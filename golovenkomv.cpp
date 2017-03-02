#include "golovenkomv.h"

/**
 * Метод Гаусса
 */
void golovenkomv::lab1()
{
    double koif;
    for(int i=0;i<N;i++)
        {
            koif=A[i][i];
            for(int l=i;l<N;l++)
            {
                A[i][l]=A[i][l]/koif;
            }
            b[i]=b[i]/koif;
            for(int j=i+1;j<N;j++)
            {
                koif=A[j][i];
                for(int k=i;k<N;k++)
                {
                    A[j][k]=A[j][k]-A[i][k]*koif;
                }
                b[j]=b[j]-b[i]*koif;
            }
        }
    x[N-1]=b[N-1];
    x[N-2]=b[N-2] - A[N-2][N-1]*x[N-1];
    for(int i=N-3;i>=0;i--)
    {
        double sum=0;
        for(int j=i+1;j<N;j++)
        {
            sum+=A[i][j]*x[i];
        }
        x[i]=(b[i]-sum)/A[i][i];
    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void golovenkomv::lab2()
{
double koif;
    for(int i=0;i<N;i++)
    {


        int indexm=i;
        double maxel=abs(A[i][i]);
        for(int mi=mi+1;mi<N;mi++)
        {

            if( abs(A[mi][i])>maxel )
            {
                maxel=abs(A[mi][i]);
                indexm=mi;
            }
        }
        for(int indexswap=0;indexswap<N;indexswap++)
        {
            swap(A[i][indexswap],A[indexm][indexswap]);
        }

            koif=A[i][i];
            for(int l=i;l<N;l++)
            {
                A[i][l]=A[i][l]/koif;
            }
            b[i]=b[i]/koif;
            for(int j=i+1;j<N;j++)
            {
                koif=A[j][i];
                for(int k=i;k<N;k++)
                {
                    A[j][k]=A[j][k]-A[i][k]*koif;
                }
                b[j]=b[j]-b[i]*koif;
            }
        }
    x[N-1]=b[N-1];
    x[N-2]=b[N-2] - A[N-2][N-1]*x[N-1];
    for(int i=N-3;i>=0;i--)
    {
        double sum=0;
        for(int j=i+1;j<N;j++)
        {
            sum+=A[i][j]*x[i];
        }
        x[i]=(b[i]-sum)/A[i][i];
    }


}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void golovenkomv::lab3()
{

}



/**
 * Метод прогонки
 */
void golovenkomv::lab4()
{

}



/**
 * Метод Якоби
 */
void golovenkomv::lab5()
{

}



/**
 * Метод Зейделя
 */
void golovenkomv::lab6()
{

}



/**
 * Один из градиентных методов
 */
void golovenkomv::lab7()
{

}
