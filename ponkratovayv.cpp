#include "ponkratovayv.h"

/**
 * Метод Гаусса
 */
void ponkratovayv::lab1()
{
double d ;
    //прямой ход
    for (int k = 0; k < N; k++)
    {
        d = A[k][k];
        for (int j = 0; j < N; j++)
            A[k][j] = A[k][j]/ d;
        b[k] = b[k]/d;

        for (int i = k + 1; i < N; i++)
        {
            d = A[i][k];
            for (int j = 0; j < N; j++)
            {
                A[i][j] = A[i][j]-A[k][j] * d;
            }
            b[i] =b[i]- b[k] * d;
        }
    }

    //обратный ход
    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            d = A[i][k];
            for (int j = 0; j < N; j++)
                A[i][j] =A[i][j]- A[k][j] *d;
            b[i] =b[i]- b[k] * d;
        }
    }

    for(int i=0; i<N; i++)
        x[i]=b[i];
    cout << "Hello world!" << endl;
    return 0;
}
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void ponkratovayv::lab2()
{
 double d;
    //прямой ход
    for (int k = 0; k < N; k++)
    {
        int maxx=k;
        for(int i=k+1;i<N;i++)
            if(abs(A[i][k]) > abs(A[maxx][k]))
                maxx=i;
        for(int i=0;i<N;i++)
            swap(A[k][i],A[maxx][i]);
        swap(b[k],b[maxx]);
        d = A[k][k];
        for (int j = 0; j < N; j++)
            A[k][j] = A[k][j]/d;
        b[k] =b[k]/ d;
        for (int i = k + 1; i < N; i++)
        {
            d = A[i][k];
            for (int j = 0; j < N; j++)
            {
                A[i][j] =A[i][j]- A[k][j] * d;
            }
            b[i] =b[i]- b[k] * d;
        }
    }
    //обратный ход
    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            d = A[i][k];
            for (int j = 0; j < N; j++)
                A[i][j] =A[i][j]- A[k][j] * d;
            b[i] =b[i]- b[k] * d;
        }
    }

    for(int i=0; i<N; i++)
        x[i]=b[i];
    cout << "Hello world!" << endl;
    return 0;
}
std::string ponkratovayv::get_name()
{
  return std::string("Понкратова Юлия");
}


/**
 * Метод квадратного корня (метод Холецкого)
 */
void ponkratovayv::lab3()
{

}



/**
 * Метод прогонки
 */
void ponkratovayv::lab4()
{

}



/**
 * Метод Якоби
 */
void ponkratovayv::lab5()
{

}



/**
 * Метод Зейделя
 */
void ponkratovayv::lab6()
{

}



/**
 * Один из градиентных методов
 */
void ponkratovayv::lab7()
{

}
