#pragma once

#define _USE_MATH_DEFINES

#include "pch.h"
#include <math.h>

class rectangle {
private:
	double x1, y1, x2, y2;
public:
	rectangle()
	{
		x1 = 0;
		y1 = 0;
		x2 = 0;
		y2 = 0;
	}
	rectangle(double a1, double b1, double a2, double b2)
	{
		x1 = a1;
		y1 = b1;
		x2 = a2;
		y2 = b2;
	}

	void draw_rect(float r, float g, float b)
	{
		glBegin(GL_QUADS);
		glColor3f(r, g, b);
		glVertex2f(x1, y1);
		glVertex2f(x2, y1);
		glVertex2f(x2, y2);
		glVertex2f(x1, y2);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(x1, y1);
		glVertex2f(x2, y1);
		glVertex2f(x2, y2);
		glVertex2f(x1, y2);
		glVertex2f(x1, y1);
		glEnd();
	};
};

class circle {
private:
	double x, y, radius;
public:
	circle()
	{
		x = 0;
		y = 0;
		radius = 0;
	}
	circle(double a, double b, double c)
	{
		x = a;
		y = b;
		radius = c;
	}

	void draw_circle(float r, float g, float b)
	{
		float i;

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(r, g, b);
		glVertex2f(x, y); 
		for (i = 0.0f; i <= 360.0; i++)
			glVertex2f(radius * cos(M_PI * i / 180.0) + x, radius * sin(M_PI * i / 180.0) + y);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		for (i = 0.0f; i <= 360.0; i++)
			glVertex2f(radius * cos(M_PI * i / 180.0) + x, radius * sin(M_PI * i / 180.0) + y);
		i = 0.0f;
		glVertex2f(radius * cos(0) + x, radius * sin(0) + y);
		glEnd();
	}
};