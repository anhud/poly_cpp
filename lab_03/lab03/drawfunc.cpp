#include "pch.h"
#include "menufunc.h"
#include "drawfunc.h"

void DrawMenus(void)
{
	menu_system menus = *GetActiveMenus();

	for (auto &cur : menus)
	{
		glBegin(GL_QUADS);
		glColor3f(0.9f, 0.9f, 0.9f);
		glVertex2f(cur.coords.x1, cur.coords.y1);
		glVertex2f(cur.coords.x2, cur.coords.y1);
		glVertex2f(cur.coords.x2, cur.coords.y2);
		glVertex2f(cur.coords.x1, cur.coords.y2);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(cur.coords.x1, cur.coords.y1);
		glVertex2f(cur.coords.x2, cur.coords.y1);
		glVertex2f(cur.coords.x2, cur.coords.y2);
		glVertex2f(cur.coords.x1, cur.coords.y2);
		glVertex2f(cur.coords.x1, cur.coords.y1);
		glEnd();

		int i = 0;
		for (auto &cur_b : cur.buttons)
		{
			glBegin(GL_QUADS);
			if(i == cur.active_id)
				glColor3f(0.4f, 0.4f, 0.4f);
			else
				glColor3f(0.66f, 0.66f, 0.66f);
			glVertex2f(cur_b.coords.x1, cur_b.coords.y1);
			glVertex2f(cur_b.coords.x2, cur_b.coords.y1);
			glVertex2f(cur_b.coords.x2, cur_b.coords.y2);
			glVertex2f(cur_b.coords.x1, cur_b.coords.y2);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glColor3f(0.0f, 0.0f, 0.0f);
			glVertex2f(cur_b.coords.x1, cur_b.coords.y1);
			glVertex2f(cur_b.coords.x2, cur_b.coords.y1);
			glVertex2f(cur_b.coords.x2, cur_b.coords.y2);
			glVertex2f(cur_b.coords.x1, cur_b.coords.y2);
			glVertex2f(cur_b.coords.x1, cur_b.coords.y1);
			glEnd();

			i++;
		}
	}
}

void RenderWindow(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawMenus();
	glutSwapBuffers();
}