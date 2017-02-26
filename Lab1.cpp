#include<iostream>
#include<ctime>
#include<cmath>

using namespace std;

void FillMass(int *, int);
void DeleteElement(int *,int *, int, int&);
void ChangeMass(int *, int *, int, int);
void DisplayMass(int *, int);
bool True(int);
void Swap(int&, int&);
void ChoiceSort(int *, int *, int);
void EnterMass(int *, int);
void PrintMass(int *, int);


int main()
{
	int n, size = 0;
	cout << "Plese, enter size of masive \n";
	while (true)
	{
		cin >> n;
		if (True(n)) break;
		else cout << "Please enter positive size of massive\n";
	}

	int *mass = new int [n];
	FillMass(mass, n);
	//EnterMass(mass, n);
	cout << "Your massive\n";
	DisplayMass(mass, n);

	int *mass2 = new int[n];
	DeleteElement(mass, mass2, n, size);
	cout << "\nNew massive\n";
	DisplayMass(mass, n - size);
	cout << "\nMassive of delete elements\n";
	DisplayMass(mass2, size);

	int *mass3 = new int[n];
	ChangeMass(mass, mass3, n, size);
	ChoiceSort(mass3, mass, n - size);
	cout << "\nSort massive\n";
	PrintMass(mass, n - size);
	cout << endl;
	delete[] mass3;
	delete[] mass2;
	delete[] mass;
	return 0;
}

void EnterMass(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "mass[" << (i + 1) << "] = ";
		cin >> *(mass + i);
	}
}

bool True(int n)
{
	if (n > 0)
		return true;
	else return false;
}

void FillMass(int *mass, int n)
{
	srand(time(0));
	for (int count = 0; count < n; count++)
		mass[count] = rand() % 100 - 40;
}

void PrintMass(int *mass, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool flag = true;
		for (int j = i + 1; j < n; j++)
			if (i - j != 0 && *(mass + i) == *(mass + j)) flag = false;
		if (flag) cout << *(mass + i) << " ";
	}
}

void DisplayMass(int *mass,int n)
{
	for (int count = 0; count < n; count++)
		cout << *(mass + count) << " ";
}

void DeleteElement(int *mass, int *mass2, int n, int& size)
{
	for (int count = 0; count < n - 1; count++)
	{
		if ((*(mass + count + 1) < 0) && (*(mass + count) > 0))
		{
			*(mass2 + size) = *(mass + count + 1);
			size++;
			for(int i = count + 1; i < n - size; i++)
			*(mass + i) = *(mass + i + 1);
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

void ChoiceSort(int *a, int *b, int n) {
	for (int i = 0; i < n - 1; i++) 
	{
		int max = i;
		for (int j = i + 1; j < n; ++j)
			if (a[j] > a[max]) max = j;
		Swap(a[i], a[max]);
		Swap(b[i], b[max]);
	}
}


void ChangeMass(int *mass, int *mass3, int n, int size)
{
	int copy, number;
	for (int i = 0; i < n - size; i++)
	{
		int counter = 0;
		copy = *(mass + i);
		number = *(mass + i);
		do
		{
			number = fmod(copy, 8);
			copy = Div(copy, 8);
			if (number % 2 == 0)
				counter++;
		} while (copy);
		*(mass3 + i) = counter;
	}
}