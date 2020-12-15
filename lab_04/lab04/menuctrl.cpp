#include "pch.h"
#include "menufunc.h"

static menu_system menu_cur;
static menu_system menu_active;

void MenuInit(string FileName)
{
	menu_cur = MenuRead(FileName);
}

menu_system *GetActiveMenus()
{
	return &menu_active;
}

menu *GetCurrentMenu()
{
	return &(menu_active[menu_active.size() - 1]);
}

void MenuOpen(int id)
{
	menu_active.push_back(menu_cur[id]);
}

void CloseCurrentMenu()
{
	menu_active.pop_back();
}





