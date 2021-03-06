#include<iostream>
#include<math.h>
#define M_PI       3.14159265358979323846

using namespace std;

double** AllocateMamory(int);
void DeleteMemory(double **, int);
double **CreateMatrixA(int, double);
double **CreateMatrixB(int);
double CreateElemA(int, int, double);
double CreateElemB(int, int);
double Sin(double, double);
double normaMatix(double **, int);
double func(double x);

int main()
{
	while (true)
	{
		int n;
		while (true)
		{
			cout << "Please, enter size of matrix : ";
			cin >> n;
			if (n > 0) break;
		}

		double eps;
		while (true)
		{
			cout << "Please, enter accuracy(eps) : ";
			cin >> eps;
			if (eps > 0 && eps < 1) break;
		}

		double **matrixA = CreateMatrixA(n, eps);

		double **matrixB = CreateMatrixB(n);

		cout << "Norma of matrix A : " << normaMatix(matrixA, n) << endl;

		cout << "Norma of matrix B : " << normaMatix(matrixB, n) << endl;

		DeleteMemory(matrixA, n);
		DeleteMemory(matrixB, n);

	}

	return 0;
}

double** AllocateMamory(int n)
{
	double** matrix = new double*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[n];
	return matrix;
}

void DeleteMemory(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete matrix;
}


double **CreateMatrixA(int n, double eps)
{
	double** matrix = AllocateMamory(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = CreateElemA(i, j, eps);
	return matrix;
}

double **CreateMatrixB(int n)
{
	double** matrix = AllocateMamory(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = CreateElemB(i, j);
	return matrix;
}

double CreateElemA(int i, int j, double eps)
{
	if (i == j)
		return 1.0;
	else return (Sin((double)(i + j), eps) - Sin((double)(i - j), eps)) / pow((i + j + 1), 2);
}

double CreateElemB(int i, int j)
{
	if (i == j)
		return 1.0;
	else return (sin((double)(i + j)) - sin((double)(i - j))) / pow((i + j + 1), 2);
}

double Sin(double x, double eps)
{
	double term = x, sum = 0.0;
	if (fabs(x) < 2 * M_PI)
	{
		for (int i = 1; fabs(term) > eps; i++)
		{
			sum += term;
			term *= -x * x / (2 * i * (2 * i + 1));
		}
	}
	else func(x);
	return sum;
}

double func(double x)
{
	while (fabs(x) < 2 * M_PI)
	{
		x /= 2 * M_PI;
	}
	return x;
}

double normaMatix(double** matrix, int n) {
	double maxsum = 0.0, sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum = 0.0;
		for (int j = 0; j < n; j++)
			sum += fabs(matrix[i][j]);

		if (maxsum < sum)
			maxsum = sum;

	}

	return maxsum;
}
