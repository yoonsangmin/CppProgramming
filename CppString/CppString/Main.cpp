#include <iostream>

// ������(Entry Point).
int main()
{
	//auto testString = "Hello";
	const char* testString = "Hello";
	char charArray[] = "Hello";
	
	// ���� �Ҵ�.
	// long long -> __int64
	size_t length = strlen("Ronnie") + 1;
	char* name = new char[length];
	strcpy_s(name, length, "Ronnie");

	// �׽�Ʈ ���.
	std::cout << testString << "\n";
	std::cout << charArray << "\n";
	std::cout << name << "\n";
	//std::cout << testString << std::endl;

	delete[] name;

	// �ǹ̴� �����ϴ�.
	std::cin.get();
}