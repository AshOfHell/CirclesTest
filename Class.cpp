#include "Circles.h"
#include <iostream>
#include <math.h>

Curve::Curve(float InitialRadiusX, float InitialRadiusY) 
{
	RadiusX = InitialRadiusX;
	RadiusY = InitialRadiusY;
}

float* Circle::GetCoordinates(float Angle, float Radius)
{
	float* Array = new float[2];
	Array[0] = Radius * cos(Angle);
	Array[1] = Radius * sin(Angle);
	return Array;
	delete[] Array;
}