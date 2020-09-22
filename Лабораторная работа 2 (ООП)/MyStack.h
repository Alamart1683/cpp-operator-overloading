#pragma once
#include <iostream>
#include <ostream>
using namespace std;

class MyStack
{
private:
	int* Array;
	int Length;
	int LastElement = 0;

public:
	//Без параметров:
	MyStack()
	{
		Length = 0;
		Array = new int[Length];	
	}
	//С параметрами:
	MyStack(int MS_L)
	{
		Length = MS_L;
		Array = new int[Length];
		for (int i = 0; i < Length; i++)
		{
			Array[i] = 0;
		}
	}
	//Модификация:
	//Set:
	void set_Length(int MS_L)
	{
		Length = MS_L;
	}
	void set_Array(int* MS_A)
	{
		Array = MS_A;
	}
	//Get:
	int get_Length()
	{
		return Length;
	}
	int* get_Array()
	{
		return Array;
	}

	//Методы основного задания:
	//Вернуть значение последнего элемента стека:
	int Peek(int* MyStack_Array,int MyStack_Length)
	{
		if (MyStack_Length == 0)
		{
			cout << "Стек пуст, вывести послдений элемент не представляется возможным!" << endl;
		}
		else
		{
			return MyStack_Array[MyStack_Length - 1];
		}
	}
	//Вернуть количество элементов стека:
	int CountOfElements(int MyStack_Length)
	{
		return MyStack_Length - 1;
	}

	//Прототипы методов дополнительного задания:
	//Добавить в конец стека:
	MyStack& operator >>(int Value);
	//Удалить из конца стека:
	MyStack& operator -();
	//Присваивание:
	MyStack& operator =(MyStack &MyStackForAssignment);
	//Перегрузка osrtream:
	friend ostream& operator<<(ostream& os, MyStack &MS);
	//Деструктор:
	~MyStack()
	{

	}
};

