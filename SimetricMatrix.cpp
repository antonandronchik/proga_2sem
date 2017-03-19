#include<iostream>
#include<ctime>

using namespace std;

void FillMatrix(int **, int);
void DisplayMatrix(int **, int);

int main()
{
	int n;
	cout << "Please, enter size of matrix\n";
	cin >> n;
	int **matrix = new int *[n];

	for (int i = 0; i < n; i++) {
		matrix[i] = new int[i + 1]();
	}

	FillMatrix(matrix, n);
	DisplayMatrix(matrix, n);

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}

void FillMatrix(int **matrix, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
		{
			matrix[j][i] = rand() % 100;
			matrix[i][j] = matrix[j][i];
		}
}

void DisplayMatrix(int **matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(5);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}