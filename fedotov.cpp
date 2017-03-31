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
		for (int k = i + 1; k < N; i++)
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
	}
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void fedotov::lab3()
{

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
 */
void fedotov::lab5()
{

}



/**
 * Метод Зейделя
 */
void fedotov::lab6()
{

}



/**
 * Один из градиентных методов
 */
void fedotov::lab7()
{

}



std::string fedotov::get_name()
{
	return std::string("Федотов Владимир");
}