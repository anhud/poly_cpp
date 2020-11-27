#pragma once
#include "shapes.h"
#include "pch.h"

class object
{
public:
	virtual void Draw() = 0;
};

class block : public object
{
private:
	int x, y;
public:
	block()
	{
		x = 0;
		y = 0;
	}
	block(int a, int b)
	{
		x = a;
		y = b;
	}
	void Draw()
	{
		rectangle rect = rectangle(-1 + x * 0.2, -1 + y * 0.2, (-1 + x * 0.2) + 0.2, (-1 + y * 0.2) + 0.05);
		rect.draw_rect(0.44f, 0.44f, 0.44f);
	}
};

class ball : public object
{
private:
	double x, y, angle, speed;
public:
	ball()
	{
		x = 0;
		y = 0;
		angle = 330;
		speed = 0.002;
	}
	void Draw()
	{
		circle circ = circle(x, y, 0.04);
		circ.draw_circle(0.44f, 0.44f, 0.44f);
	}
	void Update()
	{
		x = x + speed * cos(M_PI * angle / 180.0);
		y = y + speed * sin(M_PI * angle / 180.0);
	}
};

class platform : public object
{
private:
	double position, width, speed;
public:
	platform()
	{
		position = 0;
		width = 0.25;
	    speed = 0.03;
	}
	void Draw()
	{
		rectangle rect = rectangle(position - width / 2.0, -0.8, position + width / 2.0, -0.9);
		rect.draw_rect(0.2f, 0.2f, 0.3f);
	}
	void Move(move_direction dir)
	{
		if (dir == left_)
		{
			position = position - speed;
			if ((position - width / 2.0) < -1.0)
				position = -1 + width / 2.0;
		}
		else
		{
			position = position + speed;
			if ((position + width / 2.0) > 1.0)
				position = 1 - width / 2.0;
		}

	}
};