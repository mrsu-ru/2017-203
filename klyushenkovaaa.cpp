#include "klyushenkovaa.h"

/**
 * Метод Гаусса
 */
void klyushenkovaa::lab1()
{
double kof;
for(int i=0;i<N;i++)
        {
            kof=A[i][i];
            for(int l=i;l<N;l++)
            {
                A[i][l]=A[i][l]/kof;
            }
            b[i]=b[i]/kof;
            for(int j=i+1;j<N;j++)
            {
                kof=A[j][i];
                for(int k=i;k<N;k++)
                {
                    A[j][k]=A[j][k]-A[i][k]*kof;
                }
                b[j]=b[j]-b[i]*kof;
            }
        }
    x[n-1]=b[n-1];
    x[n-2]=b[n-2] - A[n-2][n-1]*x[n-1];
    for(int i=n-3;i>=0;i--)
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
void klyushenkovaa::lab2()
{
double kof;
    for(int i=0;i<N;i++)
    {


        int ind=i;
        double m_el=abs(A[i][i]);
        for(int q=q+1;q<N;q++)
        {

            if( abs(A[q][i])>m_el )
            {
                m_el=abs(A[q][i]);
                ind=q;
            }
        }
        for(int indexswap=0;index<N;index++)
        {
            swap(A[i][index],A[ind][index]);
        }

            kof=A[i][i];
            for(int l=i;l<N;l++)
            {
                A[i][l]=N[i][l]/kof;
            }
            b[i]=b[i]/kof;
            for(int j=i+1;j<N;j++)
            {
                kof=A[j][i];
                for(int k=i;k<N;k++)
                {
                    A[j][k]=A[j][k]-A[i][k]*kof;
                }
                b[j]=b[j]-b[i]*kof;
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
void klyushenkovaa::lab3()
{

}



/**
 * Метод прогонки
 */
void klyushenkovaa::lab4()
{

}



/**
 * Метод Якоби
 */
void klyushenkovaa::lab5()
{

}



/**
 * Метод Зейделя
 */
void klyushenkovaa::lab6()
{

}



/**
 * Один из градиентных методов
 */
void klyushenkovaa::lab7()
{

}
