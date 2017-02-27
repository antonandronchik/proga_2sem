#include<iostream>
#include<ctime>
#include<cmath>

using namespace std;

int* AllocateMemory(int);
void FillArray(int *, int);
void DeleteElement(int *,int *, int, int&);
void ChangeArray(int *, int *, int, int);
void DisplayArray(int *, int);
void Swap(int&, int&);
void ChoiceSort(int *, int *, int);
void EnterArray(int *, int);
void PrintArray(int *, int);


int main()
{
	int n, length = 0;
	cout << "Plese, enter length of masive \n";
	while (true)
	{
		cin >> n;
		if (n > 0) break;
		else cout << "Please enter positive size of array\n";
	}

	int *arr = AllocateMemory(n);
	FillArray(arr, n);
	//EnterMass(arr, n);
	cout << "Your array\n";
	DisplayArray(arr, n);

	int *arr2 = AllocateMemory(n);
	DeleteElement(arr, arr2, n, length);
	cout << "\nArray of delete elements\n";
	DisplayArray(arr2, length);
	cout << "\nNew array\n";
	DisplayArray(arr, n - length);
	
	int *arr3 = AllocateMemory(n);
	ChangeArray(arr, arr3, n, length);
	ChoiceSort(arr3, arr, n - length);
	cout << "\nSort array\n";
	PrintArray(arr, n - length);
	cout << endl;
	delete[] arr3;
	delete[] arr2;
	delete[] arr;
	return 0;
}

int* AllocateMemory(int n)
{
	int* arr = new int[n];
		for (int* p = arr; p < arr + n; p++)
	       *p = 0;
	return arr;
}

void EnterArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << (i + 1) << "] = ";
		cin >> arr[i];
	}
}

void FillArray(int *arr, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100 - 40;
}

void PrintArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool flag = true;
		for (int j = i + 1; j < n; j++)
			if (i - j != 0 && arr[i] == arr[j]) flag = false;
		if (flag) cout << arr[i] << " ";
	}
}

void DisplayArray(int *arr,int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void DeleteElement(int *arr, int *arr2, int n, int& lenth)
{
	for (int i = 0; i < n - 1; i++)
	{
		if ((arr[i + 1] < 0) && (arr[i] > 0))
		{
			arr2[lenth] = arr[i + 1];
			lenth++;
			for(int j = i + 1; j < n - lenth; j++)
			arr[j] = arr[j + 1];
		}
	}
}

int Div(int number, int devider)
{
	int quotient;
	quotient = number / devider;
	return quotient;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void ChoiceSort(int *arr2, int *arr, int n) {
	for (int i = 0; i < n - 1; i++) 
	{
		int max = i;
		for (int j = i + 1; j < n; ++j)
			if (arr2[j] > arr2[max]) max = j;
		Swap(arr2[i], arr2[max]);
		Swap(arr[i], arr[max]);
	}
}


void ChangeArray(int *arr, int *arr3, int n, int lenth)
{
	int copy, number;
	for (int i = 0; i < n - lenth; i++)
	{
		int counter = 0;
		copy = arr[i];
		number = arr[i];
		do
		{
			number = fmod(copy, 8);
			copy = Div(copy, 8);
			if (number % 2 == 0)
				counter++;
		} while (copy);
		arr3[i] = counter;
	}
}
