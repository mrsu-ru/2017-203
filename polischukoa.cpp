#include "polischukoa.h"

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

}



/**
 * Метод Якоби
 */
void polischukoa::lab5()
{

}



/**
 * Метод Зейделя
 */
void polischukoa::lab6()
{

}



/**
 * Один из градиентных методов
 */
void polischukoa::lab7()
{

}
