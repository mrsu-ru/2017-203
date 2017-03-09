#include "KulyaginaTI.h"
using namespace std;

void KulyaginaTI::lab1() {
    double temp;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            temp = A[j][i]/A[i][i];
            if (temp != 0) {
                for (int k = N; k >= i; k--)
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

}


void KulyaginaTI::lab4()
{

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
  return std::string("Кулягина Таисия");
}