#pragma once

#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
using text = vector<string>;

struct rectangle {
	double x1, y1, x2, y2;
};

struct button {
	rectangle coords;
	string text;
};

struct menu {
	rectangle coords;
	vector<button> buttons;
	int active_id; //id of current active button
};

using menu_system = vector<menu>;

menu_system MenuRead(string FileName);
void MenuInit(string FileName);
menu_system *GetActiveMenus();
menu *GetCurrentMenu();
void MenuOpen(int id);
void CloseCurrentMenu();