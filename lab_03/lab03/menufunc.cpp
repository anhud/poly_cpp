#include "pch.h"
#include "menufunc.h"

menu_system MenuRead(string FileName)
{
	std::ifstream input(FileName);
	string line;
	text lines;
	text line_cut;

	menu_system menus;

	int i = -1;

	if (input.is_open())
	{
		while (getline(input, line))
		{
			lines.push_back(line);
		}	
	}
	input.close();

	for (auto &line_ : lines)
	{
		std::istringstream iss(line_);
		menu cur;

		while (getline(iss, line, ' '))
		{
			line_cut.push_back(line);
		}
		string type_{ *line_cut.begin() };
	
		if (type_.compare("menu:") == 0)
		{
			cur.coords.x1 = stof(line_cut[1]);
			cur.coords.y1 = stof(line_cut[2]);
			cur.coords.x2 = stof(line_cut[3]);
			cur.coords.y2 = stof(line_cut[4]);
			menus.push_back(cur);
			i++;
		}

		if (type_.compare("button:") == 0)
		{
			button cur_b;
			cur_b.coords.x1 = stof(line_cut[1]);
			cur_b.coords.y1 = stof(line_cut[2]);
			cur_b.coords.x2 = stof(line_cut[3]);
			cur_b.coords.y2 = stof(line_cut[4]);
			cur_b.text = line_cut[5];
			menus[i].buttons.push_back(cur_b);
		}

		cur.active_id = 0;
		
		line_cut.clear();
	}

	return menus;
}
