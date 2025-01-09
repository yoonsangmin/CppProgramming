#include "Point.h"

Point::Point()
	: x(0), y(0)
{
}

Point::Point(float xVal, float yVal)
	: x(xVal), y(yVal)
{
}

float Point::GetX() const
{
	return x;
}

float Point::GetY() const
{
	return y;
}
