#include "stdafx.h"
#include "MyStack.h"

//Методы дополнительного задания:
//Добавить в конец стека:
MyStack& MyStack::operator >>(int Value)
{
	//Если стек пуст, выделить память под первый элемент:
	if (this->Length == 0)
	{
		this->Array = new int[this->Length + 1];
		//Поместим первый элемент в массив:
		this->Array[this->Length] = Value;
		this->Length++;
	}
	else
	{
		int* MyStack_Array_Temp = new int[this->Length + 1];
		//Резервное копирование:
		for (int i = 0; i < Length; i++)
		{
			MyStack_Array_Temp[i] = this->Array[i];
		}
		MyStack_Array_Temp[this->Length] = Value;
		//Удалим старый массив:
		delete[] this->Array;
		this->Array = MyStack_Array_Temp;
		this->Length++;
		//delete[] MyStack_Array_Temp;
	}
	return *this;
}
//Удалить из конца стека:
MyStack& MyStack::operator -()
{
	//Определим, пуст ли стек:
	if (this->Length == 0)
	{
		cout << "Невозможно исключить элемент из пустого стека!" << endl;
	}
	else
	{
		int* MyStack_Array_Temp = new int[this->Length - 1];
		//Резервное копирование, без последнего элемента:
		for (int i = 0; i < this->Length - 1; i++)
		{
			MyStack_Array_Temp[i] = this->Array[i];
		}
		//Удалим старый массив:
		delete[] this->Array;
		this->Array = MyStack_Array_Temp;
		this->Length--;
	}
	return *this;
}
//Присваивание:
MyStack& MyStack::operator =(MyStack &MyStackForAssignment)
{
	delete[] this->Array;
	this->Array = new int[MyStackForAssignment.Length];
	for (int i = 0; i < MyStackForAssignment.Length; i++)
	{
		this->Array[i] = MyStackForAssignment.Array[i];
	}
	this->Length = MyStackForAssignment.Length;
	return *this;
}
//Перегрузка osrtream:
ostream& operator <<(ostream& os, MyStack &MS)
{
	if (MS.Length == 0)
	{
		cout << "Данный стек пуст!" << endl;
	}
	else
	{
		for (int i = 0; i < MS.Length; i++)
		{
			os << "Stack[" << i << "]" << " = " << MS.Array[i] << endl;
		}	
		return os;
	}
}