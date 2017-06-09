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
            std::swap(A[i][indexswap],A[indexm][indexswap]);
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
double l[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            l[i][j]=0;
        }
    }
    double s=0;///сумма квадратов
    double y[N];

    for(int i=0;i<N;i++)
    {
        for(int k=0;k<i;k++)
        {
            s=s+l[i][k]*l[i][k];
        }
        l[i][i]=sqrt(A[i][i]-s);
        s=0;
        for(int j=i+1;j<N;j++)
        {
            for(int k=0;k<j-1;k++)
            {
                s=s+l[j][k]*l[i][k];
            }
            l[j][i]=(A[j][i]-s)/l[i][i];
            s=0;
        }
        x[i]=0;
        y[i]=0;
    }
    y[0]=b[0]/l[0][0];
    double sum=0;///для получения х и у
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            sum=sum+l[i][j]*y[j];
        }
        y[i]=(b[i]-sum)/l[i][i];
        sum=0;
    }
    x[N-1]=y[N-1]/l[N-1][N-1];
    for(int i=N-2;i>=0;i--)
    {
        for(int j=i+1;j<N;j++)
        {
            sum=sum+l[j][i]*x[j];
        }
        x[i]=(y[i]-sum)/l[i][i];
        sum=0;
    }
}



/**
 * Метод прогонки
 */
void golovenkomv::lab4()
{
double d[N];
    for(int i=0;i<N;i++)
        d[i]=A[i][i];
    double e[N-1],c[N-1];
    e[0]=A[0][1];
    c[N-1]=A[N-1][N-2];
    for(int i=1;i<N;i++)
    {
        e[i]=A[i][i+1];
        c[i-1]=A[i][i-1];
    }
    double al[N-1],bt[N];
    al[0]=(-1)*e[0]/d[0];
    bt[0]=b[0]/d[0];
    for(int i=1;i<N-1;i++)
    {
        al[i]=-e[i]/(d[i]+e[i-1]*al[i-1]);
        bt[i]=(b[i]-c[i-1]*bt[i-1])/(d[i]+c[i-1]*al[i-1]);
    }
    bt[N-1] = (b[N-1] - A[N-1][N-2]*bt[N-2])/(A[N-1][N-1] + A[N-1][N-2]*al[N-2]);

    x[N-1]=bt[N-1];
    for(int i=N-2;i>=0;i--)
    {
        x[i]=al[i]*x[i+1]+bt[i];
    }
}



/**
 * Метод Якоби
 */
void golovenkomv::lab5()
{
double eps = 1.e-10;
double nx[N];
double razn = 0;
int flag=1;
	for(int i = 0; i < N; i++)
	{
		x[i] = 0;
	}
	do
	{
		for(int i = 0; i < N; i++)
		{
			nx[i] = b[i];
			for(int j = 0; j < N; j++)
			{
				if(i != j)
				{
					nx[i] = nx[i] - A[i][j] * x[j];
				}
			}
			nx[i] = nx[i]/(A[i][i]);
		}
		razn = fabs( nx[0] - x[0] );
		for(int i = 0; i < N; i++)
		{
			if(fabs(nx[i] - x[i]) > razn)
			{
				razn = fabs(nx[i] - x[i]);
			}
			x[i] = nx[i];
		}
		if(razn < eps)
            flag=0;
	} while(flag==1);
}



/**
 * Метод Зейделя
 */
void golovenkomv::lab6()
{
double eps = 1.e-10;
double px[N];
double sum = 0;
int flag = 1;
    for(int i = 0; i < N; i++)
    {
        x[i] = 0;
    }
    do
    {
        for(int i = 0; i < N; i++)
        {
            px[i] = x[i];
        }
        for(int i = 0; i < N; i++)
        {
            sum = 0;
            for(int j = 0; j < i; j++)
            {
                sum =sum + A[i][j] * x[j];
            }
            for(int j = i+1; j < N; j++)
                sum =sum + A[i][j] * px[j];
            x[i] = (b[i] - sum) / A[i][i];
        }
        flag = 1;
        for(int i = 0; i < N; i++)
        {
            if(fabs(x[i] - px[i]) < eps)
            {
                flag = 0;
                break;
            }
        }
    } while(flag == 1);
}



/**
 * Один из градиентных методов
 */
void golovenkomv::lab7()
{

}


/**
 * Один из градиентных методов
 */
void golovenkomv::lab8()
{

}
