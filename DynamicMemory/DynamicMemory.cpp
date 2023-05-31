﻿#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------------------------------------------------------------------------------\n"

template<typename T> T** Allocate(const int rows, const int cols); // выделяет память под двумерный динамический массив
template<typename T> void Clear(T** arr, const int rows); // удаляет двумерный динамический массив

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);

void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);

template<typename T> void Print(T arr[], const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

template<typename T> T* Push_back(T* arr, int& n, T value);
template<typename T> T** Push_row_back(T** arr, int& rows, const int cols); //добавляет пустую строку в конец двумерного динамического массива
template<typename T> void Push_col_back(T** arr,const int rows,  int& cols); //добавляет пустой столбец в конец двумерного динамического массива

template<typename T> T* Push_front(T* arr, int& n, T value);
template<typename T> T** Push_row_front(T** arr, int& rows, const int cols); //добавляет пустую строку в начало двумерного динамического массива
template<typename T> void Push_col_front(T** arr, const int rows, int& cols); //добавляет пустой столбец в начало двумерного динамического массива

template<typename T> T* Insert(T* arr, int& n, T value, int index);
template<typename T> T** Insert_row(T** arr, int& rows, const int cols, int index);  //вставляет пустую строку в двумерный динамический массив по заданному индексу
template<typename T> void Insert_col(T** arr, const int rows, int& cols, int index); //вставляет пустой столбец в двумерный динамический массив по заданному индексу

template<typename T> T* Pop_back(T* arr, int& n);
template<typename T> T** Pop_row_back(T** arr, int& rows, const int cols); //удаляет последнюю строку двумерного динамического массива
template<typename T> void Pop_col_back(T** arr, const int rows, int& cols); //удаляет столбец с конца двумерного динамического массива

template<typename T> T* Pop_front(T* arr, int& n);
template<typename T> T** Pop_row_front(T** arr, int& rows, const int cols); //удаляет нулевую строку двумерного динамического массива
template<typename T> void Pop_col_front(T** arr, const int rows, int& cols); //удаляет столбец с начала двумерного динамического массива

template<typename T> T* Erase(T* arr, int& n, int index);
template<typename T> void Erase_row(T**& arr, int& rows, const int cols, int index); //удаляет строку из двумерного динамического массива по заданному индексу
template<typename T> void Erase_cols(T** arr, const int rows, int& cols, int index); //удаляет столбец из двумерного динамического массива по заданному индексу

//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2

	typedef double DataType;

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY1
	// Одномерные динамические массивы
	int n;
	cout << "Введите размер массива: "; cin >> n;
	DataType* arr = new DataType[n];
	
	FillRand(arr, n);
	Print(arr, n);

	DataType value; // Добавляемое значение в value
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
	cout << "Введите количество столбцов: "; cin >> cols;
	int** arr = Allocate<int>(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	

	////Вывод при помощи арифметики указателей
	//cout << "Вывод при помощи арифметики указателей" << endl;
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++)
	//	{
	//		cout << *(*(arr + i) + j) << "\t";
	//	}
	//	cout << endl;
	//}
	//cout << delimiter << endl;

	cout << "Добавляет пустую строку в конец двумерного динамического массива: " << endl;
	arr = Push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	cout << "Добавляет пустую строку в начало двумерного динамического массива: " << endl;
	arr = Push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	int index;
	cout << "Введите индекс добавляемой строки: "; cin >> index;
	arr = Insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	cout << "Удаляет последнюю строку  двумерного динамического массива: " << endl;
	arr = Pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	cout << "Удаляет нулевую строку  двумерного динамического массива: " << endl;
	arr = Pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	cout << "Введите индекс удаляемой строки: "; cin >> index;
	Erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	cout << "Добавляет пустой столбец в конец двумерного динамического массива: " << endl;
	Push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	cout << "Добавляет пустой столбец в начало двумерного динамического массива: " << endl;
	Push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	int index;
	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	Insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	cout << "Удаляет столбец с конца двумерного динамического массива: " << endl;
	Pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	
	cout << "Удаляет столбец с начала двумерного динамического массива: " << endl;
	Pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	cout << "Введите индекс удаляемой столца: "; cin >> index;
	Erase_cols(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimiter << endl;


	Clear(arr, rows);
#endif // DYNAMIC_MEMORY2

}

template<typename T> T** Allocate(const int rows, const int cols) // выделяет память под двумерный динамический массив
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}

template<typename T> void Clear(T** arr, const int rows) // удаляет двумерный динамический массив
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
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 10000;
		arr[i] /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand();
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
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = (rand() % 100)/10;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}

template<typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T> void Print(T** arr, const int rows, const int cols)
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

template<typename T> T* Push_back(T* arr, int& n, T value)
{
	// 1) Создаем буферный массив нужного размера (на 1 элемент больше)
	T* buffer = new T[n + 1];
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
template<typename T> T** Push_row_back(T** arr, int& rows, const int cols) //добавляет пустую строку в конец двумерного динамического массива
{
	return Push_back(arr, rows, new T[cols]{}); // Функция Push_back переопределяет массив указателей
}
template<typename T> void Push_col_back(T** arr, const int rows, int& cols) //добавляет пустой столбец в конец двумерного динамического массива
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = Pop_back(arr[i], cols);
		cols++;
	}
	 cols--;
}

template<typename T> T* Push_front(T* arr, int& n, T value)
{
	T* buffer = new T[n + 1];
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
template<typename T> T** Push_row_front(T** arr, int& rows, const int cols) //добавляет пустую строку в начало двумерного динамического массива
{
	return Push_front(arr, rows, new T[cols]{});
}
template<typename T>void Push_col_front(T** arr, const int rows, int& cols) //добавляет пустой столбец в начало двумерного динамического массива
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = Push_front(arr[i], cols, T());
		cols--; // компенсируем увеличение на один столбец
	}
	cols++;
}

template<typename T> T* Insert(T* arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1];
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
template<typename T> T** Insert_row(T** arr, int& rows, const int cols, int index) //вставляет строку из двумерного динамического массива по заданному индексу
{
	return Insert(arr, rows, new T[cols]{}, index);
}
template<typename T> void Insert_col(T** arr, const int rows, int& cols, int index) //вставляет пустой столбец в двумерный динамический массив по заданному индексу
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = Insert(arr[i], cols, index);
		cols++;
	}
	cols--;
}

template<typename T> T* Pop_back(T* arr, int& n)
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

	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
		delete[] arr;
		return buffer;
}
template<typename T> T** Pop_row_back(T** arr, int& rows, const int cols) //удаляет последнюю строку двумерного динамического массива
{
	// 1) Удаляем удаляемую строку:
	delete[] arr[rows - 1];
	// 2)Переопределяем массив указателей:
	return Pop_back(arr, rows);
}
template<typename T> void Pop_col_back(T** arr, const int rows, int& cols) //удаляет столбец с конца двумерного динамического массива
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = Pop_back(arr[i], cols);
		cols++;
	}
	cols--;
}

template<typename T> T* Pop_front(T* arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	return buffer;
}
template<typename T> T** Pop_row_front(T** arr, int& rows, const int cols) //удаляет нулевую строку двумерного динамического массива
{
	delete[] arr[0];
	return Pop_front(arr, rows);
}
template<typename T> void Pop_col_front(T** arr, const int rows, int& cols) //удаляет столбец с начала двумерного динамического массива
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = Pop_front(arr[i], cols);
		cols++;
	}
	cols--;
}

template<typename T> T* Erase(T* arr, int& n, int index)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T> void Erase_row(T**& arr, int& rows, const int cols, int index) //удаляет строку из двумерного динамического массива по заданному индексу
{
	int** buffer = new T* [rows --];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T> void Erase_cols(T** arr, const int rows, int& cols, int index) //удаляет столбец из двумерного динамического массива по заданному индексу
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1] {};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols-1; j++)
		{
			buffer[j] = arr[i][j+1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}