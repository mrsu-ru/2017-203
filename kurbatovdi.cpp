
#include "kurbatovdi.h"

/**
 * ����� ������
 */
void kurbatovdi::lab1()
{
	double m = 0;
    for (int k = 0; k < N-1; k++)
    {
        for (int i = k+1; i < N; i++)
        {
            m  = A[i][k] / A[k][k];
            for (int j = k; j < N; j++)
            {
                A[i][j] -= m * A[k][j];
            }
            b[i] -= m * b[k];
        }
    }
    for(int i = 0; i < N; i++)
    {
        x[i] = b[i];
    }
    for(int i = N-1; i >= 0; i--)
    {
        for(int j = i + 1; j < N; j++)
        {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

}


/**
 * ����� ������ � ������� �������� ��������
 */
void kurbatovdi::lab2()
{
	for (int i = 0; i < N; i++)
        x[i] = b[i];
     double m;
     int ind;
     for (int k = 0; k < N-1; k++)
        {
            ind = k;
            for (int i=k+1; i<N; i++)
                if(abs(A[i][k]) > abs(A[ind][k])) ind = i;
            std::swap(A[ind], A[k]);
            std::swap(b[ind], b[k]);
             for (int i = k+1; i < N; i++)
             {
 				m = A[i][k] / A[k][k];
  				for (int j = k; j < N; j++)
                {
  					A[i][j]-=m * A[k][j];
  				}
                 x[i]-=m * x[k];

             }
        }

    for (int i=N-1;i>=0;i--)
    {
        for (int j=i+1;j<N;j++)
                x[i]-=A[i][j]*x[j];
        x[i]/=A[i][i];
    }
}



/**
 * ����� ����������� ����� (����� ���������)
 */
void kurbatovdi::lab3()
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
 * ����� ��������
 */
void kurbatovdi::lab4()
{
	long double* P = new long double[N];
    long double* Q = new long double[N];
    for (int i=0; i<N; i++)
    {
        P[i]=0;
        Q[i]=0;
    }

    P[0]=A[0][1]/(-A[0][0]);
    Q[0]=b[0]/A[0][0];

    for(int i=1; i<N; i++)
    {
        P[i] = A[i][i+1]/(-A[i][i]-A[i][i-1]*P[i-1]);
        Q[i] = (-b[i] + A[i][i-1]*Q[i-1])/(-A[i][i]-A[i][i-1]*P[i-1]);
    }

    x[N-1] = Q[N-1];
    for(int i=N-2; i>=0; i--)
        x[i] = P[i]*x[i+1]+Q[i];

    delete[] P;
    delete[] Q;

}



/**
 * ����� �����
 */
void kurbatovdi::lab5()
{

}



/**
 * ����� �������
 */
void kurbatovdi::lab6()
{

}



/**
 * ���� �� ����������� �������
 */
void kurbatovdi::lab7()
{

}




/**
 * ���� �� ����������� �������
 */
void kurbatovdi::lab8()
{

}
