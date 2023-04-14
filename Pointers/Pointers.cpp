#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
    int a = 2;
	int* pa = &a;
	cout << a << endl; // Вывод переменной "а" на экран
	cout << &a << endl; // взятие адреса переменной "а" прямо при выводе
	cout << pa << endl; // вывод адреса переменной а хранящегося в указатели "pa"
	cout << *pa << endl; // разыменование указателя "ра" и вывод на экран значения по адресу
#endif // POINTERS_BASICS
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t";
	}
	cout << endl;
}
 