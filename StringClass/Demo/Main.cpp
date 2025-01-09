#include "String.h"

int main()
{
	String string("RonnieJ");

	std::cout << string << "\n";

	string = "Test String.";
	std::cout << string << "\n";
	std::cout << string.Length() << "\n";

	std::cout << ((string == "RonnieJ") ? "True" : "False") << "\n";

	String newString = string + "string";
	newString += "string";
	std::cout << newString;

	std::cin.get();
}