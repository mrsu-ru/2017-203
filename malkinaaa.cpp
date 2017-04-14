#include "malkinaaa.h"

/**
 * Метод Гаусса
 */
void malkinaaa::lab1()
{
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

}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void malkinaaa::lab3()
{

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
