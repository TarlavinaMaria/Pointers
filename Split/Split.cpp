#include<iostream>
#include <string>
#include <iomanip>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Split(int arr[], const int n);


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];
	
	FillRand(arr, n);
	Print(arr, n);
	Split(arr, n);
	
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Split(int arr[], const int n)
{
	int* odd = new int[n];
	int* even = new int[n];
	int oddcnt = 0;
	int evencnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2)
		{
			odd[oddcnt++] = arr[i];
		}
		else
		{
			even[evencnt++] = arr[i];
		}
	}
	cout << "odd:" << *odd << endl;
	cout << "even:" << *even << endl;

	delete[] odd;
	delete[] even;
}
