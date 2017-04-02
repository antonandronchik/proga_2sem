#include<iostream>

using namespace std;

double** AllocateMamory(int);
void DeleteMemory(double **, int);
double **CreateMatrixA(int, double);
double **CreateMatrixB(int);
double CreateElemA(int, int, double);
double CreateElemB(int, int);
double Sin(double, double);
void DisplayMatrix(double **, int);
double normaMatix(double **, int);

int main()
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
	cout << "Matrix A\n";
	DisplayMatrix(matrixA, n);
	cout << endl;

	double **matrixB = CreateMatrixB(n);
	cout << "Matrix B\n";
	DisplayMatrix(matrixB, n);

	cout << "Norma of matrix A : "<< normaMatix(matrixA, n) << endl;

	cout << "Norma of matrix B : " << normaMatix(matrixB, n) << endl;

	DeleteMemory(matrixA, n);
	DeleteMemory(matrixB, n);

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
	for (int i = 1; fabs(term) > eps; i++)
	{
		sum += term;
		term *= -x * x / (2 * i * (2 * i + 1));
	}
	return sum;
}

void DisplayMatrix(double **matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%10.5f", matrix[i][j]);
		cout << endl;
	}
}

double normaMatix(double** matrix, int n) {
	double maxsum = 0.0, sum = 0.0;
	bool flag = true;
	for (int i = 0; i < n; i++) 
	{
		if (flag) 
		{
			flag = false;
			for (int j = 0; j < n; j++)
				maxsum += fabs(matrix[i][j]);
		}

		if (maxsum < sum)
			maxsum = sum;
	}

	return maxsum;
}