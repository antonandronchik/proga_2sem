#include<iostream>
#include<ctime>

using namespace std;

int** AllocateMemory(int, int, int);
void FillMatrix(int **, int, int, int);
void DisplayMatrix(int **, int, int, int);
int* Sum(int **, int, int, int);
void DisplayArray(int *, int);

int main()
{
	int n, m, k;
	cout << "Please, enter size of matrix : \n";
	cin >> n >> m >> k;

	int** matrix = AllocateMemory(n, m, k);
	FillMatrix(matrix, n, m, k);
	cout << "Matrix\n";
	DisplayMatrix(matrix, n, m, k);

	cout << "Array of sum\n";
	DisplayArray(Sum(matrix, n, m, k), k);

	return 0;
}

int** AllocateMemory(int n, int m, int k)
{
	int** matrix = new int *[k];
	for (int i = 0; i < k; i++)
	{
		matrix[i] = new int[n * m];
		for (int j = 0; j < n; j++)
			for (int l = 0; l < m; l++)
				matrix[i][j * m + l];
	}
	return matrix;
}

void FillMatrix(int **matrix, int n, int m, int k)
{
	srand(time(0));
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			for (int l = 0; l < m; l++)
				matrix[i][j * m + l] = rand() % 100;
}

void DisplayMatrix(int **matrix, int n, int m, int k)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
		{
			for (int l = 0; l < m; l++)
			{
				cout.width(5);
				cout << matrix[i][m * j + l];
			}
			cout << endl;
		}
}

void DisplayArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int* Sum(int **matrix, int n, int m, int k)
{
	int* arr = new int[n * m];
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum = 0;
		for (int j = 0; j < n * m; j++)
			sum += matrix[i][j];
		arr[i] = sum;
	}
	return arr;
}