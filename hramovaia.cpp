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
    double **S = new double*[N];
    double **ST = new double*[N];
    double *D = new double[N];
    for(int i=0; i<N; i++)
    {
       S[i] = new double[N];
       ST[i] = new double[N];
       D[i]=0;
       for(int j=0; j<N; j++)
       {
           S[i][j]=0;
       }
    }
    //вычисляем D и S
    for(int i=0; i<N; i++)
    {
        double isum = 0;
        for(int k=0; k<i; k++)
                isum += std::abs(S[k][i]) * std::abs(S[k][i]) * D[k];

        if((A[i][i] - isum) > 0)
            D[i] = 1;
        else
            D[i] = -1;

        S[i][i] = sqrt(std::abs(A[i][i] - isum));

        for(int j=i+1; j<N; j++)
        {
            double sum=0;
            for(int k=0; k<i; k++)
                sum += S[k][i] * S[k][j] * D[k];
            S[i][j] = (A[i][j] - sum) / (S[i][i] * D[i]);
        }
    }
    //транспонируем S
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            ST[i][j] = S[j][i];
    //умножаем ST на D
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            ST[i][j] *= D[j];
    //ST*D * y = b
    double *y = new double[N];
    for(int i=0; i<N; i++)
    {
        double s=0;
        for(int j=0; j<i; j++)
            s += y[j] * ST[i][j];
        y[i]=(b[i]-s)/ST[i][i];
    }
    //S * x = y
    for(int i=N-1; i>=0; i--)
    {
        double s=0;
        for(int j=i+1; j<N; j++)
            s += x[j] * S[i][j];
        x[i]=(y[i] - s)/S[i][i];
    }

    for(int i=0; i<N; i++)
    {
        delete [] S[i];
        delete [] ST[i];
    }
    delete [] S;
    delete [] ST;
    delete [] D;
    delete [] y;
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
    double *xold = new double[N];
    for (int i=0; i<N; i++)
    {
        x[i]=0; // начальное приближение
    }
    double error=0.0;
    double eps=1e-20;
    int k=0;
    do
    {
        k++;
        error=0.0;
        for(int i=0; i<N; i++)
            xold[i]=x[i];
        for(int i=0; i<N; i++)
        {
            double s=0;
            for(int j=0; j<i; j++)
                s += A[i][j] * xold[j];
            for(int j=i+1; j<N; j++)
                s += A[i][j] * xold[j];
            x[i]=(b[i] - s)/A[i][i];
        }
        error = std::abs(xold[0]-x[0]);
        for(int i=0; i<N; i++)
        {
            if(std::abs(xold[i]-x[i]) > error)
                error = std::abs(xold[i]-x[i]);
        }
    } while(error >= eps);
    std::cout << "Чило итераций : " << k << std::endl;

    delete [] xold;
}



/**
 * Метод Зейделя
 */
void hramovaia::lab6()
{
    double *xold = new double[N];
    for (int i=0; i<N; i++)
    {
        x[i]=0; // начальное приближение
    }
    double error=0.0;
    double eps=1e-20;
    int k=0;
    do
    {
        k++;
        error=0.0;
        for(int i=0; i<N; i++)
            xold[i]=x[i];
        for(int i=0; i<N; i++)
        {
            double s=0;
            for(int j=0; j<i; j++)
                s += A[i][j] * x[j];
            for(int j=i+1; j<N; j++)
                s += A[i][j] * xold[j];
            x[i]=(b[i] - s)/A[i][i];
        }
        for(int i=0; i<N; i++)
        {
            if(std::abs(xold[i]-x[i]) > error)
                error = std::abs(xold[i]-x[i]);
        }

    } while(error >= eps);
    std::cout << "Чило итераций : " << k << std::endl;

    delete [] xold;
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
