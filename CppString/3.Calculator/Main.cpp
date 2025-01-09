#include <iostream>

class Calculator
{
public:
	Calculator()
		: addCount(0), divideCount(0), substractCount(0), multiplyCount(0)
	{

	}

	double Add(double a, double b)
	{
		++addCount;
		return a + b;
	}
	
	double Divide(double a, double b)
	{
		++divideCount;
		return a / b;
	}

	double Substract(double a, double b)
	{
		++substractCount;
		return a - b;
	}
	
	double Multiply(double a, double b)
	{
		++multiplyCount;
		return a * b;
	}

	void ShowOperationCount()
	{
		std::cout << "µ¡¼À: " << addCount << "  »¬¼À: " << substractCount << "  °ö¼À: " << multiplyCount << "  ³ª´°¼À: " << divideCount << "\n";
	}

private:
	int addCount;
	int substractCount;
	int multiplyCount;
	int divideCount;
};

int main()
{
	Calculator calculator;

	std::cout << "3+5=" << calculator.Add(3, 5) << "\n";
	std::cout << "3/5=" << calculator.Divide(3, 5) << "\n";
	std::cout << "12-7=" << calculator.Substract(12, 7) << "\n";
	std::cout << "12x7=" << calculator.Multiply(12, 7) << "\n";

	calculator.ShowOperationCount();

	std::cin.get();
}