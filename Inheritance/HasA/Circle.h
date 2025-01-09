#pragma once

#include "Point.h"

class Circle
{
public:
    Circle();
    Circle(float xVal, float yVal, float r);

    void ShowData();

private:
    Point center;
    float radius;
};

