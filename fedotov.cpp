#include "fedotov.h"

/**
 * Метод Гаусса
 */
void fedotov::lab1()
{
	/*прямой ход*/
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i][j] /= A[i][i];
		}
		b[i] /= A[i][i];
		for (int k = i+1; k < N; k++)
		{
			for (int z = 0; z < N; z++)
			{
				A[k][z] -= A[i][z] * A[k][i];
			}
			b[k] -= b[i] * A[k][i];
		}
	}

	/*обратный ход*/
	for (int j = N - 1; j > 0; j--)
	{
		for (int i = j - 1; i >= 0; i--)
		{
			b[i] -= b[j] * A[i][j];
			x[i] = b[i];
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
	for (int i = 0; i < N; i++)
	{
		int maxel = i;
		for (int k = i + 1; k<N; i++)
			if (abs(A[k][i]) > abs(A[maxel][i]))
				maxel = k;
		for (int k = 0; k < N; k++)
			std::swap(A[i][k], A[maxel][k]);
		std::swap(b[i], b[maxel]);

		for (int j = 0; j < N; j++)
		{
			A[i][j] /= A[i][i];
			b[k] /= A[i][i];
		}
		for (int k = i + 1; k < N; k++)
		{
			for (int z = 0; z < N; z++)
			{
				A[k][z] -= A[i][z] * A[k][i];
			}
			b[k] -= b[i] * A[k][i];
		}
	}

	/*обратный ход*/
	for (int j = N - 1; j > 0; j--)
	{
		for (int i = j - 1; i >= 0; i--)
		{
			b[i] -= b[j] * A[i][j];
			x[i] = b[i];
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
 */
void fedotov::lab4()
{

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
