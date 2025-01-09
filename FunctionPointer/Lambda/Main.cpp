#include <iostream>
#include <functional>		// c++ 11.

// �Լ� ������.
typedef void (*functionPointer)();
using usingFP = void (*)();
std::function<void()> newFunctionPointer;

int main()
{
	// Lambda �Լ� (���� �Լ�).
	// �����ϸ鼭 ȣ��
	//[]() { std::cout << "Hello Lambda.\n"; }();

	// ���� �Լ� ����.
	int count = 0;
	auto function = [&count](/*int& count*/) { ++count; };

	functionPointer function2 = []() { std::cout << "Hello\n"; };
	function2();

	newFunctionPointer = function2;
	newFunctionPointer();

	// ȣ��.
	//auto returnValue = function();

	function();
	function();
	function();
	function();

	std::cout << "Count: " << count << "\n";

	std::cin.get();
}