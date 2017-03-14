#include "korytinsi.h"

/**
 * Метод Гаусса
 */
void korytinsi::lab1()
{
double *x, max;
  int k;
  x = new double[N];
  k = 0;



while (k < N)
   {
// Нормализация уравнений
    for (int i = k; i < N; i++) {
      double temp = A[k][k];
       for (int j = 0; j < N; j++) {
        A[i][j] = A[i][j] / temp;
      }
      b[i] = b[i] / temp;
      if (i == k)
       continue; // уравнение не вычитаем сам из себя само из себя
      for (int j = 0; j < N; j++) {
        A[i][j] = A[i][j] - A[k][j];

      }
     b[i] = b[i] - x[k];
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
      b[i]=b[k]*temp-b[i];
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
      b[i]=b[k]*temp-b[i];
}
  }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void korytinsi::lab3()
{

}



/**
 * Метод прогонки
 */
void korytinsi::lab4()
{

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
