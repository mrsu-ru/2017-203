#include "mulichevaes.h"

/**
 * Метод Гаусса
 */
void mulichevaes::lab1()
{
    double t;
    //Прямой ход
    for (int k = 0; k < N; k++)
    {
        t = A[k][k];

        //Делим все элементы k'ой строки на a[k][k] элемент, потому что он диагональный и мы хотим на нём получить значение 1 для
       // удобства дальнейших вычислений
        for (int j = 0; j < N; j++)
            A[k][j] = A[k][j] / t;
            b[k] =b[k]/t;

        for (int i = k + 1; i < N; i++)
        {
            t = A[i][k];
            //Вычитаем из всех строк лежащих ниже k'ой к'ую строку помноженную на k'ый элемент строки
           // из которой вычитаем, что даёт нам ноль в этом элементе после вычитания и матрица постепенно приобретает треугольный вид
        
            for (int j = 0; j < N; j++)
            {
                A[i][j] =A[i][j]- A[k][j] * t;
            }
            b[i] =b[i]- b[k] * t;
        }
    }

    //Матрица треугольного вида готова, теперь можем последовательно, снизу вверх вычислять искомые значения элементов матрицы x
    //Осуществляем обратный ход
    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            t = A[i][k];
            
            for (int j = 0; j < N; j++)
                A[i][j] =A[i][j]- A[k][j] * t;
            b[i] =b[i] - b[k] * t;
        }
    }

    for(int i=0; i<N; i++)
        x[i]=b[i];
    
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void mulichevaes::lab2()
{
//Это некоторая оптимизация метода Гаусса. 
//Суть состоит в том, что бы при каждом шаге, элемент главной диагонали, под которым мы будем получать нули в нижележащих строках, 
//должен быть максимальным из других таких же элементов нижележащих строк. Потому как это поможет при делении уменьшить ошибку округления,
// ну и вообще там может оказаться деление на ноль
    double t;
    
    for (int k = 0; k < N; k++)
    {
    //Ищем самый большой элемент стоящий на к'атом месте по всем строкам, по умолчанию он k'ый
        int maxel=k;
        for(int i=k+1;i<N;i++)
            if(abs(A[i][k]) > abs(A[maxel][k]))
                maxel=i;
     //Нашли, теперь надо поменять k'ую строчку и строчку с максимальным элементом местами
        for(int i=0;i<N;i++)
            std::swap(A[k][i],A[maxel][i]);
        std::swap(b[k],b[maxel]);


        //А дальше всё делаем по методу Гаусса по коду из лабораторной номер 1

    //Прямой ход
   
        t = A[k][k];

 //Делим все элементы k'ой строки на a[k][k] элемент, потому что он диагональный и мы хотим на нём получить значение 1 
//для удобства дальнейших вычислений
        for (int j = 0; j < N; j++)
            A[k][j] = A[k][j] / t;
            b[k] =b[k]/t;

        for (int i = k + 1; i < N; i++)
        {
            t = A[i][k];
   //Вычитаем из всех строк лежащих ниже k'ой к'ую строку помноженную на k'ый элемент строки,
// из которой вычитаем, что даёт нам ноль в этом элементе после вычитания и матрица постепенно приобретает треугольный вид
        
            for (int j = 0; j < N; j++)
            {
                A[i][j] =A[i][j]- A[k][j] * t;
            }
            b[i] =b[i]- b[k] * t;
        }
    }

    //Матрица треугольного вида готова, теперь можем последовательно, снизу вверх вычислять искомые значения элементов матрицы x
    //Осуществляем обратный ход
    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            t = A[i][k];
            
            for (int j = 0; j < N; j++)
                A[i][j] =A[i][j]- A[k][j] * t;
            b[i] =b[i] - b[k] * t;
        }
    }

    for(int i=0; i<N; i++)
        x[i]=b[i];
}


/**
 * Метод Холецкого
 */
void mulichevaes::lab3()
{



 double **L;
    L = new double*[N];
    for (int i = 0;  i < N; i++) {
        L[i] = new double[N];
        memset(L[i], 0, sizeof(double)*N);
    }
    double *y;
    y = new double[N];


    for (int i = 0; i < N; i++) {
        double sumikjk = 0;

        for (int j = 0; j < i; j++) { // поиск эл/ слева от диагонали
            sumikjk = 0;
            for (int k = 0; k < j; k++)
                sumikjk += L[i][k] * L[j][k];
            L[i][j] = (A[i][j] - sumikjk) / L[j][j];
        }

        sumikjk = 0;
        for (int k = 0; k < i; k++)
            sumikjk += L[i][k] * L[i][k];
        L[i][i] = sqrt(A[i][i] - sumikjk);

    }


    y[0] = b[0];
    for (int i = 1; i < N ; ++i) {
        y[i] = b[i];
        for (int j = 0; j < i; ++j) {
            y[i] -= y[j]*L[i][j];
        }
        y[i] /= L[i][i];
    }

    x[N - 1] = y[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < N; ++j)
            x[i] -= x[j] * L[j][i];
        x[i] /= L[i][i];
    }


    for (int i = 0; i < N; i++)
        delete[] L[i];
    delete[] L;
    delete[] y;
}


/**
 * Метод Прогонки
 */


void mulichevaes::lab4()
{

//Метод прогонки - частный случай метода Гаусса.
//Матрица трёхдиагональная
    double *d, *c, *a; // верхняя, главная, нижняя диагонали
    d = new double[N];
    c = new double[N];
    a = new double[N];
    double m;

    a[0] = 0; 
    d[N-1] = 0;
    for (int i = 0; i < N; ++i)// выписываем диагонали
    {
        if (i - 1 >= 0 && i - 1 < N) 
            d[i] = A[i-1][i]; //верхняя
        c[i] = A[i][i];      //главная
        if (i + 1 >= 0 && i + 1 < N) 
            a[i] = A[i+1][i]; //нижняя
    }  
//Этап прямой прогонки
    for (int i = 1; i < N; i++) //Вычисляются прогоночные коэффициенты
    {
        m = a[i]/c[i-1];
        c[i] = c[i] - m*d[i-1];
        b[i] = b[i] - m*b[i-1];
    }
//Этап обратной прогонки 
    x[N-1] = b[N-1]/c[N-1]; //вычисляется решение

    for (int i = N - 2; i >= 0; i--) //решение для дальнейших частей
        x[i]=(b[i]-d[i]*x[i+1])/c[i];  

    delete[] b, c, d;
}



/**
 * Метод Якоби
 */
void mulichevaes::lab5()
{
double eps = 0.0001;
    double* B = new double[N];
    double norma;

    do 
	{
        for (int i = 0; i < N; i++) {
            B[i] = b[i];
            for (int j = 0; j < N; j++) {
                if (i != j)
                    B[i] -= A[i][j] * x[j];
            }
            B[i] /= A[i][i];
        }
        norma = abs(x[0] - B[0]);
        for (int j = 0; j < N; j++) {
            if (abs(x[j] - B[j]) > norma)
                norma = abs(x[j] - B[j]);
            x[j] = B[j];
        }
    } while (norma >= eps);
    delete[] B;
}





/**
 * Метод Зейделя
 */
void mulichevaes::lab6()
{
double eps = 0.0001;
    double* B = new double[N];
    double norma;

    do 
	{
        for (int i = 0; i < N; i++) {
            B[i] = b[i];
            for (int j = 0; j < N; j++) {
                if (i != j)
                    B[i] -= A[i][j] * x[j];
            }
            B[i] /= A[i][i];
        }
        norma = abs(x[0] - B[0]);
        for (int j = 0; j < N; j++) {
            if (abs(x[j] - B[j]) > norma)
                norma = abs(x[j] - B[j]);
            x[j] = B[j];
        }
    } while (norma >= eps);
    delete[] B;

}



/**
 * ???? ?? ??????????? ???????
 */
void mulichevaes::lab7()
{

}
void mulichevaes::lab8()
{

}

std::string mulichevaes::get_name()
{        
  return std::string("Муличева Екатерина");
}
