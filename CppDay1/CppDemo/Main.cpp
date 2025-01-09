// 전처리(Pre-Process).
#include <iostream>
#include "Log.h"

//void Log(const char* message);

// 매크로.
//#define Square(x) ( (x) * (x) )
#define FORCEINLINE __forceinline
FORCEINLINE int Square(int x)
{
	return x * x;
}

// 진입점(Entry Point).
int main()
{
	// 주석(Comment).
	/*
	* 여러 줄 주석 - 비권장
	*/
	// 출력.
	//std::cout << "Hello World\n";
	//Log("Hello World");

	std::cout << Square(10) << "\n";

	// 의미 없음. 바로 종료되지 말라고 추가.
	std::cin.get();
}