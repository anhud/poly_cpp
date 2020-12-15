#pragma once

#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

#include "shapes.h"

using namespace std;
typedef enum { up, down } direction;

class button {
private:
	rectangle coords;
	string text;
public:
	button(double a1, double b1, double a2, double b2, string text_)
	{
		coords = rectangle(a1, b1, a2, b2);
		text = text_;
	}
	void draw(bool active)
	{
		if (active == true)
			coords.draw_rect(0.4, 0.4, 0.4);
		else
			coords.draw_rect(0.66, 0.66, 0.66);
	}
	string get_text()
	{
		return text;
	};
};

class menu {
private:
	rectangle coords;
	vector<button> buttons;
	int active_id; //id of current active button
public:
	menu(double a1, double b1, double a2, double b2)
	{
		coords = rectangle(a1, b1, a2, b2);
		active_id = 0;
	};

	void add_button(double a1, double b1, double a2, double b2, string text_)
	{
		buttons.push_back(button(a1, b1, a2, b2, text_));
	}

	void draw()
	{
		coords.draw_rect(0.9, 0.9, 0.9);

		int i = 0;
		for (auto &cur_b : buttons)
		{
			if (i == active_id)
				cur_b.draw(true);
			else
				cur_b.draw(false);
			i++;
		}
	};

	string get_action()
	{
		return buttons[active_id].get_text();
	};

	void move(direction dir)
	{
		if ((dir == down) && (active_id < buttons.size() - 1))
		{
			active_id++;
		}
		if ((dir == up) && (active_id > 0))
		{
			active_id--;
		}
	}
};

using menu_system = vector<menu>;

menu_system MenuRead(string FileName);
void MenuInit(string FileName);
menu_system *GetActiveMenus();
menu *GetCurrentMenu();
void MenuOpen(int id);
void CloseCurrentMenu();