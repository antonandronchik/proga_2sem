#include <iostream>
#include <cstring>

using namespace std;

void Swap(char&, char&);
char NumberToChar(int);
int Div(int, int);
void Reverse(char*, int);
void ConvertIntPart(char *, int, int, int &);
void ConvertDoublePart(char *, double, int, int, int);

int main()
{
	double number;
	bool flag = false;
	int posPoint = 0;

	char strNum[64] = { '0' };
	cout << "Please, enter number : ";
	cin >> number;

	if (number < 0) {
		flag = true;
		number = fabs(number);
	}

	int notation;
	cout << "Please, enter notation to convert : ";
	cin >> notation;

	int k;
	cout << "Please, enter number of digits after \".\" k : ";
	cin >> k;
	
	ConvertIntPart(strNum, number, notation, posPoint);
	strNum[posPoint++] = '.';
	ConvertDoublePart(strNum, number, notation, posPoint, k);

	if (flag)
		cout << "Your number in new notation is : -" << strNum << endl;
	else
		cout << "Your number in new notation is : " << strNum << endl;
	return 0;
}

void Swap(char& a, char& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Reverse(char* a, int n)
{
	for (int i = 0; i < n / 2; i++)
		Swap(a[i], a[n - i - 1]);
}

char NumberToChar(int number)
{
	if (number >= 0 && number <= 9)
		return 48 + number;
	else if (number >= 10 && number <= 35)
		return 55 + number;
	return 0;
}

int Div(int number, int devider)
{
	int quotient;
	quotient = number / devider;
	return quotient;
}

void ConvertIntPart(char *strNum, int number, int base, int &i)
{
	int rem = 0;
	int copy = (int)number;
	do {	
		rem = fmod(copy, base);
		copy = Div(copy, base);
		strNum[i] = NumberToChar(rem);
		i++;
	} while (copy);
	Reverse(strNum, strlen(strNum));
}

void ConvertDoublePart(char *strNum, double number, int base, int pos, int k)
{
	double copy = number - (int)number;
	int i = 0;
	while (i < k) 
	{
		copy = copy * base;
		int digit = (int)(copy);
		strNum[pos++] = NumberToChar(digit);
		copy -= (int)copy;
		i++;
	}
}