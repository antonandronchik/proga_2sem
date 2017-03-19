#include <iostream>
#include <ctime>

using namespace std;

int sum(int *, int);
int **allocateMemory(int, int *);
void DisplayMatrix(int **, int, int *);
void FillMatrix(int **, int, int *);
void swap(int *&p, int *&q);
int *SumArray(int **, int, int *);
void SortBySumRows(int **, int, int *, int *);

int main(int argc, const char * argv[])
{
	
	int n;
	cout << "Please, enter length of array : ";
	cin >> n;

	int *m = new int[n];
	for (int i = 0; i < n; i++)
		m[i] = i + 1;

	int **matrix = allocateMemory(n, m);
	
	FillMatrix(matrix, n, m);
	cout << "Your matrix\n";
	DisplayMatrix(matrix, n, m);
	int *sumarr = SumArray(matrix, n, m);

	SortBySumRows(matrix, n, sumarr, m);
	cout << endl;
	cout << "Sort matrix by sum in rows\n";
	DisplayMatrix(matrix, n, m);
	cout << endl;

	return 0;
}

void FillMatrix(int **matrix, int n, int *arr)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < arr[i]; j++)
			matrix[i][j] = (rand() % 100) - 40;
}

void DisplayMatrix(int **matrix, int n, int *arr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			cout.width(5);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

int **allocateMemory(int n, int *arr)
{
	int **matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[arr[i]];
	return matrix;
}

int sum(int *matr, int M)
{
	int sum = 0;
	for (int i = 0; i < M; i++)
		sum += matr[i];
	return sum;
}

int *SumArray(int **matrix, int n, int *m)
{
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = sum(matrix[i], m[i]);
	}
	return arr;
}

void swap(int * &a, int * &b)
{
	int *temp = a;
	a = b;
	b = temp;
}

void SortBySumRows(int **matrix, int n, int *d, int *m)
{
	for (int i = 1; i<n; i++)
		for (int j = n - 1; j >= i; j--)
			if (d[j] < d[j - 1])
			{
				swap(d[j], d[j - 1]);
				swap(matrix[j], matrix[j - 1]);
				swap(m[j], m[j - 1]);
			}
	delete[] d;
}