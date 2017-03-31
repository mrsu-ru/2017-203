#include "polischukoa.h"

/**
 * ����� ������
 */
void polischukoa::lab1()
{
	double Q = 0;
	int n = N;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            Q = A[j][i] / A[i][i];

            for (int k = i; k < n; k++)
            {
                A[j][k] -= Q * A[i][k];
            }
            b[j] -= Q * b[i];
        }
    }

    for(int i = 0; i < n; i++)
		{
	        x[i] = b[i];
		}

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
				{
					x[i] -= A[i][j] * x[j];
				}

        x[i] /= A[i][i];
	}


}


/**
 * ����� ������ � ������� �������� ��������
 */
void polischukoa::lab2()
{
	double Q = 0;
	int max;

    for (int i = 0; i < N - 1; i++)
    {
				max = i;

				for (int j = i + 1; j < N; j++)
				{
					if(abs(A[j][i]) > abs(A[max][i]))
					{
						max = j;
					}
				}

				std::swap(A[max], A[i]);
		    std::swap(b[max], b[i]);


        for (int j = i + 1; j < N; j++)
        {
            Q = A[j][i] / A[i][i];
            for (int k = i; k < N; k++)
            {
                A[j][k] -= Q * A[i][k];
            }
            b[j] -= Q * b[i];
        }
    }

    for(int i = 0; i < N; i++)
		{
        x[i] = b[i];
		}

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < N; j++)
		{
			x[i] -= A[i][j] * x[j];
		}

        x[i] /= A[i][i];
	}

}



/**
 * ����� ����������� ����� (����� ���������)
 */
void polischukoa::lab3()
{

}



/**
 * ����� ��������
 */
void polischukoa::lab4()
{

}



/**
 * ����� �����
 */
void polischukoa::lab5()
{

}



/**
 * ����� �������
 */
void polischukoa::lab6()
{

}



/**
 * ���� �� ����������� �������
 */
 void polischukoa::lab7()
 {

 }

 void polischukoa::lab8()
 {

 }
