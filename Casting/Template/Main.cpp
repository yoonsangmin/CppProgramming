#include <iostream>

// int Ÿ�� �� �ٲٱ�.
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
// float Ÿ�� �� �ٲٱ�.
//void Swap(float& a, float& b)
//{
//	float temp = a;
//	a = b;
//	b = temp;
//}

// ���ø�.
template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


int main()
{
	int number1 = 10;
	int number2 = 20;

	Swap<int>(number1, number2);
	std::cout << number1 << " : " << number2 << "\n";

	float number3 = 10.34f;
	float number4 = 20.56f;

	Swap<float>(number3, number4);
	std::cout << number3 << " : " << number4 << "\n";

	std::cin.get();
}