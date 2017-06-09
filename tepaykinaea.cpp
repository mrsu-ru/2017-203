/**
 * Метод Гаусса
 */
void tepaykinaea::lab1()
{
    double temp;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            temp=A[j][i]/A[i][i];   //A[i][i] - диагональные эл-ты в столбце, кот. мы рассматриваем; A[j][i] - эл-ты под главн. диагональю
            if (temp!=0) {
                for (int k=N-1; k>=i; k--)
                    A[j][k]-=temp * A[i][k];
                b[j]-=temp*b[i];
            }
        }
    }

    x[N-1] = b[N-1];
    for (int i=N-2; i>=0; i--) {
        x[i] = b[i];
        for (int j=i+1; j<N; ++j)
            x[i]-=x[j] * A[i][j];
        x[i] /= A[i][i];
    }
}

/**
 * Метод Гаусса с выбором главного элемента
 */
void tepaykinaea::lab2()
{
    for (int k=0; k<N; ++k) {
        int str_max_el=-1;
        double max_el=0;
        for (int p=0; p<N; ++p) {
            if (abs(A[k][p]) >= max_el) {
                max_el = abs(A[k][p]);
                str_max_el=p;
            }
        }

        if (str_max_el!=-1) {
            for (int j=0; j<N; ++j) {
                swap(A[j][str_max_el], A[j][k]);
            }
            swap(b[str_max_el], b[k]);

            for (int i=k+1; i<N; ++i)
            {
                double koef = A[i][k]/(A[k][k]*1.0);
                for (int j=k; j<N; ++j)
                    A[i][j] -= koef*A[k][j];
                b[i] -= koef*b[k];
            }
        }
    }

    x[N-1] = b[N-1];
    for (int i=N-2; i>=0; i--) {
        x[i] = b[i];
        for (int j=i+1; j<N; ++j)
            x[i]-=x[j] * A[i][j];
        x[i] /= A[i][i];
    }
}

/**
 * Метод квадратного корня (метод Холецкого)
 */
void tepaykinaea::lab3()
{
	double l[N][N];
    for(int i=0;i<N;i++)
    {for(int j=0;j<N;j++)
        {l[i][j]=0;}
    }
    double s=0; //сумма квадратов
    double y[N];

    for(int i=0;i<N;i++)
    {for(int k=0;k<i;k++)
        {s=s+l[i][k]*l[i][k];}
        l[i][i]=sqrt(A[i][i]-s);
        s=0;
        for(int j=i+1;j<N;j++)
        {for(int k=0;k<j-1;k++)
            {s=s+l[j][k]*l[i][k];}
            l[j][i]=(A[j][i]-s)/l[i][i];
            s=0;
        }
        x[i]=0;
        y[i]=0;
    }

    y[0]=b[0]/l[0][0];
    double sum=0;   //для получения х и у
    for(int i=1;i<N;i++)
    {for(int j=0;j<i;j++)
        {sum=sum+l[i][j]*y[j];}
        y[i]=(b[i]-sum)/l[i][i];
        sum=0;
    }
    x[N-1]=y[N-1]/l[N-1][N-1];

    for(int i=N-2;i>=0;i--)
    {for(int j=i+1;j<N;j++)
        {sum=sum+l[j][i]*x[j];}
        x[i]=(y[i]-sum)/l[i][i];
        sum=0;
    }
}

/**
 * Метод прогонки
 */
void tepaykinaea::lab4()
{
	double *P = new double [N]; //Коэффициенты "альфа"
	double *Q = new double [N]; //Коэффициенты "бетта"

	P[0] = -A[0][1]/A[0][0];
	Q[0] = b[0]/A[0][0];

	for(int i=1; i<N; i++) //Определяем прогоночные коэффициенты
	{
		P[i] = A[i][i+1]/(-A[i][i] - A[i][i-1]*P[i-1]);
		Q[i] = (-b[i] + A[i][i-1]*Q[i-1])/(-A[i][i] - A[i][i-1]*P[i-1]);
	}

	x[N-1] = Q[N-1];
	for(int i=N-2; i>=0; i--) //Определяем решение
		x[i] = P[i]*x[i+1] + Q[i];

	delete [] P;
	delete [] Q;
}

/**
 * Метод Якоби
 */
void tepaykinaea::lab5()
{
    double* px=new double[N];
    double eps=0.000000001;
	double pr=eps;
	for (int i=0; i<N; i++) x[i]=b[i];
    do
      {
		for (int i=0; i<N; i++)
           {
			px[i]=b[i];
			for (int j=0; j<N; j++)
			    if (i!=j)
					px[i]=px[i]-A[i][j]*x[j];
			px[i]=px[i]/A[i][i];
           }
        pr=abs(x[0]-px[0]);

		for (int k=0; k<N; k++)
            {
			 if (abs(x[k]-px[k])>pr)
				pr=abs(x[k]-px[k]);
			x[k]=px[k];
		   }
	 } while(pr>eps);
}

/**
 * Метод Зейделя
 */
void tepaykinaea::lab6()
{
    const double eps=10E-20;

	double* y=new double[N];
	double r=0;     //норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций
	double var=0;

	for (int i=0; i<N; i++)
    {x[i] = 0;}

    do
    {
        for (int i=0; i<N; i++)
            y[i] = x[i];

        for (int i=0; i<N; i++)
        {
            var=0;
            r=0;

            for (int j=0; j<i; j++)
                var += A[i][j]*x[j];

            for (int j=i+1; j<N; j++)
                var += A[i][j]*x[j];

            x[i]=(b[i]-var)/A[i][i];

            for (int i=0; i<N; i++)
				r += sqrt((x[i]-y[i])*(x[i]-y[i]));
		}
    } while (r>=eps);

    delete[] y;
}
