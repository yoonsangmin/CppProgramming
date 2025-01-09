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

	std::cout << "�߽� ��ǥ: (" << x << ", " << y << ")\n";
	std::cout << "������: " << radius << "\n";
	std::cout << "���� ����: " << area << "\n";
}
