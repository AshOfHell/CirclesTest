#include "Circles.h"
#include <iostream>
#include <math.h>
#include <array>

Curve::Curve(float InitialRadiusX, float InitialRadiusY) 
{
	RadiusX = InitialRadiusX;
	RadiusY = InitialRadiusY;
}

std::array<float, 2> Circle::GetCoordinates(float Angle, float Radius)
{
	std::array<float, 2> Array;
	Array[0] = Radius * cos(Angle);
	Array[1] = Radius * sin(Angle);
	return Array;
}