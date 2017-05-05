#include "fedotov.h"

/**
 * Метод Гаусса
 */
void fedotov::lab1()
{
    double tmp = 1;
    /*прямой ход*/
    for (int i = 0; i < N; i++)
    {
        tmp = A[i][i];
        b[i] /= tmp;

        for (int j = 0; j < N; j++)
        {
            A[i][j] /= tmp;
        }

        for (int k = i + 1; k < N; k++)
        {
            tmp = A[k][i];
            for (int z = 0; z < N; z++)
            {
                A[k][z] -= A[i][z] * tmp;
            }
            b[k] -= b[i] * tmp;
        }
    }

    /*обратный ход*/
    for (int j = N - 1; j > 0; j--)
    {
        for (int i = j - 1; i >= 0; i--)
        {
            b[i] -= b[j] * A[i][j];
        }
        x[j] = b[j];
    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void fedotov::lab2()
{

    /*прямой ход
    найдем максимальный элемент по модулю , поменяюм эти строки , а дальше по Гаусу
    */
    int max_element_in_column = 0;
    double tmp = 1;
    for (int i = 0; i < N; i++)
    {

        max_element_in_column = i;
        for (int k = i + 1; k < N; k++)
            if (abs(A[k][i]) > abs(A[max_element_in_column][i]))
            {
                max_element_in_column = k;
                for (int k = 0; k < N; k++)
                {
                    std::swap(A[i][k], A[max_element_in_column][k]);
                }
                std::swap(b[i], b[max_element_in_column]);
            }

        tmp = A[i][i];
        b[i] /= tmp;

        for (int j = 0; j < N; j++)
        {
            A[i][j] /= tmp;
        }

        for (int k = i + 1; k < N; k++)
        {
            tmp = A[k][i];
            for (int z = 0; z < N; z++)
            {
                A[k][z] -= A[i][z] * tmp;
            }
            b[k] -= b[i] * tmp;
        }
    }

    /*обратный ход*/
    for (int j = N - 1; j > 0; j--)
    {
        for (int i = j - 1; i >= 0; i--)
        {
            b[i] -= b[j] * A[i][j];
        }
        x[j] = b[j];
    }
}



/**
 * Метод квадратного корня (метод Холецкого)
 *литература http://info.alnam.ru/book_clm.php?id=46
 */
void fedotov::lab3()
{
    double **L = new double *[N];
    for(int i = 0; i < N; i++)
    {
        L[i] = new double[N];
    }

    double *y = new double[N];
    double s = 0;


    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            L[i][j] = 0;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int k = 0; k < i; k++)
        {
            s += L[i][k] * L[i][k];
        }

        L[i][i] = sqrt(A[i][i] - s);
        s = 0;

        for(int j = i + 1; j < N; j++)
        {
            for(int k = 0; k < j - 1; k++)
            {
                s += L[j][k] * L[i][k];
            }

            L[j][i] = (A[j][i] - s) / L[i][i];
            s = 0;
        };
    }

    for(int i = 0; i < N; i++)
    {
        x[i] = 0;
        y[i] = 0;
    }

    y[0] = b[0] / L[0][0];

    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            s += L[i][j] * y[j];
        }

        y[i] = (b[i] - s) / L[i][i];
        s = 0;
    }

    x[N - 1] = y[N - 1] / L[N - 1][N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            s += L[j][i] * x[j];
        }

        x[i] = (y[i] - s) / L[i][i];
        s = 0;
    }

    for(int i=0; i<N; i++)
        delete L[i];


    for(int i=0; i<N; i++)
    delete [] y;

}



/**
 * Метод прогонки
 *mathhelpplanet.com/static.php?p=chislennyye-metody-resheniya-slau
 */
void fedotov::lab4()
{
    //P,Q - прогоночные коэффициенты
    double *P = new double[N];
    double *Q = new double[N];

    double a;
    double c;
    double e;

    P[0] = -A[0][1] / A[0][0];
    Q[0] = b[0] / A[0][0];

    for (int i = 1; i < N; i++)
    {
        //a c e - нижн.,диаг.,верхн.
        a = A[i][i - 1];
        c = -A[i][i];
        e = A[i][i + 1];

        P[i] = e / (c - a * P[i - 1]);
        Q[i] = (a * Q[i - 1] - b[i]) / (c - a * P[i - 1]);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        x[i] = P[i] * x[i + 1] + Q[i];
    }

    delete[] P;
    delete[] Q;
}



/**
 * Метод Якоби
 *литература
 *http://mathhelpplanet.com/static.php?p=chislennyye-metody-resheniya-slau
 */
void fedotov::lab5()
{
    const double eps = 10E-20;

    double* D = new double[N];
    double** LU = new double*[N];

    for(int i=0; i<N; i++)
        LU[i] = new double[N];

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            if(i==j)
            {
                D[i] = A[i][j];
                LU[i][j] = 0;
            }
            else
            {
                LU[i][j] = A[i][j];
            }
        }

    double* new_x = new double[N];
    double S;
    double temp;
    double k=0;

    for(int i=0; i<N; i++)
        new_x[i] = D[i];

    do
    {
        for(int i=0; i<N; i++)
        {
            S = 0;
            for(int j=0; j<N; j++)
            {
                if(j!=i)
                    S +=  LU[i][j]*new_x[j];
            }
            x[i] = (b[i] - S)/D[i];
        }

        temp = fabs(new_x[0] - x[0]);

        for(int i=1; i<N; i++)
            if( fabs(new_x[i] - x[i]) > temp )
                temp = fabs(new_x[i] - x[i]);

        for(int i=0; i<N; i++)
            new_x[i] = x[i];

        k++;
    }
    while(temp >= eps);

    delete [] new_x;

    for(int i=0; i<N; i++)
        delete LU[i];

    delete [] LU;
    delete [] D;
}



/**
 * Метод Зейделя
 */
void fedotov::lab6()
{
    const double eps = 10E-20;

    double* D = new double[N];
    double** LU = new double*[N];

    for(int i=0; i<N; i++)
        LU[i] = new double[N];

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            if(i==j)
            {
                D[i] = A[i][j];
                LU[i][j] = 0;
            }
            else
            {
                LU[i][j] = A[i][j];
            }
        }

    double* new_x = new double[N];
    double S;
    double temp;
    double k=0;

    for(int i=0; i<N; i++)
        new_x[i] = D[i];
    ::memset(x, 0, sizeof(double)*N);
    do
    {
        for(int i=0; i<N; i++)
        {
            S = 0;
            for(int j=0; j<N; j++)
            {
                if(j!=i)
                    S +=  LU[i][j]*x[j];
            }
            x[i] = (b[i] - S)/D[i];
            //new_x[i] = x[i];
        }

        temp = fabs(new_x[0] - x[0]);

        for(int i=1; i<N; i++)
        {
            //if( fabs(new_x[i] - x[i]) > temp )
            temp = (new_x[i] - x[i])*(new_x[i] - x[i]);
        }
        temp = sqrt(temp);
        for(int i=0; i<N; i++)
            new_x[i] = x[i];

        k++;
    }
    while(temp >= eps);

    delete [] new_x;

    for(int i=0; i<N; i++)
        delete LU[i];

    delete [] LU;
    delete [] D;
}



/**
 * Один из градиентных методов
 */
void fedotov::lab7()
{

}


void fedotov::lab8()
{

}



std::string fedotov::get_name()
{
    return std::string("Федотов Владимир");
}
