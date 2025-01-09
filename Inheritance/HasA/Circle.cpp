#include <iostream>
#include "Circle.h"

Circle::Circle()
	: center(0, 0), radius(1)
{
}

Circle::Circle(float xVal, float yVal, float r)
	: center(xVal, yVal), radius(r)
{
}

void Circle::ShowData()
{
	float area = 3.141592f * radius * radius;

	std::cout << "중심 좌표: (" << center.GetX() << ", " << center.GetY() << ")\n";
	std::cout << "반지름: " << radius << "\n";
	std::cout << "원의 넓이: " << area << "\n";
}
