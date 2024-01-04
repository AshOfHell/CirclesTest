#pragma once

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
	float* GetCoordinates(float Angle, float Radius);
};