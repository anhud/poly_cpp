#pragma once

#include "func.h"

double EditUnits(unit *u_main, trail *trail_main)
{
	static vect particle_speed;
	double norm;
	*u_main = unit(u_main->GetPos(), 0, u_main->GetAccel());
	if (GetKeyState(VK_UP) & 0x8000)
	{
		*u_main = *u_main + unit(0, vect(0, -1), 0);
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		*u_main = *u_main + unit(0, vect(0, 1), 0);
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		*u_main = *u_main + unit(0, vect(-1, 0), 0);
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		*u_main = *u_main + unit(0, vect(1, 0), 0);
	}
	norm = VectorLength(u_main->GetSpeed());
	if (norm > 1e-7)
	{
		*u_main = unit(u_main->GetPos(), u_main->GetSpeed() / norm, u_main->GetAccel());
		particle_speed = -(u_main->GetSpeed());
	}
	if (VectorLength(particle_speed) > 0.02)
	{
		particle_speed = particle_speed / 1.25;
		trail_main->push_back(unit(u_main->GetPos(), particle_speed, -particle_speed / 60));
	}

	*u_main = u_main->UpdatePos();
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
		trail_unit = trail_unit.UpdatePos();
		SetPixel(hMemDC, trail_unit.GetPos().GetX(), trail_unit.GetPos().GetY(), RGB(0, 0, 0));
		trail_unit = trail_unit.UpdateSpeed();
	}
	if (trail_main->size() > 0)
		if (VectorLength(trail_main->begin()->GetSpeed()) < 0.005)
			trail_main->erase(trail_main->begin());

	SetPixel(hMemDC, u_main->GetPos().GetX(), u_main->GetPos().GetY(), RGB(0, 0, 0));
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