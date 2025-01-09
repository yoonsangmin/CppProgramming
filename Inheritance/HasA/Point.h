#pragma once
class Point
{
public:
	Point();
	Point(float xVal, float yVal);

	float GetX() const;
	float GetY() const;

private:
	float x;
	float y;
};
