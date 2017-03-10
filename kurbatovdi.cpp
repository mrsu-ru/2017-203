
#include "kurbatovdi.h"

/**
 * Метод Гаусса
 */
void kurbatovdi::lab1()
{
	double m = 0;
    for (int k = 0; k < N-1; k++)
    {
        for (int i = k+1; i < N; i++)
        {
            m  = A[i][k] / A[k][k];
            for (int j = k; j < N; j++)
            {
                A[i][j] -= m * A[k][j];
            }
            b[i] -= m * b[k];
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
void kurbatovdi::lab2()
{
	for (int i = 0; i < N; i++)
        x[i] = b[i];
     double m;
     int ind;
     for (int k = 0; k < N-1; k++)
        {
            ind = k;
            for (int i=k+1; i<N; i++)
                if(abs(A[i][k]) > abs(A[ind][k])) ind = i;
            std::swap(A[ind], A[k]);
            std::swap(b[ind], b[k]);
             for (int i = k+1; i < N; i++)
             {
 				m = A[i][k] / A[k][k];
  				for (int j = k; j < N; j++)
                {
  					A[i][j]-=m * A[k][j];
  				}
                 x[i]-=m * x[k];

             }
        }

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i]/=A[i][i];
    }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void kurbatovdi::lab3()
{

}



/**
 * Метод прогонки
 */
void kurbatovdi::lab4()
{

}



/**
 * Метод Якоби
 */
void kurbatovdi::lab5()
{

}



/**
 * Метод Зейделя
 */
void kurbatovdi::lab6()
{

}



/**
 * Один из градиентных методов
 */
void kurbatovdi::lab7()
{

}

