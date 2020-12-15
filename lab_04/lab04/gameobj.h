#pragma once
#include "shapes.h"
#include "pch.h"
#include "glutfunc.h"

class object
{
public:
	virtual void Draw() = 0;
};

class block : public object
{
private:
	int x, y, type;
public:
	block()
	{
		x = 0;
		y = 0;
		type = 0;
	}
	block(int a, int b, int c)
	{
		x = a;
		y = b;
		type = c;
	}
	virtual void Draw() override
	{
		rectangle rect = rectangle(-1 + x * 0.2, 1 - (y * 0.1), (-1 + x * 0.2) + 0.2, (1 - (y * 0.1)) - 0.1);
		switch (type)
		{
		case 1:
			rect.draw_rect(0.44f, 0.66f, 0.44f);
			break;
		case 2:
			rect.draw_rect(0.66f, 0.66f, 0.44f);
			break;
		case 3:
			rect.draw_rect(0.66f, 0.44f, 0.44f);
			break;
		}
	}
	rectangle GetRectangle()
	{
		return rectangle(-1 + x * 0.2, 1 - (y * 0.1), (-1 + x * 0.2) + 0.2, (1 - (y * 0.1)) - 0.1);
	}
	int GetType()
	{
		return type;
	}
	void LowerType()
	{
		type = type - 1;
	}
};

class platform : public object
{
private:
	double position, width, accel, speed;
public:
	platform()
	{
		position = 0;
		width = 0.4;
	    accel = 0.003;
		speed = 0;
	}
	virtual void Draw() override
	{
		rectangle rect = rectangle(position - width / 2.0, -0.8, position + width / 2.0, -0.9);
		rect.draw_rect(0.2f, 0.2f, 0.3f);
	}
	void Move(move_direction dir)
	{
		if (dir == left_)
		{
			speed = accel;
		}
		else
		{
			speed = -accel;
		}

	}
	void Stop(move_direction dir)
	{
		if (((dir == left_) && (speed > 0)) || ((dir == right_) && (speed < 0)))
		{
			speed = 0;
		}
	}
	void Update()
	{
		position = position - speed;
		if ((position - width / 2.0) < -1.0)
			position = -1 + width / 2.0;
		if ((position + width / 2.0) > 1.0)
			position = 1 - width / 2.0;
	}
	rectangle GetRectangle()
	{
		return rectangle(position - width / 2.0, -0.8, position + width / 2.0, -0.9);
	}
	double GetSpeed()
	{
		return speed;
	}
};

class ball : public object
{
private:
	point center;
	point speed;
	double radius;

	bool invert_x = false;
	bool invert_y = false;
public:
	ball()
	{
		center.x = 0;
		center.y = -0.3;
		speed.x = 0.001;
		speed.y = 0.001;
		radius = 0.02;
	}
	virtual void Draw() override
	{
		circle circ = circle(center, radius);
		circ.draw_circle(0.44f, 0.44f, 0.44f);
	}
	bool RectangleIntersection(rectangle rect)
	{
		point c = rect.GetPoint1();
		point d = rect.GetPoint2();

		return ((center.x + radius >= c.x) && (center.x - radius <= d.x) && (center.y + radius <= c.y) && (center.y - radius >= d.y));
	}
	bool RectangleCollision(rectangle rect)
	{
		point p1 = rect.GetPoint1();
		point p2 = rect.GetPoint2();
		
		double dl, dr, du, dd;

		double dlr, dud;

		bool collision = RectangleIntersection(rect);

		if (collision == true)
		{
			dl = (center.x + radius) - p1.x;
			dr = p2.x - (center.x - radius);
			du = (center.y + radius) - p1.y;
			dd = p2.y - (center.y - radius);

			if (fabs(dl) < fabs(dr))
				dlr = dl;
			else
				dlr = dr;

			if (fabs(du) < fabs(dd))
				dud = du;
			else
				dud = dd;

			if (fabs(dlr) < fabs(dud))
				invert_x = true;
			else
				invert_y = true;
		}
	
		return collision;
	}
	void BlockCollision(block *block_)
	{
		if (block_->GetType() > 0)
		{
			if (RectangleCollision(block_->GetRectangle()))
				block_->LowerType();
		}
	}
	void PlatformCollision(platform platform_)
	{
		if (RectangleCollision(platform_.GetRectangle()) == true)
			speed.x = speed.x - (platform_.GetSpeed() / 16);
	}
	void Update()
	{
		if ((center.x + radius) > 1)
		{
			center.x = 1 - radius;
			invert_x = true;
		}
		if ((center.x - radius) < -1)
		{
			center.x = -1 + radius;
			invert_x = true;
		}
		if ((center.y + radius) > 1)
		{
			center.y = 1 - radius;
			invert_y = true;
		}

		if (invert_x == true)
			speed.x = -speed.x;
		if (invert_y == true)
			speed.y = -speed.y;

		invert_x = false;
		invert_y = false;

		if (speed.x > 0.0025)
			speed.x = 0.0025;
		else if (speed.x < -0.0025)
			speed.x = -0.0025;

		center.x = center.x + speed.x;
		center.y = center.y + speed.y;
	}
	point GetCenter()
	{
		return center;
	}
	double GetRadius()
	{
		return radius;
	}
};

