#include "kuzminnal.h"

/**
 * Метод Гаусса
 */
void kuzminnal::lab1()
{
    double tmp = 0;
    for(int k = 0; k < N-1; k++)
    {
        for (int i = k+1; i < N; i++)
        {
            tmp = A[i][k] / A[k][k];
            for (int j = k; j < N; j++)
            {
                A[i][j] -= tmp * A[k][j];
            }
            b[i] -= tmp * b[k];
        }
    }
    for(int i = 0; i < N; i++)
    {
        x[i] = b[i];
    }
    for(int i = N-1; i >= 0; i--)
    {
        for(int j = i + 1; j < N; j++)
        {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void kuzminnal::lab2()
{
    double tmp;
    int maxIndex = -1;
    for(int k = 0; k < N - 1; k++)
    {
        maxIndex = k;
        for(int i = k + 1; i < N; i++)
        {
            if(abs(A[i][k]) > abs(A[maxIndex][k]))
            {
                maxIndex = i;
            }
        }
        if(maxIndex != -1)
        {
            for(int p = 0; p < N; p++)
            {
                std::swap(A[k][p], A[maxIndex][p]);
                std::swap(b[k], b[maxIndex]);
            }
        }
        for(int i = k + 1; i < N; i++)
        {
            tmp = A[i][k] / A[k][k];
            for(int j = k; j < N; j++)
            {
                A[i][j] -= tmp * A[k][j];
            }
            b[i] -= tmp * b[k];
        }
        for(int i = 0; i < N; i++)
        {
            x[i] = b[i];
        }
        for(int i = N - 1; i >= 0; i--)
        {
            for(int j = i + 1; j < N; j++)
            {
                x[i] -= A[i][j] * x[j];
            }
            x[i] /= A[i][i];
        }
    }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void kuzminnal::lab3()
{
	double** L = new double*[N];
    for(int i = 0; i < N; i++)
    {
        L[i] = new double[N];
    }
    double sum = 0;
    double* y = new double[N];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            L[i][j] = 0;
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int k = 0; k < i; k++)
        {
            sum = sum + L[i][k] * L[i][k];
        }
        L[i][i] = sqrt(A[i][i] - sum);
        sum = 0;

        for(int j = i + 1; j < N; j++)
        {
            for(int k = 0; k < j-1; k++)
            {
                sum = sum + L[j][k] * L[i][k];
            }
            L[j][i] = (A[j][i] - sum) / L[i][i];
            sum = 0;
        }
        x[i] = 0;
        y[i] = 0;
    }

    y[0] = b[0] / L[0][0];
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            sum = sum + L[i][j]*y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
        sum = 0;
    }
    x[N-1] = y[N-1] / L[N-1][N-1];
    for(int i = N - 2; i >= 0; i--)
    {
        for(int j = i + 1; j < N; j++)
        {
            sum = sum + L[j][i] * x[j];
        }
        x[i] = (y[i] - sum) / L[i][i];
        sum = 0;
    }
    delete[] y;
    for(int i = 0; i < N; i++)
        delete[] L[i];
    delete[] L;
}



/**
 * Метод прогонки
 */
void kuzminnal::lab4()
{
	double* P = new double[N];
    double* Q = new double[N];
    for(int i = 0; i < N; i++)
    {
        P[i] = 0;
        Q[i] = 0;
    }
    P[0] = A[0][1] / (-A[0][0]);
    Q[0] = b[0] / A[0][0];
    for(int i = 0; i < N; i++)
    {
        P[i] = A[i][i+1] / (-A[i][i] - A[i][i-1] * P[i-1]);
        Q[i] = (-b[i] + A[i][i-1]*Q[i-1]) / (-A[i][i]-A[i][i-1] * P[i-1]);
    }
    x[N-1] = Q[N-1];
    for(int i = N - 2; i >= 0; i--)
    {
        x[i] = P[i] * x[i+1] + Q[i];
    }

    delete[] P;
    delete[] Q;
}



/**
 * Метод Якоби
 */
void kuzminnal::lab5()
{
	double eps = 0.00001;
	double* next = new double[N];
	double norm = 0;
	for(int i = 0; i < N; i++)
	{
		x[i] = 0;
	}
	do
	{
		for(int i = 0; i < N; i++)
		{
			next[i] = b[i];
			for(int j = 0; j < N; j++)
			{
				if(i != j)
				{
					next[i] -= A[i][j] * x[j];
				}
			}
			next[i] /= A[i][i];
		}
		norm = fabs(x[0] - next[0]);
		for(int i = 0; i < N; i++)
		{
			if(fabs(x[i] - next[i]) > norm)
			{
				norm = fabs(x[i] - next[i]);
			}
			x[i] = next[i];
		}
	} while(norm > eps);
	delete[] next;
}



/**
 * Метод Зейделя
 */
void kuzminnal::lab6()
{
	double eps = 0.00001;
    double* prev = new double[N];
    double sum = 0;
    double norm = 0;
    for(int i = 0; i < N; i++)
    {
        x[i] = 0;
    }
    do
    {
        for(int i = 0; i < N; i++)
        {
            prev[i] = x[i];
        }
        for(int i = 0; i < N; i++)
        {
            sum = 0;
            for(int j = 0; j < i; j++)
            {
                sum += A[i][j] * x[j];
            }
            for(int j = i+1; j < N; j++)
                sum += A[i][j] * prev[j];
            x[i] = (b[i] - sum) / A[i][i];
        }
		norm = fabs(x[0] - prev[0]);
        for(int i = 0; i < N; i++)
		{
			if(fabs(x[i] - prev[i]) > norm)
			{
				norm = fabs(x[i] - prev[i]);
			}
		}
    } while(norm > eps);
    
    delete[] prev;
}



/**
 * Один из градиентных методов
 */
void kuzminnal::lab7()
{

}

void kuzminnal::lab8()
{

}

std::string kuzminnal::get_name()
{
  return std::string("Кузьмин Никита Александрович");
}
