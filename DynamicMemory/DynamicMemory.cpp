#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


void Allocate(int** arr, const int rows, const int cols); // выделяет память под двумерный динамический массив
void Clear(int** arr, const int rows); // удаляет двумерный динамический массив

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* Push_back(int* arr, int& n, int value);
void Push_row_back(int **&arr, int& rows, const int cols); //добавляет пустую строку в конец двумерного динамического массива

int* Push_front(int* arr, int& n, int value);
void Push_row_front(int **&arr, int& rows, const int cols); //добавляет пустую строку в конец двумерного динамического массива

int* Insert(int* arr, int& n, int value, int index);


int* Pop_back(int* arr, int& n);

int* Pop_front(int* arr, int& n);

int* Erase(int* arr, int& n, int index);

//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2


void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY1
	// Одномерные динамические массивы
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value; // Добавляемое значение в value
	cout << "Введите добавляемое значение массива: "; cin >> value;
	arr = Push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение массива: "; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите добавляемое значение массива: "; cin >> value;
	arr = Insert(arr, n, value, index);
	Print(arr, n);

	arr = Pop_back(arr, n);
	Print(arr, n);
	
	arr = Pop_front(arr, n);
	Print(arr, n);	

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	arr = Erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY1

#ifdef DYNAMIC_MEMORY2
	// Двумерные динамические массивы
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество строк: "; cin >> cols;
	int** arr = new int* [rows];

	Allocate(arr, rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавляет пустую строку в конец двумерного динамического массива: " << endl;
	Push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавляет пустую строку в начало двумерного динамического массива: " << endl;




	Clear(arr, rows);
#endif // DYNAMIC_MEMORY2

}

void Allocate(int** arr, const int rows, const int cols) // выделяет память под двумерный динамический массив
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
}

void Clear(int** arr, const int rows) // удаляет двумерный динамический массив
{
	// 1) Удаляем строки:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	// 2) Удаляем указатели:
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int* Push_back(int* arr, int& n, int value)
{
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
	return arr;
}
void Push_row_back(int **& arr, int& rows, const int cols) //добавляет пустую строку в конец двумерного динамического массива
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[rows] = new int[cols] {};
	rows++;
}

int* Push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	buffer[0] = value;
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}
void Push_row_front(int**& arr, int& rows, const int cols)
{
}

int* Insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	} 
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

int* Pop_back(int* arr, int& n)
{
	/*int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;*/

	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
		delete[] arr;
		return buffer;
}

int* Pop_front(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	return buffer;
}

int* Erase(int* arr, int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index + 1; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;

	return buffer;
}

