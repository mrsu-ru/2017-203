#include "polischukoa.h"
#include <cmath>

/**
 * Метод Гаусса
 */
void polischukoa::lab1()
{
	double Q = 0;	

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            Q = A[j][i] / A[i][i];

            for (int k = i; k < N; k++)
            {
                A[j][k] -= Q * A[i][k];
            }
            b[j] -= Q * b[i];
        }
    }
	  
    for(int i = 0; i < N; i++)
	{
        x[i] = b[i];
	}
	
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < N; j++)
		{
			x[i] -= A[i][j] * x[j];
		}

        x[i] /= A[i][i];
	}

}


/**
 * Метод Гаусса с выбором главного элемента
 */
void polischukoa::lab2()
{
	double Q = 0;
	int max;

    for (int i = 0; i < N - 1; i++)
    {
		max = i;

		for (int j = i + 1; j < N; j++)
		{
			if(abs(A[j][i]) > abs(A[max][i]))
			{
				max = j;
			}
		}
        
		swap(A[max], A[i]);
        swap(B[max], B[i]);


        for (int j = i + 1; j < N; j++)
        {
            Q = A[j][i] / A[i][i];
            for (int k = i; k < n; k++)
            {
                A[j][k] -= Q * A[i][k];
            }
            b[j] -= Q * b[i];
        }
    }
	  
    for(int i = 0; i < N; i++)
	{
        x[i] = b[i];
	}
	
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < N; j++)
		{
			x[i] -= A[i][j] * x[j];
		}

        x[i] /= A[i][i];
	}

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void polischukoa::lab3()
{

}



/**
 * Метод прогонки
 */
void polischukoa::lab4()
{
	double* P = new double[N];
    double* Q = new double[N];

    for (int i = 0; i < N; i++)
    {
        P[i] = 0;
        Q[i] = 0;
    }

    P[0] = -A[0][1] / A[0][0];
    Q[0] = b[0] / A[0][0];

    for(int i = 1; i < N; i++)
    {
        P[i] = A[i][i + 1] / (-A[i][i - 1] * P[i - 1] - A[i][i]);
        Q[i] = (-b[i] + A[i][i - 1] * Q[i - 1]) / (-A[i][i - 1] * P[i - 1] - A[i][i]);
    }

    x[N - 1] = Q[N - 1];

    for(int i = N - 2; i >= 0; i--)
	{
        x[i] = P[i] * x[i + 1] + Q[i];
	}
    
	delete[] P;
	delete[] Q;

}



/**
 * Метод Якоби
 */
void polischukoa::lab5()
{
	double eps = 1E-8;
	double *P = new double[N];
	double norm;

    do 
	{
        for (int i = 0; i < N; i++)
        {
            P[i] = b[i];

            for (int j = 0; j < N; j++)
			{
                if (i != j)
				{
					P[i] -= A[i][j] * x[j];
				}
			}

            P[i] /= A[i][i];
        }

        norm = fabs(x[0] - P[0]);

        for (int h = 0; h < N; h++)
        {
            if (fabs(x[h] - P[h]) > norm)
			{
                norm = fabs(x[h] - P[h]);
			}

            x[h] = P[h];
        }
    }
	while (norm > eps);
	
    delete[] P;
}



/**
 * Метод Зейделя
 */
void polischukoa::lab6()
{
	double eps = 1E-8;
    double *y = new double[N];
    double norm = 0;
    double var = 0;	
	
    do
    {
        for (int i = 0; i < N; i++)
		{
            y[i] = x[i];
		}

        for (int i = 0; i < N; i++)
        {
            var = 0;
            norm = 0;
            for (int j = 0; j < i; j++)
			{
                var += (A[i][j] * x[j]);
			}

            for (int j = i + 1; j < N; j++)
			{
                var += (A[i][j] * x[j]);
			}

            x[i] = (b[i] - var) / A[i][i];

            for (int i = 0; i < N; i++)
			{
                norm += (x[i] - y[i]) * (x[i] - y[i]);
			}
        }
    } 
	while (sqrt(norm) >= eps);

    delete[] y;	
	
}



/**
 * Один из градиентных методов
 */
void polischukoa::lab7()
{

}
