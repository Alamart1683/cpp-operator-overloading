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
	//��� ����������:
	MyStack()
	{
		Length = 0;
		Array = new int[Length];	
	}
	//� �����������:
	MyStack(int MS_L)
	{
		Length = MS_L;
		Array = new int[Length];
		for (int i = 0; i < Length; i++)
		{
			Array[i] = 0;
		}
	}
	//�����������:
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

	//������ ��������� �������:
	//������� �������� ���������� �������� �����:
	int Peek(int* MyStack_Array,int MyStack_Length)
	{
		if (MyStack_Length == 0)
		{
			cout << "���� ����, ������� ��������� ������� �� �������������� ���������!" << endl;
		}
		else
		{
			return MyStack_Array[MyStack_Length - 1];
		}
	}
	//������� ���������� ��������� �����:
	int CountOfElements(int MyStack_Length)
	{
		return MyStack_Length - 1;
	}

	//��������� ������� ��������������� �������:
	//�������� � ����� �����:
	MyStack& operator >>(int Value);
	//������� �� ����� �����:
	MyStack& operator -();
	//������������:
	MyStack& operator =(MyStack &MyStackForAssignment);
	//���������� osrtream:
	friend ostream& operator<<(ostream& os, MyStack &MS);
	//����������:
	~MyStack()
	{

	}
};

