#include "bosonogovamv.h"

/**
 * Метод Гаусса
 */
void bosonogovamv::lab1()
{
for (int i = 0; i < N; i++)
	x[i] = b[i];
	long double m;
	for (int k = 0; k < N - 1; k++)
	  {
		for (int i = k + 1; i < N; i++)
		  {
			m = A[i][k] / A[k][k];
  			  for (int j = k; j < N; j++)
				{
				  A[i][j] = A[i][j] - m * A[k][j];
				}
					 x[i] = x[i] - m * x[k];
		   }
	   }
	for (int i = N - 1; i >= 0; i--)
	  {
		for (int j = i + 1; j < N; j++)
		  x[i] = x[i] - A[i][j] * x[j];
		  x[i] = x[i] / A[i][i];
	  }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void bosonogovamv::lab2()
{
double temp;
    //прямой ход
    for (int k = 0; k < N; k++)
    {
        int max_elem=k;
        for(int i=k+1;i<N;i++)
            if(abs(A[i][k]) > abs(A[max_elem][k]))
                max_elem=i;
        for(int i=0;i<N;i++)
            std::swap(A[k][i],A[max_elem][i]);
        std::swap(b[k],b[max_elem]);

        temp = A[k][k];

        for (int j = 0; j < N; j++)
            A[k][j] = A[k][j] / temp;
        b[k] = b[k] / temp;

        for (int i = k + 1; i < N; i++)
        {
            temp = A[i][k];
            for (int j = 0; j < N; j++)
            {
                A[i][j] = A[i][j] - A[k][j] * temp;
            }
            b[i] = b[i] - b[k] * temp;
        }
    }

    //обратный ход
    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];
            for (int j = 0; j < N; j++)
                A[i][j] = A[i][j] - A[k][j] * temp;
            b[i] = b[i] - b[k] * temp;
        }
    }

    for(int i=0; i<N; i++)
       x[i]=b[i];
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void bosonogovamv::lab3()
{
double** L = new double*[N];
	for (int i=0; i<N; i++)
	L[i] = new double[N];
	double* y = new double[N];

   for (int i=0; i<N; i++)
   {
		for (int j=0; j<N; j++)
			{
				L[i][j]=0;
			}
   }

  for(int i=0;i<N;i++)
	{
		for(int k=0;k<=i-1;k++)

			L[i][i]+=L[i][k]*L[i][k];
			L[i][i]=sqrt(A[i][i]-L[i][i]);
			for(int j=i+1;j<N;j++)
				{
					for(int k=0;k<=i-1;k++)
						L[j][i]+=L[i][k]*L[j][k];
						L[j][i]=(A[i][j]-L[j][i])/L[i][i];
				}
  }
	double summa=0;
    for(int i=0;i<N;i++)
		{
			for(int j=0;j<i;j++){
			summa+=L[i][j]*y[j];}
			y[i]=(b[i]-summa)/L[i][i];
			summa=0;
		}
	for(int i=N-1;i>=0;i--)
		{
			for(int j=i+1;j<N;j++){
				summa+=L[j][i]*x[j];}
				x[i]=(y[i]-summa)/L[i][i];
				summa=0;
		}
delete[] y;
}



/**
 * Метод прогонки
 */
void bosonogovamv::lab4()
{
    double *d, *c, *a; 
    d = new double[N];
    c = new double[N];
    a = new double[N];
    double m;

    a[0] = 0;
    d[N-1] = 0;
    for (int i = 0; i < N; ++i)
    {
        if (i - 1 >= 0 && i - 1 < N) 
            d[i] = A[i-1][i];
        c[i] = A[i][i];
        if (i + 1 >= 0 && i + 1 < N) 
            a[i] = A[i+1][i];
    }  

    for (int i = 1; i < N; i++)
    {
        m = a[i]/c[i-1];
        c[i] = c[i] - m*d[i-1];
        b[i] = b[i] - m*b[i-1];
    }

    x[N-1] = b[N-1]/c[N-1];

    for (int i = N - 2; i >= 0; i--)
        x[i]=(b[i]-d[i]*x[i+1])/c[i];  

delete[] b, c, d;
}



/**
 * Метод Якоби
 */
void bosonogovamv::lab5()
{
	long double eps = 0.00000001;
    long double* p = new long double[N];
	long double norm;
    for (int i = 0; i < N; i++)
        x[i] = 0;
    do {
		for (int i = 0; i < N; i++)
        {
			p[i] = b[i];
			for (int j = 0; j < N; j++)
				{
				    if (i != j)
                     p[i] -= A[i][j] * x[j];
				}
			p[i] /= A[i][i];
		}
        norm = fabs(x[0] - p[0]);
		for (int h = 0; h < N; h++)
        {
			if (fabs(x[h] - p[h]) > norm)
				norm = fabs(x[h] - p[h]);
			x[h] = p[h];
		}
	} while (norm > eps);
    delete[] p;
}



/**
 * Метод Зейделя
 */
void bosonogovamv::lab6()
{
double *y = new double[N];
    for (int i=0; i<N; i++)
    {
        x[i]=0; // начальное приближение
    }
    double temp=0.0;
    double eps=1e-20;
    int k=0;
    do
    {
        k++;
        temp=0.0;
        for(int i=0; i<N; i++)
            y[i]=x[i];
        for(int i=0; i<N; i++)
        {
            double s=0;
            for(int j=0; j<i; j++)
                s += A[i][j] * x[j];
            for(int j=i+1; j<N; j++)
                s += A[i][j] * y[j];
            x[i]=(b[i] - s)/A[i][i];
        }
        for(int i=0; i<N; i++)
        {
            if(std::abs(y[i]-x[i]) > temp)
                temp = std::abs(y[i]-x[i]);
        }

    } while(temp >= eps);

    delete [] y;
}



/**
 * Один из градиентных методов
 */
void bosonogovamv::lab7()
{

}