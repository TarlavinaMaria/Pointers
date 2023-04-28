#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Push_back(int arr[], int n);
void Push_front(int arr[], int n);
void Insert(int arr[], int n);
void Pop_back(int arr[], int n);
void Pop_front(int arr[], int n);


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	//Push_back(arr, n);
	//Push_front(arr, n);
	//Insert(arr, n);
	//Pop_back(arr, n);
	Pop_front(arr, n);


	
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

void Push_back(int arr[], int n)
{
	int value; // Добавляемое значение в value
	cout << "Введите добавляемое значение в конец массива: "; cin >> value;
	// 1) Создаем буферный массив нужного размера (на 1 элемент больше)
	int* buffer = new int[n + 1];
	// 2) Копируем все значения с исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) Удаляем исходный массив:
	delete[] arr;
	// 4) Изменяем адрес исходного массива адресом нового массива:
	arr = buffer;
	buffer = nullptr; // Null-pointer (указатель на 0)
	// 5) И только после этого в массив "arr" можно добавить значение:
	arr[n] = value;
	// 6) После добавления элемента в массив кол-во его элементов увеличивается на 1:
	n++;
	// 7) Mission complete - элемент добавлен
	Print(arr, n);
	
	delete [] arr;
}

void Push_front(int arr[], int n)
{
	int value;
	cout << "Введите добавляемое значение в начало массива: "; cin >> value;
	int* buffer = new int[n + 2];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr; 

	int number = 1;
	for (int i = 0; i < number; i++)
	{
		int Buffer = arr[n-1];
		for (int i = n-1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = Buffer;
	}
	arr[0] = value;


	Print(arr, n);

	delete[] arr;
}

void Insert(int arr[], int n)
{
	int value;
	int number;
	cout << "Введите добавляемое значение в массива: "; cin >> value;
	cout << "Введите индекс: "; cin >> number;
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;

	// C костылями
	switch (number)
	{
	case (1): arr[0] = value; break;
	case (2): arr[n-4] = value; break;
	case (3): arr[n-3] = value; break;
	case (4): arr[n-2] = value; break;
	case (5): arr[n] = value; break;
	}
	

	Print(arr, n);

	delete[] arr;
}

void Pop_back(int arr[], int n)
{
	n--;
	Print(arr, n);
}

void Pop_front(int arr[], int n)
{

}