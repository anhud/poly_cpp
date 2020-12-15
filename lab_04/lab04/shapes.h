#pragma once

#define _USE_MATH_DEFINES

#include "pch.h"
#include <math.h>

class rectangle {
private:
	point p1, p2;
public:
	rectangle()
	{
		p1.x = 0;
		p1.y = 0;
		p2.x = 0;
		p2.y = 0;
	}
	rectangle(double a1, double b1, double a2, double b2)
	{
		p1.x = a1;
		p1.y = b1;
		p2.x = a2;
		p2.y = b2;
	}
	void draw_rect(float r, float g, float b)
	{
		glBegin(GL_QUADS);
		glColor3f(r, g, b);
		glVertex2f(p1.x, p1.y);
		glVertex2f(p2.x, p1.y);
		glVertex2f(p2.x, p2.y);
		glVertex2f(p1.x, p2.y);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(p1.x, p1.y);
		glVertex2f(p2.x, p1.y);
		glVertex2f(p2.x, p2.y);
		glVertex2f(p1.x, p2.y);
		glVertex2f(p1.x, p1.y);
		glEnd();
	};
	point GetPoint1()
	{
		return p1;
	}
	point GetPoint2()
	{
		return p2;
	}
};

class circle {
private:
	point center;
	double radius;
public:
	circle()
	{
		center.x = 0;
		center.y = 0;
		radius = 0;
	}
	circle(double a, double b, double c)
	{
		center.x = a;
		center.y = b;
		radius = c;
	}
	circle(point r, double c)
	{
		center.x = r.x;
		center.y = r.y;
		radius = c;
	}

	void draw_circle(float r, float g, float b)
	{
		float i;

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(r, g, b);
		glVertex2f(center.x, center.y);
		for (i = 0.0f; i <= 360.0; i++)
			glVertex2f(radius * cos(M_PI * i / 180.0) + center.x, radius * sin(M_PI * i / 180.0) + center.y);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		for (i = 0.0f; i <= 360.0; i++)
			glVertex2f(radius * cos(M_PI * i / 180.0) + center.x, radius * sin(M_PI * i / 180.0) + center.y);
		i = 0.0f;
		glVertex2f(radius * cos(0) + center.x, radius * sin(0) + center.y);
		glEnd();
	}
};

