#include "gorbylevako.h"

/**
 * Метод Гаусса
 */
void gorbylevako::lab1()
{
    double p;
    for(int k=0; k<N; k++)
        for(int i=k+1; i<N; i++)
        {
            p = A[i][k]/A[k][k];
            for(int j=0; j<N; j++)
                A[i][j] -= A[k][j]*p;
            b[i] -= b[k]*p;
        }

    for(int i = 0; i<N; i++)
    {
        x[i]=b[i];
    }

    for (int i=N-1; i>=0; i--)
    {
        for (int j=i+1;j<N;j++)
            x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void gorbylevako::lab2()
{
    double p;
	int maxn;

    for (int k=0; k<N-1; k++)
    {
        maxn = k;
        for (int i=k+1; i<N; i++)
			if(abs(A[i][k]) > abs(A[maxn][k])) maxn = i; ///Выбор главного элемента
        std::swap(A[maxn], A[k]); ///Меняем строки местами
        std::swap(b[maxn], b[k]);

        for (int i=k+1; i<N; i++)
        {
            p = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
                A[i][j] -= p*A[k][j];
            b[i] -= p*b[k];
        }
    }

    for(int i = 0; i<N; i++)
    {
        x[i]=b[i];
    }

    for (int i=N-1; i>=0; i--)
    {
        for (int j=i+1;j<N;j++)
            x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void gorbylevako::lab3()
{
	double **S = new double *[N];
	for (int i = 0; i < N; i++)
		S[i] = new double [N];

	double *y = new double [N];


	for (int i = 0; i < N; i++)
	{
		x[i] = 0;
		y[i] = 0;
		for (int j = 0; j < N; j++)
		{
			S[i][j] = 0;
		}
	}

	double t = 0;
	for (int i = 0; i < N; i++)  ///Вычисляем нижнетреугольную матрицу S
	{
		for (int k = 0; k <= i-1; k++)
			t += S[i][k]*S[i][k];

		S[i][i] = sqrt(A[i][i] - t);
		t = 0;
		for (int j = i + 1; j < N; j++)
			{
				for (int k = 0; k <= i-1; k++)
					t += S[i][k]*S[j][k];

				S[j][i] = (A[i][j] - t)/S[i][i];
				t = 0;
			}
	}


	for (int i = 0; i < N; i++) ///Нахождение y[i] "обратным ходом" метода Гаусса
	{
		t = 0;
		for (int j = 0; j < i; j++)
			t += S[i][j]*y[j];

		y[i] = (b[i] - t)/S[i][i];
	}


	for (int i = N-1; i >= 0; i--) ///Нахождение х[i] "обратным ходом" метода Гаусса
	{
		t = 0;
		for (int j = i + 1; j < N; j++)
			t += S[j][i]*x[j];

		x[i] = (y[i] - t)/S[i][i];
	}

    delete[] y;
	for (int i = 0; i < N; i++)
		delete[] S[i];
	delete[] S;
}



/**
 * Метод прогонки
 */
void gorbylevako::lab4()
{
	double *P = new double [N]; ///Коэффициенты "альфа"
	double *Q = new double [N]; ///Коэффициенты "бетта"

	P[0] = -A[0][1]/A[0][0];
	Q[0] = b[0]/A[0][0];

	for(int i=1; i<N; i++) ///Определяем прогоночные коэффициенты
	{
		P[i] = A[i][i+1]/(-A[i][i] - A[i][i-1]*P[i-1]);
		Q[i] = (-b[i] + A[i][i-1]*Q[i-1])/(-A[i][i] - A[i][i-1]*P[i-1]);
	}

	x[N-1] = Q[N-1];
	for(int i=N-2; i>=0; i--) ///Определяем решение
		x[i] = P[i]*x[i+1] + Q[i];

	delete [] P;
	delete [] Q;
}



/**
 * Метод Якоби
 */
void gorbylevako::lab5()
{
    const double eps = 10E-20;

	double* y = new double[N];
	double r = 0; /// норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций.

	for(int i=0; i<N; i++)
	{
		x[i] = 0;
	}

	do
	{
		for(int i=0; i<N; i++)
		{
			y[i] = b[i];
			for(int j=0; j<N; j++)
			{
				if(i != j)
				{
					y[i] -= A[i][j]*x[j];
				}
			}
			y[i] /= A[i][i];
		}

		r = abs(x[0] - y[0]);

		for(int i=0; i<N; i++)
		{
			if(abs(x[i]-y[i]) > r)
				r = sqrt((x[i]-y[i])*(x[i]-y[i]));
			x[i] = y[i];
		}
	} while(r >= eps);
	delete[] y;
}



/**
 * Метод Зейделя
 */
void gorbylevako::lab6()
{
    const double eps = 10E-20;

	double* y = new double[N];
	double r = 0; /// норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций.
	double var = 0;

	for(int i=0; i<N; i++)
    {
        x[i] = 0;
    }

    do
    {
        for(int i=0; i<N; i++)
            y[i] = x[i];

        for(int i=0; i<N; i++)
        {
            var = 0;
            r = 0;

            for(int j=0; j<i; j++)
                var += A[i][j]*x[j];

            for(int j=i+1; j<N; j++)
                var += A[i][j]*x[j];

            x[i] = (b[i]-var)/A[i][i];

            for(int i=0; i<N; i++)
				r += sqrt((x[i]-y[i])*(x[i]-y[i]));
		}
    } while(r >= eps);

    delete[] y;
}



/**
 * Один из градиентных методов
 */
void gorbylevako::MatrVect(double **M, double *V, double *R)
{
    for(int i=0; i<N; i++)
    {
        R[i]=0;
        for(int j=0; j<N; j++)
              R[i]+= M[i][j]*V[j];
    }
}

double gorbylevako::ScalarVect(double* v1, double* v2)
{
	double result=0;
	for (int i=0; i<N; i++)
        result+=(v1[i]*v2[i]);
	return result;
}

void gorbylevako::lab7()
{
    const double eps = 10E-20;

    int count = 0; ///  количество итераций
    double *U = new double [N];
    double *r = new double [N];
    double *TempX = new double[N];
    double p = 0.0, Tau = 0.0;

    for (int i=0; i<N; i++)
        TempX[i]=0; /// первое приближение задаём нулевым

    do
    {
        MatrVect(A, TempX, U);

        for(int i=0; i<N; i++)
        {
            r[i] = U[i]-b[i]; /// Вектор невязок
        }

        MatrVect(A, r, U);

        double TempTau1 = ScalarVect(U, r);
        double TempTau2 = ScalarVect(U, U);
        if (TempTau2 == 0) break;

        Tau = TempTau1/TempTau2; /// Итерационный параметр

        for(int i=0; i<N; i++)
            x[i] = TempX[i]-Tau*r[i];

        p = fabs(x[0]-TempX[0]);

        for(int i=0; i<N; i++)
        {
            if(fabs(x[i]-TempX[i]) > p)
                p = fabs(x[i]-TempX[i]);
            TempX[i] = x[i];
        }
        count++;
    } while (p >= eps);

    delete[] U;
    delete[] r;
    delete[] TempX;
}

/**
 * Один из градиентных методов
 */
void gorbylevako::lab8()
{

}
