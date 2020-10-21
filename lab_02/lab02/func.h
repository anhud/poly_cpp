#ifndef __FUNC_H_
#define __FUNC_H_

#include "stdafx.h"
#include "vectors.h"

double EditUnits(unit *u_main, trail *trail_main);
double ScreenClear(HDC hMemDC, HWND hWnd, int w, int h);
double DrawTrail(HDC hMemDC, HWND hWnd, unit *u_main, trail *trail_main);
double OnTimer(HDC hMemDC, HWND hWnd, int w, int h);

#endif