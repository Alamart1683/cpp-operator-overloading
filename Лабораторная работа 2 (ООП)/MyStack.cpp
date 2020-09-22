#include "stdafx.h"
#include "MyStack.h"

//������ ��������������� �������:
//�������� � ����� �����:
MyStack& MyStack::operator >>(int Value)
{
	//���� ���� ����, �������� ������ ��� ������ �������:
	if (this->Length == 0)
	{
		this->Array = new int[this->Length + 1];
		//�������� ������ ������� � ������:
		this->Array[this->Length] = Value;
		this->Length++;
	}
	else
	{
		int* MyStack_Array_Temp = new int[this->Length + 1];
		//��������� �����������:
		for (int i = 0; i < Length; i++)
		{
			MyStack_Array_Temp[i] = this->Array[i];
		}
		MyStack_Array_Temp[this->Length] = Value;
		//������ ������ ������:
		delete[] this->Array;
		this->Array = MyStack_Array_Temp;
		this->Length++;
		//delete[] MyStack_Array_Temp;
	}
	return *this;
}
//������� �� ����� �����:
MyStack& MyStack::operator -()
{
	//���������, ���� �� ����:
	if (this->Length == 0)
	{
		cout << "���������� ��������� ������� �� ������� �����!" << endl;
	}
	else
	{
		int* MyStack_Array_Temp = new int[this->Length - 1];
		//��������� �����������, ��� ���������� ��������:
		for (int i = 0; i < this->Length - 1; i++)
		{
			MyStack_Array_Temp[i] = this->Array[i];
		}
		//������ ������ ������:
		delete[] this->Array;
		this->Array = MyStack_Array_Temp;
		this->Length--;
	}
	return *this;
}
//������������:
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
//���������� osrtream:
ostream& operator <<(ostream& os, MyStack &MS)
{
	if (MS.Length == 0)
	{
		cout << "������ ���� ����!" << endl;
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