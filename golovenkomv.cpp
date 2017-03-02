#include "golovenkomv.h"

/**
 * Метод Гаусса
 */
void golovenkomv::lab1()
{
    double koif;
    for(int i=0;i<n;i++)
        {
            koif=a[i][i];
            for(int l=i;l<n;l++)
            {
                a[i][l]=a[i][l]/koif;
            }
            b[i]=b[i]/koif;
            for(int j=i+1;j<n;j++)
            {
                koif=a[j][i];
                for(int k=i;k<n;k++)
                {
                    a[j][k]=a[j][k]-a[i][k]*koif;
                }
                b[j]=b[j]-b[i]*koif;
            }
        }
    x[n-1]=b[n-1];
    x[n-2]=b[n-2] - a[n-2][n-1]*x[n-1];
    for(int i=n-3;i>=0;i--)
    {
        double sum=0;
        for(int j=i+1;j<n;j++)
        {
            sum+=a[i][j]*x[i];
        }
        x[i]=(b[i]-sum)/a[i][i];
    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void golovenkomv::lab2()
{
double koif;
    for(int i=0;i<n;i++)
    {


        int indexm=i;
        double maxel=abs(a[i][i]);
        for(int mi=mi+1;mi<n;mi++)
        {

            if( abs(a[mi][i])>maxel )
            {
                maxel=abs(a[mi][i]);
                indexm=mi;
            }
        }
        for(int indexswap=0;indexswap<n;indexswap++)
        {
            swap(a[i][indexswap],a[indexm][indexswap]);
        }

            koif=a[i][i];
            for(int l=i;l<n;l++)
            {
                a[i][l]=a[i][l]/koif;
            }
            b[i]=b[i]/koif;
            for(int j=i+1;j<n;j++)
            {
                koif=a[j][i];
                for(int k=i;k<n;k++)
                {
                    a[j][k]=a[j][k]-a[i][k]*koif;
                }
                b[j]=b[j]-b[i]*koif;
            }
        }
    x[n-1]=b[n-1];
    x[n-2]=b[n-2] - a[n-2][n-1]*x[n-1];
    for(int i=n-3;i>=0;i--)
    {
        double sum=0;
        for(int j=i+1;j<n;j++)
        {
            sum+=a[i][j]*x[i];
        }
        x[i]=(b[i]-sum)/a[i][i];
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
