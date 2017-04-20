#include "malkinaaa.h"

/**
 * Метод Гаусса
 */
void malkinaaa::lab1()
{
<<<<<<< HEAD
	for (int i = 0; i < N; i++)
        x[i] = b[i];
	long double m;
	for (int k = 0; k < N - 1; k++)     // прямой ход
    {
        for (int i = k + 1; i < N; i++)
            {
                m = A[i][k] / A[k][k]; 
  				for (int j = k; j < N; j++)
                    {
                        A[i][j] -= m * A[k][j]; 
                    }
                 x[i] -= m * x[k]; 
             }
    }
	for (int i = N - 1; i >= 0; i--) //обратный ход
=======
for (int i = 0; i < N; i++)
        x[i] = b[i];
long double m;
for (int k = 0; k < N - 1; k++)     // прямой ход
    {
        for (int i = k + 1; i < N; i++)
            {
                m = A[i][k] / A[k][k]; // умножение k-й строки на число
  				for (int j = k; j < N; j++)
                    {
                        A[i][j] -= m * A[k][j]; // вычитание к-й строки
                    }
                 x[i] -= m * x[k];
             }
    }
for (int i = N - 1; i >= 0; i--) //обратный ход
>>>>>>> db22a158aa15833753105e821fd86ad1a9cf7580
    {
        for (int j = i + 1; j < N; j++)
                x[i] -= A[i][j]*x[j];
        x[i] /= A[i][i];
    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void malkinaaa::lab2()
{
<<<<<<< HEAD
	long double m = 0;
	int index;
	for (int k = 0; k < N-1; k++)
			{
				index = k;
				for (int i = k + 1; i < N; i++)
				{
					if(abs(A[i][k]) > abs(A[index][k]))
						{
							index = i;
						}
				}
				std::swap(A[index], A[k]);
				std::swap(b[index], b[k]);
				for (int i = k + 1; i < N; i++)
				 {
 					m = A[i][k] / A[k][k];
  					for (int j = k; j < N; j++)
					{
  						A[i][j] -= m * A[k][j];
  					}
					 b[i] -= m * b[k];
				 }
			}
			for (int i = 0; i < N; i++)
				x[i] = b[i];
			for (int i = N - 1; i >= 0; i--)
			{
				for (int j = i + 1; j < N; j++)
				{
					 x[i] -= A[i][j] * x[j];
				}
				x[i] /= A[i][i];
			}        
}

=======

}
>>>>>>> db22a158aa15833753105e821fd86ad1a9cf7580



/**
 * Метод квадратного корня (метод Холецкого)
 */
void malkinaaa::lab3()
{
<<<<<<< HEAD
	long double* P = new long double[N];
	long double* Q = new long double[N];
	for (int i = 0; i<N; i++)
		{
			P[i] = 0;
			Q[i] = 0;
		}
	P[0] = A[0][1]/(-A[0][0]);
	Q[0] = b[0]/A[0][0];
	for(int i = 1; i<N; i++)
		{
			P[i] = A[i][i+1]/(-A[i][i] - A[i][i-1]*P[i-1]);
			Q[i] = (-b[i] + A[i][i-1]*Q[i-1])/(-A[i][i]-A[i][i-1]*P[i-1]);
		}
	x[N - 1] = Q[N - 1];
	for(int i = N - 2; i >= 0; i--)
		x[i] = P[i]*x[i+1] + Q[i];
	delete[] P;
	delete[] Q;
=======

>>>>>>> db22a158aa15833753105e821fd86ad1a9cf7580
}



/**
 * Метод прогонки
 */
void malkinaaa::lab4()
{

}



/**
 * Метод Якоби
 */
void malkinaaa::lab5()
{

}



/**
 * Метод Зейделя
 */
void malkinaaa::lab6()
{

}



/**
 * Один из градиентных методов
 */
void malkinaaa::lab7()
{

}
