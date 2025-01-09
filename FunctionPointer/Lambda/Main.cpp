#include <iostream>
#include <functional>		// c++ 11.

// 함수 포인터.
typedef void (*functionPointer)();
using usingFP = void (*)();
std::function<void()> newFunctionPointer;

int main()
{
	// Lambda 함수 (무명 함수).
	// 선언하면서 호출
	//[]() { std::cout << "Hello Lambda.\n"; }();

	// 람다 함수 저장.
	int count = 0;
	auto function = [&count](/*int& count*/) { ++count; };

	functionPointer function2 = []() { std::cout << "Hello\n"; };
	function2();

	newFunctionPointer = function2;
	newFunctionPointer();

	// 호출.
	//auto returnValue = function();

	function();
	function();
	function();
	function();

	std::cout << "Count: " << count << "\n";

	std::cin.get();
}