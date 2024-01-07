#pragma once

#include <array>

class Curve
{
private:
public:
	float RadiusX, RadiusY;
	Curve(float RadiusX, float RadiusY);
};

class Circle
{
private:
public:
	float Radius, X, Y, Angle, Coordinates[2];
	Circle(float Radius)
	{
		this->Radius = Radius;
	};
	std::array<float, 2> GetCoordinates(float Angle, float Radius);
};