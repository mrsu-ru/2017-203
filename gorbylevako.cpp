#include "gorbylevako.h"

/**
 * Метод Гаусса
 */
void gorbylevako::lab1()
{
    double p;
    for(int k=0; k<N; k++)
        for(int i=k+1; i<N; i++)
        {
            p = A[i][k]/A[k][k];
            for(int j=0; j<N; j++)
                A[i][j] -= A[k][j]*p;
            b[i] -= b[k]*p;
        }

    for(int i = 0; i<N; i++)
    {
        x[i]=b[i];
    }

    for (int i=N-1; i>=0; i--)
    {
        for (int j=i+1;j<N;j++)
            x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void gorbylevako::lab2()
{
    double p;
	int maxn;

    for (int k=0; k<N-1; k++)
    {
        maxn = k;
        for (int i=k+1; i<N; i++)
			if(abs(A[i][k]) > abs(A[maxn][k])) maxn = i; //Выбор главного элемента
        std::swap(A[maxn], A[k]); //Меняем строки местами
        std::swap(b[maxn], b[k]);

        for (int i=k+1; i<N; i++)
        {
            p = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
                A[i][j] -= p*A[k][j];
            b[i] -= p*b[k];
        }
    }

    for(int i = 0; i<N; i++)
    {
        x[i]=b[i];
    }

    for (int i=N-1; i>=0; i--)
    {
        for (int j=i+1;j<N;j++)
            x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void gorbylevako::lab3()
{

}



/**
 * Метод прогонки
 */
void gorbylevako::lab4()
{

}



/**
 * Метод Якоби
 */
void gorbylevako::lab5()
{

}



/**
 * Метод Зейделя
 */
void gorbylevako::lab6()
{

}



/**
 * Один из градиентных методов
 */
void gorbylevako::lab7()
{

}

/**
 * Один из градиентных методов
 */
void gorbylevako::lab8()
{

}
