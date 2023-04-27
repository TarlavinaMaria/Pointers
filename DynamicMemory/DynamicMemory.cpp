#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Push_back(int arr[], int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	Push_back(arr, n);

	
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
	cout << "Введите добавляемое значение: "; cin >> value;
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

	delete[] arr;
}