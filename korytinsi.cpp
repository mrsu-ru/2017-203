#include "korytinsi.h"

/**
 * Метод Гаусса
 */
void korytinsi::lab1()
{
double *x, max;
  int k;
  const double eps = 0.000000000001;
  x = new double[N];
  k = 0;
while (k < N)
   {
// Нормализация уравнений
for (int i = k; i < N; i++) {
      double temp = A[i][k];
     if (abs(temp) < eps)
      continue; // для нулевого коэффициента пропускаем
       for (int j = 0; j < N; j++) {
        A[i][j] = A[i][j] / temp;
      }
      b[i] = b[i] / temp;
      if (i == k)
       continue; // уравнение не вычитаем сам из себя само из себя
      for (int j = 0; j < N; j++) {
        A[i][j] = A[i][j] - A[k][j];
       }
     b[i] = b[i] - b[k];
    }
    k++;
  }
  // обратная подстановка
  for (k = N - 1; k >=0; k--) {
  x[k] = b[k];
    for (int i = k-1; i >=0; i--) {
       double temp=A[i][k];

      b[i]=-b[k]*temp+b[i];
}
  }
}

/**
 * Метод Гаусса с выбором главного элемента
 */
void korytinsi::lab2()
{
 double *x, max;
  int k, index;
 const double eps = 0.000000000001;  // точность
  x = new double[N];
  k = 0;
  while (k < N)
    {
        // Поиск строки с максимальным A[i][k]
    max = abs(A[k][k]);
    index = k;
    for (int i = k + 1; i < N; i++) {
      if (abs(A[i][k]) > max) {
        max = abs(A[i][k]);
        index = i;
      }
    }
  // Перестановка строк
for (int j = 0; j < N; j++) {
      double temp = A[k][j];
      A[k][j] = A[index][j];
      A[index][j] = temp;
    }
    double temp = b[k];
    b[k] = b[index];
    b[index] = temp;
  // Нормализация уравнений
    for (int i = k; i < N; i++) {
      double temp = A[i][k];
      if (abs(temp) < eps)
      continue; // для нулевого коэффициента пропускаем
      for (int j = 0; j < N; j++) {
        A[i][j] = A[i][j] / temp;
      }
      b[i] = b[i] / temp;
      if (i == k)
       continue; // уравнение не вычитаем сам из себя само из себя
      for (int j = 0; j < N; j++) {
        A[i][j] = A[i][j] - A[k][j];
      }
      b[i] = b[i] - b[k];
    }
    k++;
  }
  // обратная подстановка
  for (k = N - 1; k >=0; k--) {
  x[k] = b[k];
    for (int i = k-1; i >=0; i--) {
       double temp=A[i][k];
            for (int j=0; j<N; j++)
           A[i][j]=A[k][j]*temp+A[i][j];
      b[i]=-b[k]*temp+b[i];
}
  }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void korytinsi::lab3()
{
 double *x, max;
  int k;
   x = new double[N];
  k = 0;


  double temp, temp2;
  for (int i = 0; i < N; i++)
  {
      temp = 0.0; temp2 = 1;
      for (int k = 0; k < i; k++)
        temp += pow(A[k][i], 2);
      A[i][i] = sqrt(A[i][i] - temp);

      if(i==0)
        temp2 = 0;
      else
      for(int l=i; l<N; l++)
      temp2 = temp2 * A[i-1][l];

      for (int j = 0; j < N; j++)
      {
          if (j < i) A[i][j] = 0;
          else if (i == j)  continue;
          else A[i][j] = (A[i][j] - temp2) / A[i][i];
      }
  }

  for (int i = 0; i < N; i++)
  {
      temp = 0;
      for (int k = 0; k < i; k++)
        temp = temp + A[k][i] * b[k];
      b[i] = (b[i] - temp) / A[i][i];
  }

  for (int k = N-1; k >= 0; k--)
  {
      double res = 0;
      for (int i = k+1; i < N; i++)
        res += A[k][i] * x[i];
      x[k] = (b[k] - res)/A[k][k];
  }

}



/**
 * Метод прогонки
 */
void korytinsi::lab4()
{
double *x;

x = new double[N];
  double* AA = new double[N];
    double* B = new double[N];
int z;
 AA[0]=A[0][1]/(-A[0][0]);
 B[0]=b[0]/A[0][0];

for(int i=1;i<N;i++)
    {

     AA[i] = A[i][i+1]/(-A[i][i-1]*AA[i-1]-A[i][i]);
     B[i] = (-b[i] + A[i][i-1]*B[i-1])/(-A[i][i-1]*AA[i-1]-A[i][i]);

    }
for(int i=N-2;i>=0;i--)
    x[i]=AA[i]*x[i+1]+B[i];


}



/**
 * Метод Якоби
 */
void korytinsi::lab5()
{

}



/**
 * Метод Зейделя
 */
void korytinsi::lab6()
{

}



/**
 * Один из градиентных методов
 */
void korytinsi::lab7()
{

}
