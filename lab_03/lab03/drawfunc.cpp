#include "pch.h"
#include "menufunc.h"
#include "drawfunc.h"

void DrawMenus(void)
{
	menu_system menus = *GetActiveMenus();

	for (auto &cur : menus)
	{
		cur.draw();
	}
}

void RenderWindow(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawMenus();
	glutSwapBuffers();
}