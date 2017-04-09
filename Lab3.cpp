#include<iostream>
#include<ctime>

using namespace std;

int** AllocateMamory(int);
void DeleteMemory(int **, int);
void FillMatrix(int **, int);
void DisplayMatrix(int **, int);
void CreateMatrix(int **, int **, int);
int FindMax(int **, int, int, int);

int main()
{
	int n = 5;
	cout << "Please, enter size of matrix : ";
	cin >> n;

	int** matrixA = AllocateMamory(n);
	FillMatrix(matrixA, n);
	cout << "Matrix A : \n";
	DisplayMatrix(matrixA, n);
	cout << endl;

	int** matrixB = AllocateMamory(n);
	CreateMatrix(matrixB, matrixA, n);
	cout << "Matrix B : \n";
	DisplayMatrix(matrixB, n);
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
			matrix[i][j] = rand() % 100;
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
	int left = j - 1, right = j + 1;

	for (int k = i; k >= 0; k--)
		if (matrix[k][j] > max)
			max = matrix[k][j];

	int copy = i;
	while (left >= 0)
	{
		for (int k = 0; k < i; k++)
		{
			if (matrix[k][left] > max)
				max = matrix[k][left];
		}
		left--;
		copy--;
	}

	while (right < n)
	{
		for (int k = 0; k < i; k++)
		{
			if (matrix[k][right] > max)
				max = matrix[k][right];
		}
		right++;
		i--;
	}
	return max;
}