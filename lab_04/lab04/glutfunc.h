#pragma once

#include "pch.h"
#include "menufunc.h"

void ProcessSpecialKeys(int key, int x, int y);
void ProcessNormalKeys(unsigned char key, int x, int y);
void ProcessKeysUp(int key, int x, int y);

void DrawMenus(void);
void RenderWindow(void);
void BackToMenu(void);