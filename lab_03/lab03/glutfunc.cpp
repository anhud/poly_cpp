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
		if (current_menu->active_id < current_menu->buttons.size() - 1)
		{
			current_menu->active_id++;
		}
		break;
	case GLUT_KEY_UP:
		if (current_menu->active_id > 0)
		{
			current_menu->active_id--;
		}
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
		button cur = current_menu->buttons[current_menu->active_id];

		if (CheckIfInteger(cur.text))
		{
			MenuOpen(stoi(cur.text));
			return;
		}
		else
		{
			if (cur.text.compare("close") == 0)
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

