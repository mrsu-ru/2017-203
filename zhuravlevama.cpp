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
         for(int j=0;j<N;j++)
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
         for(int j=0;j<N;j++)
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
 double *aa=new double[N];
 double *bb=new double[N];
 double *cc=new double[N];

 aa[N-1]=0;
 bb[N-1]=A[N-1][N-1];
 cc[N-1]=0;

 for(int i=0;i<N-1;i++)
      {
       cc[i]=A[i][i+1];
       aa[i]=A[i+1][i];
       bb[i]=A[i][i];
      }
 double gam=0.0;
 double *alf=new double[N];
 double *bet=new double[N];

 gam=bb[0];
 alf[0]=-cc[0]/gam;
 bet[0]=b[0]/gam;

 for(int i=1;i<N;i++)
    {
     gam=bb[i]+aa[i-1]*alf[i-1];
     alf[i]=-cc[i]/gam;
     bet[i]=(b[i]-aa[i-1]*bet[i-1])/gam;
    }

 x[N-1]=bet[N-1];
 for(int i=N-2;i>=0;i--)
     x[i]=alf[i]*x[i+1]+bet[i];


      delete[]alf;
      delete[]bet;
      delete[]aa;
      delete[]bb;
      delete[]cc;

}




/**
 * Метод Якоби
 */
void zhuravlevama::lab5()
{
    double* px=new double[N];
    double eps=0.000000001;
	double pr=eps;
	for(int i=0;i<N;i++)x[i]=b[i];
    do
      {
		for(int i=0;i<N;i++)
           {
			px[i]=b[i];
			for(int j=0;j<N;j++)
			    if(i!=j)
					px[i]=px[i]-A[i][j]*x[j];
			px[i]=px[i]/A[i][i];
           }
        pr=abs(x[0]-px[0]);

		for(int k=0;k<N;k++)
            {
			 if(abs(x[k]-px[k])>pr)
				pr=abs(x[k]-px[k]);
			x[k]=px[k];
		   }
	 } while(pr>eps);
}



/**
 * Метод Зейделя
 */
void zhuravlevama::lab6()
{
    double* px=new double[N];
    double eps=0.000000001;
	double pr=eps;
	for(int i=0;i<N;i++)x[i]=b[i];

   do
	{
		for(int i=0;i<N;i++)
			px[i]=x[i];

		for(int i=0;i<N; i++)
		{
			double temp=0;
			for(int j=0;j<i;j++)
				temp=temp+A[i][j]*x[j];

			for (int j=i+1;j<N;j++)
				temp=temp+A[i][j]*x[j];
			x[i]=(b[i]-temp)/A[i][i];

			pr=0;
			for (int i=0;i<N;i++)
				pr+=(x[i]-px[i])*(x[i]-px[i]);
		}
	} while(pr>=eps);

}



/**
 * Один из градиентных методов
 */
void zhuravlevama::lab7()
{

}



/**
 * Один из градиентных методов
 */
void zhuravlevama::lab8()
{

}
