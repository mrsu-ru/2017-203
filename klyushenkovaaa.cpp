#include "klyushenkovaaa.h"

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
        for(int index=0;index<N;index++)
        {
            std::swap(A[i][index],A[ind][index]);
        }

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
	int i=0;
	  int j=0;
 double** L = new  double*[N];
    for (int i=0; i<N; i++)
        L[i] = new  double[N];
	double* y = new  double[N];
	 double s=0;

	 //метод LU разложения 
	for ( i=0; i<N; i++)//начальная инициализация массива
    for ( j=0; j<N; j++)
        {
                L[i][j]=0;
        }
	for (int i = 0; i < N; i++)
        {
            for(int k=0; k<i; k++)
                s+=L[i][k]*L[i][k];
				
            L[i][i]=sqrt(A[i][i]-s);//вычисление диогонального элемента 
			
            s = 0;

        for (int j = i+1; j < N; j++)
            {
                for (int k=0; k<j-1; k++)
                    s+=L[j][k]*L[i][k];
                L[j][i] = (A[j][i]-s)/L[i][i];//mat L
                s = 0;
            };
        }

	for (int i = 0; i < N; i++)
    {
        x[i]=0;
        y[i]=0;
    }

    y[0]=b[0]/L[0][0];
    for (int i = 1; i < N; i++)
    {
        for(int j=0; j < i; j++)
			s += L[i][j]*y[j];

        y[i] = (b[i] - s)/L[i][i];//L*y=b
        s = 0;
		
    }

	x[N-1] = y[N-1]/L[N-1][N-1];
    for (int i=N-2;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
			s += L[j][i]*x[j];//L^(t)*x=y

        x[i] = (y[i] - s)/L[i][i]; //реш 
        s = 0;
		
	
    }
}



/**
 * Метод прогонки
 */
void klyushenkovaa::lab4()
{
	double* XX = new double[N];
    double* B = new double[N];

    XX[0] = A[0][1]/(-A[0][0]);
    B[0] = b[0]/A[0][0];

    for(int i=1; i<N; i++)
    {
       XX[i] = -A[i][i+1]/(A[i][i-1]*XX[i-1]+A[i][i]);//выражаем по формулам xi
       B[i] = (b[i] - A[i][i-1]*B[i-1])/(A[i][i-1]*XX[i-1]+A[i][i]);//аналогично соотв bi
    }

    for(int i=N-1; i>=0; i--) x[i] = XX[i]*x[i+1]+B[i];
}



/**
 * Метод Якоби
 */
void klyushenkovaa::lab5()
{
	 long double eps = 1.e-10;
	long double* s = new long double[N];
	long double razn;
	int i,j,k;


    for (int i = 0; i < N; i++){
	
        x[i]=0;
    }

    do {
		for ( i = 0; i < N; i++)
        {
			s[i] = b[i];
			for ( j = 0; j < N; j++)
				if (i != j) s[i] -= A[i][j] * x[j];
			s[i] /= A[i][i];
		}
        razn = fabs(x[0] - s[0]);
		for (k = 0; k < N; k++)
        {
			if (fabs(x[k] - s[k]) > razn)
				razn = fabs(x[k] - s[k]);
			x[k] = s[k];
		}
	} while (razn> eps);
}



/**
 * Метод Зейделя
 */
void klyushenkovaa::lab6()
{
	long double eps = 1.e-10;
    long double* y = new long double[N];
    long double razn = 0;
	long double var = 0;

    for (int i = 0; i < N; i++)
			x[i] = 0;
	do
	{
		for (int i = 0; i < N; i++)
			y[i] = x[i];

		for (int i = 0; i < N; i++)
		{
			var = 0;
            razn = 0;
			for (int j = 0; j < i; j++)
				var += (A[i][j] * x[j]);
			for (int j = i + 1; j < N; j++)
				var += (A[i][j] * x[j]);
			x[i] = (b[i] - var) / A[i][i];
			for (int i = 0; i < N; i++)
				razn += (x[i] - y[i])*(x[i] - y[i]);
		}
	} while (razn >= eps);
}



/**
 * Один из градиентных методов
 */
void klyushenkovaa::lab7()
{

}


/**
 * Один из градиентных методов
 */
void klyushenkovaa::lab8()
{

}
