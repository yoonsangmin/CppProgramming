#pragma once

#include "Point.h"

class Circle : public Point
{
public:
    Circle();
    Circle(float xVal, float yVal, float r);

    void ShowData();

private:
    float radius;
};

