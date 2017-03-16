#include "hramovaia.h"

/**
 * Метод Гаусса
 */
void hramovaia::lab1()
{
    double temp;
    //прямой ход
    for (int k = 0; k < N; k++)
    {
        temp = A[k][k];

        //получаем единицу в a[k][k]
        for (int j = 0; j < N; j++)
            A[k][j] /= temp;
        b[k] /= temp;

        for (int i = k + 1; i < N; i++)
        {
            temp = A[i][k];
            /*получаем нули под единицей - вычитаем из i-ой строки k-ую,
            умноженную на коэф a[i][k] */
            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
            }
            b[i] -= b[k] * temp;
        }
    }

    //обратный ход
    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];
            //получаем нули над единицами
            for (int j = 0; j < N; j++)
                A[i][j] -= A[k][j] * temp;
            b[i] -= b[k] * temp;
        }
    }

    for(int i=0; i<N; i++)
        x[i]=b[i];
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void hramovaia::lab2()
{
    double temp;
    //прямой ход
    for (int k = 0; k < N; k++)
    {
        //ищем максимальный по модулю элемент в столбце
        int maxind=k;
        for(int i=k+1;i<N;i++)
            if(abs(A[i][k]) > abs(A[maxind][k]))
                maxind=i;
        //меняем местами строки
        for(int i=0;i<N;i++)
            std::swap(A[k][i],A[maxind][i]);
        std::swap(b[k],b[maxind]);


        temp = A[k][k];

        //получаем единицу в a[k][k]
        for (int j = 0; j < N; j++)
            A[k][j] /= temp;
        b[k] /= temp;

        for (int i = k + 1; i < N; i++)
        {
            temp = A[i][k];
            /*получаем нули под единицей - вычитаем из i-ой строки k-ую,
            умноженную на коэф a[i][k] */
            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
            }
            b[i] -= b[k] * temp;
        }
    }

    //обратный ход
    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];
            //получаем нули над единицами
            for (int j = 0; j < N; j++)
                A[i][j] -= A[k][j] * temp;
            b[i] -= b[k] * temp;
        }
    }

    for(int i=0; i<N; i++)
        x[i]=b[i];
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void hramovaia::lab3()
{

}



/**
 * Метод прогонки
 */
void hramovaia::lab4()
{
    double *alpha = new double[N];
    double *beta = new double[N];

    //определяем прогоночные коэффициенты
    alpha[1] = -A[0][1] / A[0][0];
    beta[1] = b[0] / A[0][0];
    for(int i=2; i<N; i++)
    {
        double a = A[i-1][i-2]; //эл-т под диагональю
        double c = -A[i-1][i-1]; //эл-т диагонали
        double e = A[i-1][i]; //эл-т над диагональю

        alpha[i] = e / (c - a * alpha[i-1]);
        beta[i] = (a * beta[i-1] - b[i-1]) / (c - a * alpha[i-1]);
    }

    x[N-1] = (A[N-1][N-2] * beta[N-1] - b[N-1]) / (-A[N-1][N-1] - alpha[N-1] * A[N-1][N-2]);

    for(int i=N-2; i>=0; i--)
    {
        x[i] = alpha[i+1] * x[i+1] + beta[i+1];
    }

    delete [] alpha;
    delete [] beta;
}



/**
 * Метод Якоби
 */
void hramovaia::lab5()
{

}



/**
 * Метод Зейделя
 */
void hramovaia::lab6()
{

}



/**
 * Один из градиентных методов
 */
void hramovaia::lab7()
{

}
void hramovaia::lab8()
{

}

std::string hramovaia::get_name()
{
  return std::string("Храмова Ирина");
}
