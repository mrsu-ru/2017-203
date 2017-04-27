#include "KulyaginaTI.h"
using namespace std;

void KulyaginaTI::lab1() {
    double temp;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            temp = A[j][i]/A[i][i];
            if (temp != 0) {
                for (int k = N-1; k >= i; k--)
                    A[j][k] -= temp * A[i][k];
                b[j] -= temp*b[i];
            }
        }
    }

    x[N - 1] = b[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < N; ++j)
            x[i] -= x[j] * A[i][j];
        x[i] /= A[i][i];
    }

}

void KulyaginaTI::lab2() {

    for (int k = 0; k < N; ++k) {
        int str_max_el = -1;
        double max_el = 0;
        for (int p = 0; p < N; ++p) {
            if (abs(A[k][p]) >= max_el) {
                max_el = abs(A[k][p]);
                str_max_el = p;
            }
        }

        if (str_max_el != -1) {
            for (int j = 0; j < N; ++j) {
                swap(A[j][str_max_el], A[j][k]);
            }
            swap(b[str_max_el], b[k]);

            for (int i = k+1; i < N; ++i)
            {

                double koef = A[i][k]/(A[k][k]*1.0);
                for (int j = k; j < N; ++j)
                    A[i][j] -= koef*A[k][j];
                b[i] -= koef*b[k];
            }

        }

    }

    x[N - 1] = b[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < N; ++j)
            x[i] -= x[j] * A[i][j];
        x[i] /= A[i][i];
    }

}
void KulyaginaTI::lab3()
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
        double sum = 0;

        for (int j = 0; j < i; j++) {
            sum = 0;
            for (int k = 0; k < j; k++)
                sum += L[i][k] * L[j][k];
            L[i][j] = (A[i][j] - sum) / L[j][j];
        }

        sum = 0;
        for (int k = 0; k < i; k++)
            sum += L[i][k] * L[i][k];
        L[i][i] = sqrt(A[i][i] - sum);

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


void KulyaginaTI::lab4()
{
	  double *d, *c, *a;
    d = new double[N];
    c = new double[N];
    a = new double[N];
    double m;

    a[0] = 0;
    d[N-1] = 0;
    for (int i = 0; i < N; ++i)
    {
        if (i - 1 >= 0 && i - 1 < N)
            d[i] = A[i-1][i];
        c[i] = A[i][i];
        if (i + 1 >= 0 && i + 1 < N)
            a[i] = A[i+1][i];
    }

    for (int i = 1; i < N; i++)
    {
        m = a[i]/c[i-1];
        c[i] = c[i] - m*d[i-1];
        b[i] = b[i] - m*b[i-1];
    }

    x[N-1] = b[N-1]/c[N-1];

    for (int i = N - 2; i >= 0; i--)
        x[i]=(b[i]-d[i]*x[i+1])/c[i];

    delete[] a, c, d;

}


void KulyaginaTI::lab5()
{

}


void KulyaginaTI::lab6()
{

}


void KulyaginaTI::lab7()
{

}
void KulyaginaTI::lab8()
{

}

std::string KulyaginaTI::get_name()
{
  return std::string("Kulyagina T.I.");
}
