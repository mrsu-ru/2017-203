#include "zhuravlevama.h"
using namespace std;
/**
 * Метод Гаусса
 */
void zhuravlevama::lab1()
{
    double obrv1=0,obrv0=0;///obrv1-число,преобр. эл-т в 1 obrv0-в 0
///прямой ход
   for(int m=0;m<N;m++)///m-строка
    {
     obrv1=A[m][m];
     for(int j=0;j<N;j++)
          A[m][j]=A[m][j]/obrv1;
     b[m]=b[m]/obrv1;
     for(int i=m+1;i<N;i++)
        {
         obrv0=A[i][m];
         for(int j=0;j<n;j++)
             A[i][j]=A[i][j]-obrv0*A[m][j];
         b[i]=b[i]-obrv0*b[m];
          }
    }
///обратный ход
    for(int m=N-1;m>0;m--)
    {
        for(int i=m-1;i+1>0;i--)
           {
            obrv0=A[i][m];
            for(int j=0;j<N;j++)
                A[i][j]=A[i][j]-obrv0*A[m][j];
            b[i]=b[i]-obrv0*b[m];
           }
    }
    for(int i=0;i<N;i++)
        x[i]=b[i];
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void zhuravlevama::lab2()
{
        //меняем местами строки


    double obrv1=0,obrv0=0;///obrv1-число,преобр. эл-т в 1 obrv0-в 0
///прямой ход
   for(int m=0;m<N;m++)///m-строка
    {
///выбор главного элемента
     int ime=m;///ime-индекс наибольшего по модулю элемента
     for(int i=m+1;i<N;i++)
        if(abs(A[ime][m])<abs(A[i][m]))
           ime=i;
     for(int i=0;i<N;i++)
         swap(A[ime][i],A[m][i]);
     swap(b[m],b[ime]);
///решениe..Г
     obrv1=A[m][m];
     for(int j=0;j<N;j++)
          A[m][j]=A[m][j]/obrv1;
     b[m]=b[m]/obrv1;
     for(int i=m+1;i<N;i++)
        {
         obrv0=A[i][m];
         for(int j=0;j<n;j++)
             A[i][j]=A[i][j]-obrv0*A[m][j];
         b[i]=b[i]-obrv0*b[m];
          }
    }
///обратный ход
    for(int m=N-1;m>0;m--)
    {
        for(int i=m-1;i+1>0;i--)
           {
            obrv0=A[i][m];
            for(int j=0;j<N;j++)
                A[i][j]=A[i][j]-obrv0*A[m][j];
            b[i]=b[i]-obrv0*b[m];
           }
    }
    for(int i=0;i<N;i++)
        x[i]=b[i];
}



}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void zhuravlevama::lab3()
{

}



/**
 * Метод прогонки
 */
void zhuravlevama::lab4()
{

}



/**
 * Метод Якоби
 */
void zhuravlevama::lab5()
{

}



/**
 * Метод Зейделя
 */
void zhuravlevama::lab6()
{

}



/**
 * Один из градиентных методов
 */
void zhuravlevama::lab7()
{

}
