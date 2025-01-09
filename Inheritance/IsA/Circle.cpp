#include <iostream>
#include "Circle.h"

Circle::Circle()
	: Point(), radius(1)
{
}

Circle::Circle(float xVal, float yVal, float r)
	: Point(xVal, yVal), radius(r)
{
}

void Circle::ShowData()
{
	float area = 3.141592f * radius * radius;

	std::cout << "중심 좌표: (" << x << ", " << y << ")\n";
	std::cout << "반지름: " << radius << "\n";
	std::cout << "원의 넓이: " << area << "\n";
}
