#pragma once

#include "func.h"

double EditUnits(unit *u_main, trail *trail_main)
{
	static vect particle_speed;
	double norm;
	u_main->speed = vect(0, 0);
	if (GetKeyState(VK_UP) & 0x8000)
	{
		u_main->speed.y = u_main->speed.y - 1;
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		u_main->speed.y = u_main->speed.y + 1;
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		u_main->speed.x = u_main->speed.x - 1;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		u_main->speed.x = u_main->speed.x + 1;
	}
	norm = VectorLength(u_main->speed);
	if (norm > 1e-7)
	{
		u_main->speed.x = u_main->speed.x / norm;
		u_main->speed.y = u_main->speed.y / norm;
		particle_speed = -u_main->speed;
	}
	if (VectorLength(particle_speed) > 0.02)
	{
		particle_speed = particle_speed / 1.25;
		trail_main->push_back(unit(u_main->pos, particle_speed, particle_speed / 60));
	}

	u_main->pos = u_main->pos + u_main->speed;
	return 0;
}

double ScreenClear(HDC hMemDC, HWND hWnd, int w, int h)
{
	SelectObject(hMemDC, GetStockObject(DC_PEN));
	SelectObject(hMemDC, GetStockObject(DC_BRUSH));
	SetDCPenColor(hMemDC, RGB(0, 0, 0));
	SetDCBrushColor(hMemDC, RGB(255, 255, 255));
	Rectangle(hMemDC, -1, -1, w + 1, h + 1);
	InvalidateRect(hWnd, NULL, FALSE);
	return 0;
}

double DrawTrail(HDC hMemDC, HWND hWnd, unit *u_main, trail *trail_main)
{
	for (auto &trail_unit : *trail_main)
	{
		trail_unit.pos = trail_unit.pos + trail_unit.speed;
		SetPixel(hMemDC, trail_unit.pos.x, trail_unit.pos.y, RGB(0, 0, 0));
		trail_unit.speed = trail_unit.speed - trail_unit.accel;
	}
	if (trail_main->size() > 0)
		if (VectorLength(trail_main->begin()->speed) < 0.005)
			trail_main->erase(trail_main->begin());

	SetPixel(hMemDC, u_main->pos.x, u_main->pos.y, RGB(0, 0, 0));
	return 0;
}

double OnTimer(HDC hMemDC, HWND hWnd, int w, int h)
{
	static unit u_main = unit(vect(19, 18), vect(0, 0), vect(0, 0));
	static trail trail_main;

	EditUnits(&u_main, &trail_main);
	ScreenClear(hMemDC, hWnd, w, h);
	DrawTrail(hMemDC, hWnd, &u_main, &trail_main);
	return 0;
}