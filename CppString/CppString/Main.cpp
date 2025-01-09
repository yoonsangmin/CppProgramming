#include <iostream>

// 진입점(Entry Point).
int main()
{
	//auto testString = "Hello";
	const char* testString = "Hello";
	char charArray[] = "Hello";
	
	// 동적 할당.
	// long long -> __int64
	size_t length = strlen("Ronnie") + 1;
	char* name = new char[length];
	strcpy_s(name, length, "Ronnie");

	// 테스트 출력.
	std::cout << testString << "\n";
	std::cout << charArray << "\n";
	std::cout << name << "\n";
	//std::cout << testString << std::endl;

	delete[] name;

	// 의미는 없습니다.
	std::cin.get();
}