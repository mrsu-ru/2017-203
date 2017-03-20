#include "geroevvn.h"

/**
 * Метод Гаусса
 */
void geroevvn::lab1()
{
    double temp;

      for(int i=0;i<N-1;i++)
        {
         for(int j=i+1;j<N;j++)
          {
             temp = A[j][i]/A[i][i];

             b[j] -= temp*b[i];

              for(int q=i;q<N;q++)
                {
                  A[j][q] -= temp*A[i][q];
                }
           }
        }

        for(int i=N-1;i>=0;i--)
         {
            b[i]/=A[i][i];

             for(int j=i-1;j>=0;j--)
              {
                b[j] -= b[i]*A[j][i];
              }
         }
    for(int i=0;i<N;i++)
     x[i] = b[i];

}


/**
 * Метод Гаусса с выбором главного элемента
 */
void geroevvn::lab2()
{
    double temp;
    int maxInd;

      for(int i=0;i<N-1;i++)
        {
         maxInd = i;

          for(int k=i+1;k<N;k++)
           {
            if(abs(A[k][i]) > abs(A[maxInd][i]))
              {
                maxInd = k;
              }
           }

           if (maxInd != i)
            {
              for(int k=i;k<N;k++)
               {
                std::swap(A[i][k],A[maxInd][k]);
               }
               std::swap(b[i],b[maxInd]);
            }

         for(int j=i+1;j<N;j++)
          {
             temp = A[j][i]/A[i][i];

             b[j] -= temp*b[i];

              for(int q=i;q<N;q++)
                {
                  A[j][q] -= temp*A[i][q];
                }
           }
        }

        for(int i=N-1;i>=0;i--)
         {
            b[i]/=A[i][i];

             for(int j=i-1;j>=0;j--)
              {
                b[j] -= b[i]*A[j][i];
              }

         }
    for(int i=0;i<N;i++)
         x[i] = b[i];

}

int geroevvn::sign(double x)
 {
   if(x>=0)
     return 1;
   else
     return -1;
 }

/**
 * Метод квадратного корня (метод Холецкого)
 */
void geroevvn::lab3()
{
 double** S = new double*[N];
     for(int i=0;i<N;i++)
        S[i] = new double[N];

 int* D = new int[N];

 double sum;
   D[0] = sign(A[0][0]);
   S[0][0] = sqrt(fabs(A[0][0]));

   for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
      {
        if(i==0 && j==0)
         continue;

         sum = 0;
           if(i > j)
            {
              S[i][j] = 0;
            }
            else if (i==j)
            {
              for(int k = 0;k < i;k++)
               sum += pow(S[k][i],2)*D[k];
              D[i] = sign(A[i][i] - sum);
              S[i][i] = sqrt( fabs(A[i][i] - sum) );
            }
            else
            {
              for(int k=0;k<i;k++)
                sum += S[k][i]*S[k][j]*D[k];

              S[i][j] = (A[i][j] - sum)/(S[i][i]*D[i]);
            }
     }

     double** ST = new double*[N];
   for(int i=0;i<N;i++)
        ST[i] = new double[N];

   for(int i=0;i<N;i++)
      {
        for(int j=0;j<N;j++)
            ST[i][j]=S[j][i];
      }

   for(int i=0;i<N;i++)
     for(int j=0;j<N;j++)
    {
      ST[i][j]*=D[j];
    }

    for(int i=0;i<N;i++)
      {
       b[i]/=ST[i][i];
        for(int j=i;j<N-1;j++)
         {
            b[j+1]-=ST[j+1][i]*b[i];
         }
      }

  for(int i=0;i<N;i++)
     x[i] = b[i];

  for(int i=0;i<N-1;i++)
     delete ST[i];
delete [] ST;

  for(int i=N-1;i>=0;i--)
      {
       x[i]/=S[i][i];
        for(int j=i;j>0;j--)
         {
            x[j-1]-=S[j-1][i]*x[i];
         }
      }

 for(int i=0;i<N;i++)
   delete S[i];
 delete [] S;
 delete [] D;
}



/**
 * Метод прогонки
 */
void geroevvn::lab4()
{
    double* P = new double[N-1];
    double* Q = new double[N];

     P[0] = -A[0][1]/A[0][0];
     Q[0] = b[0]/A[0][0];

      for(int i=1;i<N-1;i++)
       {
         P[i] = -A[i][i+1]/(A[i][i]+A[i-1][i]*P[i-1]);
         Q[i] = (b[i] - A[i][i-1]*Q[i-1])/(A[i][i] + A[i][i-1]*P[i-1]);
       }
        Q[N-1] = (b[N-1] - A[N-1][N-2]*Q[N-2])/(A[N-1][N-1] + A[N-1][N-2]*P[N-2]);


       x[N-1] = Q[N-1];
        for(int i=N-2;i>=0;i--)
          {
            x[i] = P[i]*x[i+1]+Q[i];
          }


     delete [] P;
     delete [] Q;


}


/**
 * Метод Якоби
 */
void geroevvn::lab5()
{
    const double eps = 10E-20;

    double* D = new double[N];
    double** LU = new double*[N];

     for(int i=0;i<N;i++)
      LU[i] = new double[N];

    for(int i=0;i<N;i++)
     for(int j=0;j<N;j++)
       {
         if(i!=j)
          {
            LU[i][j] = A[i][j];
          }
         else
          {
            D[i] = A[i][j];
            LU[i][j] = 0;
          }
       }

  double* new_x = new double[N];
  double S;
  double temp;
  double k=0;

  for(int i=0;i<N;i++)
        new_x[i] = D[i];

   do{
      for(int i=0;i<N;i++)
       {
         S = 0;
        for(int j=0;j<N;j++)
         {
           if(j!=i)
            S +=  LU[i][j]*new_x[j];
         }
         x[i] = (b[i] - S)/D[i];
       }

        temp = fabs(new_x[0] - x[0]);

       for(int i=1;i<N;i++)
        if( fabs(new_x[i] - x[i]) > temp )
         temp = fabs(new_x[i] - x[i]);

        for(int i=0;i<N;i++)
            new_x[i] = x[i];

     k++;
   }while(temp >= eps);

  delete [] new_x;

  for(int i=0;i<N;i++)
     delete LU[i];

    delete [] LU;
    delete [] D;

}



/**
 * Метод Зейделя
 */
void geroevvn::lab6()
{
  const double eps = 10E-20;
    double* D = new double[N];
    double** L = new double*[N];
    double** U = new double*[N];

     for(int i=0;i<N;i++)
      {
        L[i] = new double[N];
        U[i] = new double[N];
      }

    for(int i=0;i<N;i++)
     for(int j=0;j<N;j++)
       {
         if(i > j)
          {
            L[i][j] = A[i][j];
            U[i][j] = 0;
          }
         else if(i < j)
          {
            U[i][j] = A[i][j];
            L[i][j] = 0;
          }
         else
          {
            D[i] = A[i][j];
            L[i][j] = 0;
            U[i][j] = 0;
          }
       }

  double* new_x = new double[N];
  double S;
  double temp;
  double k=0;

  for(int i=0;i<N;i++)
       new_x[i] = D[i];

  do{
      for(int i=0;i<N;i++)
       {
         S = 0;
        for(int j=0;j<N;j++)
         {
           if(j<i)
            S += L[i][j]*x[j];
           if(j>i)
            S += U[i][j]*new_x[j];
         }
         x[i] = (b[i] - S)/D[i];
       }

        temp = fabs(new_x[0] - x[0]);

       for(int i=1;i<N;i++)
        if( fabs(new_x[i] - x[i]) > temp )
         temp = fabs(new_x[i] - x[i]);

           for(int i=0;i<N;i++)
            new_x[i] = x[i];

     k++;
   }while(temp >= eps);

  delete [] new_x;

   for(int i=0;i<N;i++)
     {
      delete L[i];
      delete U[i];
     }

    delete [] L;
    delete [] U;
    delete [] D;
}



/**
 * Один из градиентных методов
 */
void geroevvn::lab7()
{

}

/**
 * Один из градиентных методов
 */
void geroevvn::lab8()
{

}

std::string geroevvn::get_name() {
  return std::string("Geroev V.N.");
}
