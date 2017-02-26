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

}



/**
 * Метод прогонки
 */
void kuzminnal::lab4()
{

}



/**
 * Метод Якоби
 */
void kuzminnal::lab5()
{

}



/**
 * Метод Зейделя
 */
void kuzminnal::lab6()
{

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
