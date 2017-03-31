#include "mulichevaes.h"

/**
 * ����� ������
 */
void mulichevaes::lab1()
{
    double t;
    //������ ���
    for (int k = 0; k < N; k++)
    {
        t = A[k][k];

        //����� ��� �������� k'�� ������ �� a[k][k] �������, ������ ��� �� ������������ � �� ����� �� ��� �������� �������� 1 ���
       // �������� ���������� ����������
        for (int j = 0; j < N; j++)
            A[k][j] = A[k][j] / t;
            b[k] =b[k]/t;

        for (int i = k + 1; i < N; i++)
        {
            t = A[i][k];
            //�������� �� ���� ����� ������� ���� k'�� �'�� ������ ����������� �� k'�� ������� ������
           // �� ������� ��������, ��� ���� ��� ���� � ���� �������� ����� ��������� � ������� ���������� ����������� ����������� ���

            for (int j = 0; j < N; j++)
            {
                A[i][j] =A[i][j]- A[k][j] * t;
            }
            b[i] =b[i]- b[k] * t;
        }
    }

    //������� ������������ ���� ������, ������ ����� ���������������, ����� ����� ��������� ������� �������� ��������� ������� x
    //������������ �������� ���
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
 * ����� ������ � ������� �������� ��������
 */
void mulichevaes::lab2()
{
//��� ��������� ����������� ������ ������.
//���� ������� � ���, ��� �� ��� ������ ����, ������� ������� ���������, ��� ������� �� ����� �������� ���� � ����������� �������,
//������ ���� ������������ �� ������ ����� �� ��������� ����������� �����. ������ ��� ��� ������� ��� ������� ��������� ������ ����������,
// �� � ������ ��� ����� ��������� ������� �� ����
    double t;

    for (int k = 0; k < N; k++)
    {
    //���� ����� ������� ������� ������� �� �'���� ����� �� ���� �������, �� ��������� �� k'��
        int maxel=k;
        for(int i=k+1;i<N;i++)
            if(abs(A[i][k]) > abs(A[maxel][k]))
                maxel=i;
     //�����, ������ ���� �������� k'�� ������� � ������� � ������������ ��������� �������
        for(int i=0;i<N;i++)
            std::swap(A[k][i],A[maxel][i]);
        std::swap(b[k],b[maxel]);


        //� ������ ��� ������ �� ������ ������ �� ���� �� ������������ ����� 1

    //������ ���

        t = A[k][k];

 //����� ��� �������� k'�� ������ �� a[k][k] �������, ������ ��� �� ������������ � �� ����� �� ��� �������� �������� 1
//��� �������� ���������� ����������
        for (int j = 0; j < N; j++)
            A[k][j] = A[k][j] / t;
            b[k] =b[k]/t;

        for (int i = k + 1; i < N; i++)
        {
            t = A[i][k];
   //�������� �� ���� ����� ������� ���� k'�� �'�� ������ ����������� �� k'�� ������� ������,
// �� ������� ��������, ��� ���� ��� ���� � ���� �������� ����� ��������� � ������� ���������� ����������� ����������� ���

            for (int j = 0; j < N; j++)
            {
                A[i][j] =A[i][j]- A[k][j] * t;
            }
            b[i] =b[i]- b[k] * t;
        }
    }

    //������� ������������ ���� ������, ������ ����� ���������������, ����� ����� ��������� ������� �������� ��������� ������� x
    //������������ �������� ���
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
 * ����� ���������
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

        for (int j = 0; j < i; j++) { // ����� ��/ ����� �� ���������
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
 * ����� ��������
 */


void mulichevaes::lab4()
{

//����� �������� - ������� ������ ������ ������.
//������� ����������������
    double *d, *c, *a; // �������, �������, ������ ���������
    d = new double[N];
    c = new double[N];
    a = new double[N];
    double m;

    a[0] = 0;
    d[N-1] = 0;
    for (int i = 0; i < N; ++i)// ���������� ���������
    {
        if (i - 1 >= 0 && i - 1 < N)
            d[i] = A[i-1][i]; //�������
        c[i] = A[i][i];      //�������
        if (i + 1 >= 0 && i + 1 < N)
            a[i] = A[i+1][i]; //������
    }
//���� ������ ��������
    for (int i = 1; i < N; i++) //����������� ����������� ������������
    {
        m = a[i]/c[i-1];
        c[i] = c[i] - m*d[i-1];
        b[i] = b[i] - m*b[i-1];
    }
//���� �������� ��������
    x[N-1] = b[N-1]/c[N-1]; //����������� �������

    for (int i = N - 2; i >= 0; i--) //������� ��� ���������� ������
        x[i]=(b[i]-d[i]*x[i+1])/c[i];

    delete[] b, c, d;
}



/**
 * ����� �����
 */
void mulichevaes::lab5()
{
double eps = 1.e-9;
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
 * ����� �������
 */
void mulichevaes::lab6()
{
double eps = 1.e-9;
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
  return std::string("�������� ���������");
}
