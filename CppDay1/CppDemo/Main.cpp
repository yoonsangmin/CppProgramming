// ��ó��(Pre-Process).
#include <iostream>
#include "Log.h"

//void Log(const char* message);

// ��ũ��.
//#define Square(x) ( (x) * (x) )
#define FORCEINLINE __forceinline
FORCEINLINE int Square(int x)
{
	return x * x;
}

// ������(Entry Point).
int main()
{
	// �ּ�(Comment).
	/*
	* ���� �� �ּ� - �����
	*/
	// ���.
	//std::cout << "Hello World\n";
	//Log("Hello World");

	std::cout << Square(10) << "\n";

	// �ǹ� ����. �ٷ� ������� ����� �߰�.
	std::cin.get();
}