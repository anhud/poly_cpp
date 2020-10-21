#pragma once

#include <math.h>
#include <vector>

using namespace std;

class vect
{
private:
	double x, y;
public:
	vect(double a)
	{
		x = a;
		y = a;
	}
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
	double GetX()
	{
		return x;
	}
	double GetY()
	{
		return y;
	}
};

inline double VectorLength(vect v)
{
	return sqrt(v.GetX() * v.GetX() + v.GetY() * v.GetY());
}

class unit
{
private:
	vect pos, speed, accel;
public:
	unit(vect a, vect b, vect c)
	{
		pos = a;
		speed = b;
		accel = c;
	}
	unit()
	{
		pos = vect(0);
		speed = vect(0);
		accel = vect(0);
	}

	unit operator+(unit u)
	{
		return unit(pos + u.pos, speed + u.speed, accel + u.accel);
	}

	unit operator-(unit u)
	{
		return unit(pos - u.pos, speed - u.speed, accel - u.accel);
	}

	vect GetPos()
	{
		return pos;
	}

	vect GetSpeed()
	{
		return speed;
	}

	vect GetAccel()
	{
		return accel;
	}

	unit UpdatePos()
	{
		return unit(pos + speed, speed, accel);
	}

	unit UpdateSpeed()
	{
		return unit(pos, speed + accel, accel);
	}
};

using trail = vector<unit>;