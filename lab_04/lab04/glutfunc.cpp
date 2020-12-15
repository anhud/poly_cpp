#include "pch.h"
#include "glutfunc.h"
#include "menufunc.h"
#include "gamefunc.h"

static int mode = 1; //1 - main menu, 2 - game

bool CheckIfInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

void ProcessSpecialKeys(int key, int x, int y) {
	menu *current_menu = GetCurrentMenu();
	switch (mode)
	{
	case 1:
	{
		//glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
		switch (key) {
		case GLUT_KEY_DOWN:
			current_menu->move(down);
			break;
		case GLUT_KEY_UP:
			current_menu->move(up);
			break;
		}
	}
	break;
	case 2:
	{
		//glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);
		switch (key) {
		case GLUT_KEY_RIGHT:
			MovePlatform(right_);
			break;
		case GLUT_KEY_LEFT:
			MovePlatform(left_);
			break;
		}
	}
	break;
	}
	
}

void ProcessNormalKeys(unsigned char key, int x, int y) {
	switch (mode)
	{
	case 1:
	{
		switch (key) {
		case 27:
		{
			exit(0);
		}
		break;
		case 13:
		{
			menu *current_menu = GetCurrentMenu();
			string action = current_menu->get_action();

			if (CheckIfInteger(action))
			{
				MenuOpen(stoi(action));
				return;
			}
			else
			{
				if (action.compare("close") == 0)
				{
					CloseCurrentMenu();
					return;
				}
				else if (action.compare("exit") == 0)
				{
					exit(0);
					return;
				}
				else
				{
					mode = 2;
					InitGame(action);
					return;
				}
				// further functions there
			}
		}
		break;
		}
	}
	break;
	case 2:
	{
		switch (key) {
		
		}
	}
	break;
	}
}

void ProcessKeysUp(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_RIGHT:
		StopPlatform(right_);
		break;
	case GLUT_KEY_LEFT:
		StopPlatform(left_);
		break;
	}
}

//////////////

void DrawMenus(void)
{
	menu_system menus = *GetActiveMenus();

	for (auto &cur : menus)
	{
		cur.draw();
	}
}

void RenderMainMenu(void)
{
	DrawMenus();
}

//////////////

void RenderWindow(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	switch (mode) {
	case 1:
	{
		RenderMainMenu();
	}
	break;
	case 2:
	{
		RenderGame();
		UpdateGame();
	}
	break;
	}
	
	glutSwapBuffers();
}

void BackToMenu(void)
{
	mode = 1;
}