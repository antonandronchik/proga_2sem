#include<iostream>
#include<ctime>

using namespace std;

int** AllocateMamory(int);
void DeleteMemory(int **, int);
void FillMatrix(int **, int);
void DisplayMatrix(int **, int);
void CreateMatrix(int **, int **, int);
void searchInColumn(int&, int, int, int **);
int FindMax(int **, int, int, int);

int main()
{
	int n = 0;
	while (true)
	{
		cout << "Please, enter size of matrix : ";
		cin >> n;
		if (n > 0) break;
	}

	int** matrixA = AllocateMamory(n);
	FillMatrix(matrixA, n);
	cout << "Matrix A : \n";
	DisplayMatrix(matrixA, n);
	cout << endl;

	int** matrixB = AllocateMamory(n);
	CreateMatrix(matrixB, matrixA, n);
	cout << "Matrix B : \n";
	DisplayMatrix(matrixB, n);

	DeleteMemory(matrixA, n);
	DeleteMemory(matrixB, n);

	return 0;
}

int** AllocateMamory(int n)
{
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];
	return matrix;
}

void DeleteMemory(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete matrix;
}

void FillMatrix(int** matrix, int n)
{
	srand(time(0));
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = rand() % 100 - 35;
}

void DisplayMatrix(int **matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%6.0i", matrix[i][j]);
		cout << endl;
	}
}

void CreateMatrix(int **matrix, int **firstMatrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = FindMax(firstMatrix, i, j, n);
}

int FindMax(int **matrix, int i, int j, int n)
{

	int max = matrix[i][j];

	int i1 = i, j1 = j;
	for (; (j1 >= 0) && (i1 >= 0); i1--, j1--)
		searchInColumn(max, i1, j1, matrix);

	i1 = i, j1 = j;
	for (; (j1 < n) && (i1 >= 0); i1--, j1++)
		searchInColumn(max, i1, j1, matrix);

	return max;
}

void searchInColumn(int& max, int i, int j, int** matrix)
{
	for (int k = i; k >= 0; k--)
		if (matrix[k][j] > max)
			max = matrix[k][j];
}
