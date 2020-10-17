#pragma once

#include <math.h>
#include <vector>

using namespace std;

class vect
{
public:
	double x, y;

	vect(double a, double b)
	{
		x = a;
		y = b;
	}
	vect()
	{
		x = 0;
		y = 0;
	}

	vect operator-(void) 
	{
		return vect(-x, -y);
	}
	vect operator+(vect & v) 
	{
		return vect(x + v.x, y + v.y);
	}
	vect operator-(vect & v)
	{
		return vect(x - v.x, y - v.y);
	}
	vect operator/(double a)
	{
		return vect(x / a, y / a);
	}
};

inline double VectorLength(vect v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

class unit
{
public:
	vect pos, speed, accel;

	unit(vect a, vect b, vect c)
	{
		pos = a;
		speed = b;
		accel = c;
	}
	unit()
	{
		pos.x = 0;
		pos.y = 0;
		speed.x = 0;
		speed.y = 0;
		accel.x = 0;
		accel.y = 0;
	}
};

using trail = vector<unit>;