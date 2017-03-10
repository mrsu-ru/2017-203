#include "sorokinai.h"

/**
 * Метод Гаусса
 */
void sorokinai::lab1()
{
	 for (int i = 0;  i < N; i++)
	  for (int j = 0;  j <N; j++)  {
		  fin>>A[i][j];
	  }

	    double tt = 0; //нужен для избавления от соотв xi
    for (int k=0; k<N-1; k++)
    { 
    
        for (int i=k+1; i<N; i++)//прямой ход
        {
            tt = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
            {
                A[i][j] -= tt*A[k][j];
               
            }
            b[i] -= tt*b[k];
        }
    }
    for(int i = 0; i<N; i++)
        x[i]=b[i];

    for (int i=N-1;i>=0;i--)//получаем решение
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }


}


/**
 * Метод Гаусса с выбором главного элемента
 */
void  sorokinai::lab2()
{
	 double tt;
	int maks;

    for (int k=0; k<N-1; k++)
    {
        maks = k;
        for (int i=k+1; i<N; i++)
			if(abs(A[i][k]) > abs(A[maks][k])) maks = i;//проверка 
        std::swap(A[maks], A[k]);
        std::swap(b[maks], b[k]);

        for (int i=k+1; i<N; i++)
        {

            tt = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
                A[i][j] -= tt*A[k][j];
            b[i] -= tt*b[k];
        }
    }


    for(int i = 0; i<N; i++)
    {
        x[i]=b[i];
    }

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];//решение
        x[i] /= A[i][i];
    }


}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void  sorokinai::lab3()
{

}



/**
 * Метод прогонки
 */
void  sorokinai::lab4()
{

}



/**
 * Метод Якоби
 */
void  sorokinai::lab5()
{

}



/**
 * Метод Зейделя
 */
void  sorokinai::lab6()
{

}



/**
 * Один из градиентных методов
 */
void  sorokinai::lab7()
{

}
