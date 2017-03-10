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



/**
 * Метод квадратного корня (метод Холецкого)
 */
void geroevvn::lab3()
{

}



/**
 * Метод прогонки
 */
void geroevvn::lab4()
{

}



/**
 * Метод Якоби
 */
void geroevvn::lab5()
{

}



/**
 * Метод Зейделя
 */
void geroevvn::lab6()
{

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
