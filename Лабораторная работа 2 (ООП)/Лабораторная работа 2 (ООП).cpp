// Лабораторная работа 2 (ООП).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MyStack.h"
#include <locale.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUS");
	system("cls");
	cout << "Лабораторная работа №6: Вариант 14" << endl;

	MyStack Stack1 = MyStack(); //Инициализация конструктором по умолчанию
	MyStack Stack2 = MyStack(8); //Инициализация стека2 длиной в 8 элементов через конструктор с параметром

	cout << "Stack1 до добалвения в него элементов: " << endl;
	cout << Stack1 << endl;

	cout << "Stack1 после добавления в него чисел -10, 6, 4, 8, 5: " << endl;
	Stack1.operator>>(-10);
	Stack1.operator>>(6);
	Stack1.operator>>(4);
	Stack1.operator>>(8);
	Stack1.operator>>(5);
	cout << Stack1 << endl;

	cout << "Stack2 после инициализации конструктором с параметром длины 8: " << endl;
	cout << Stack2 << endl;

	//Присвоим стеку2 стек1:
	Stack2.operator=(Stack1);

	cout << "Stack2 после того, как мы присвоили ему Stack1:" << endl;
	cout << Stack2 << endl;

	//Последний элемент стека2:
	cout << "Последний элемент Stack2: " << Stack2.Peek(Stack2.get_Array(), Stack2.get_Length()) << endl;
	cout << endl;

	//Удалим два последних элемента стека2:
	Stack2.operator-();
	Stack2.operator-();
	cout << "Stack2 после удаления из него двух последних элементов: " << endl;
	cout << Stack2 << endl;
	system("pause");
}

