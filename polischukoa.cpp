#include "polischukoa.h"
#include <cmath>

/**
 * Метод Гаусса
 */
void polischukoa::lab1()
{
	double С = 0;
	double *X = new double[n];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            С = A[j][i] / A[i][i];

            for (int k = i; k < n; k++)
            {
                A[j][k] -= С * A[i][k];
            }
            B[j] -= С * B[i];
        }
    }
	  
    for(int i = 0; i < n; i++)
	{
        X[i] = B[i];
	}
	
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
		{
			X[i] -= A[i][j] * X[j];
		}

        X[i] /= A[i][i];
	}

	for(int i = 0; i < n; i++)
	{
        cout << X[i] << "	";
	}

}


/**
 * Метод Гаусса с выбором главного элемента
 */
void polischukoa::lab2()
{
	double С = 0;
	double *X = new double[n];
	int max;

    for (int i = 0; i < n - 1; i++)
    {
		max = i;

		for (int j = i + 1; j < n; j++)
		{
			if(abs(A[j][i]) > abs(A[max][i]))
			{
				max = j;
			}
		}
        
		swap(A[max], A[i]);
        swap(B[max], B[i]);


        for (int j = i + 1; j < n; j++)
        {
            С = A[j][i] / A[i][i];
            for (int k = i; k < n; k++)
            {
                A[j][k] -= С * A[i][k];
            }
            B[j] -= С * B[i];
        }
    }
	  
    for(int i = 0; i < n; i++)
	{
        X[i] = B[i];
	}
	
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
		{
			X[i] -= A[i][j] * X[j];
		}

        X[i] /= A[i][i];
	}

	for(int i = 0; i < n; i++)
	{
        cout << X[i] << "	";
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
	double* X = new double[N];
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

    X[N - 1] = Q[N - 1];

    for(int i = N - 2; i >= 0; i--)
	{
        X[i] = P[i] * X[i + 1] + Q[i];
	}
    
	for(int i = 0; i < N; i++)
	{
        cout << X[i] << "	";
	}	

	delete[] P;
	delete[] Q;
	delete[] X;
}



/**
 * Метод Якоби
 */
void polischukoa::lab5()
{
	double eps = 0.0001;
	double *P = new double[n];
	double norm;
	double *X = new double[n];

    for (int i = 0; i < n; i++)
	{
        X[i] = 0;
	}

    do 
	{
        for (int i = 0; i < n; i++)
        {
            P[i] = b[i];

            for (int j = 0; j < n; j++)
			{
                if (i != j)
				{
					P[i] -= A[i][j] * X[j];
				}
			}

            P[i] /= A[i][i];
        }

        norm = fabs(X[0] - P[0]);

        for (int h = 0; h < n; h++)
        {
            if (fabs(X[h] - P[h]) > norm)
			{
                norm = fabs(X[h] - P[h]);
			}

            X[h] = P[h];
        }
    }
	while (norm > eps);

	for(int i = 0; i < n; i++)
	{
        cout << X[i] << "	";
	}	

    delete[] P;
	delete[] X;
}



/**
 * Метод Зейделя
 */
void polischukoa::lab6()
{
	double eps = 0.0001;
    double *y = new double[n];
    double norm = 0;
    double var = 0;	
	double *X = new double[n];

    for (int i = 0; i < n; i++)
	{
		X[i] = 0;
	}

    do
    {
        for (int i = 0; i < n; i++)
		{
            y[i] = X[i];
		}

        for (int i = 0; i < n; i++)
        {
            var = 0;
            norm = 0;
            for (int j = 0; j < i; j++)
			{
                var += (A[i][j] * X[j]);
			}

            for (int j = i + 1; j < n; j++)
			{
                var += (A[i][j] * X[j]);
			}

            X[i] = (b[i] - var) / A[i][i];

            for (int i = 0; i < n; i++)
			{
                norm += (X[i] - y[i]) * (X[i] - y[i]);
			}
        }
    } 
	while (sqrt(norm) >= eps);

	for(int i = 0; i < n; i++)
	{
        cout << X[i] << "	";
	}	

    delete[] y;	
	delete[] X;
}



/**
 * Один из градиентных методов
 */
void polischukoa::lab7()
{

}
