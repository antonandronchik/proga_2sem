#include <iostream>
#include <string.h>

using namespace std;

char** ObtainWords(char* str, int& k);
void Swap(char* &a, char* &b);
void DisplayWords(char** words, int n);
void SortingWords(char** words, int n);

int main()
{
	int k = 0;
	char *str = "You can use the .NET Compiler Platform (Roslyn) to write your own code analyzers and code generators";
	char **words = ObtainWords(str, k);
	DisplayWords(words, k);
	SortingWords(words, k);
	cout << endl;
	cout << "Sort words : \n";
	DisplayWords(words, k);
	return 0;
}

void Swap(char* &a, char* &b)
{
	char *temp = a;
	a = b;
	b = temp;
}

int** AllocateMemory(int n, int* arr)
{
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[arr[i]];
		for (int j = 0; j < arr[i]; j++)
			matrix[i][j] = 0;
	}
	return matrix;
}


char** ObtainWords(char* str, int& k)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char** words = new char*[strlen(str)];
	char* pword = strpbrk(str, symbols);
	while (pword)
	{
		int length = strspn(pword, symbols);
		words[k] = new char[length + 1];
		strncpy(words[k], pword, length);
		words[k][length] = '\0';
		pword += length;
		pword = strpbrk(pword, symbols);
		k++;
	}
	return words;
}

char** ObtainWords(char* str, int& k)
{
	char* s = new char[strlen(str) + 1];
	strcpy(s, str);
	char** words = new char*[strlen(str) / 2];
	char* symbols = " (!+$*!204812 )$!($!$<>><>.,//123:;";
	char* pword = strtok(s, symbols);
	words[k] = new char[strlen(pword) + 1];
	strcpy(words[k], pword);
	k++;
	while (pword)
	{
		pword = strtok('\0', symbols);
		if (pword) {
			words[k] = new char[strlen(pword) + 1];
			strcpy(words[k], pword);
			k++;
		}
	}
	delete[] s;
	return words;
}

void SortingWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > 0; j--)
			//if (strlen(words[j]) < strlen(words[j - 1]))
			if (strcmp(words[j], words[j - 1]) < 0)
				Swap(words[j], words[j - 1]);
	}
}

void DisplayWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; words[i][j] != '\0'; j++)
			cout << words[i][j];
		cout << endl;
	}
}
