#include "sorokinai.h"

/**
 * Метод Гаусса
 */
void sorokinai::lab1()
{

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
				
            L[i][i]=sqrt(A[i][i]-s);//вычесление диогонального элемента 
			
            s = 0;

        for (int j = i+1; j < N; j++)
            {
                for (int k=0; k<j-1; k++)
                    s+=L[j][k]*L[i][k];
                L[j][i] = (A[j][i]-s)/L[i][i];//matr L
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
		//cout<<y[i]<<endl;
    }

	x[N-1] = y[N-1]/L[N-1][N-1];
    for (int i=N-2;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
			s += L[j][i]*x[j];//L^(t)*x=y

        x[i] = (y[i] - s)/L[i][i];//solution 
        s = 0;
		//cout<<x[i];
	
    }
}



/**
 * Метод прогонки
 */
void  sorokinai::lab4()
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

/**
 * Один из градиентных методов
 */
void  sorokinai::lab8()
{

}
