#include "pch.h"
#include "glutfunc.h"

bool CheckIfInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

void ProcessSpecialKeys(int key, int x, int y) {
	menu *current_menu = GetCurrentMenu();

	switch (key) {
	case GLUT_KEY_DOWN:
		current_menu->move(down);
		break;
	case GLUT_KEY_UP:
		current_menu->move(up);
		break;
	}
}

void ProcessNormalKeys(unsigned char key, int x, int y) {
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
			// further functions there
		}
	}
	break;
	}
}

