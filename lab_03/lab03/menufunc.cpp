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

		while (getline(iss, line, ' '))
		{
			line_cut.push_back(line);
		}
		string type_{ *line_cut.begin() };
	
		if (type_.compare("menu:") == 0)
		{
			menus.push_back(menu(stof(line_cut[1]), stof(line_cut[2]), stof(line_cut[3]), stof(line_cut[4])));
			i++;
		}

		if (type_.compare("button:") == 0)
		{
			menus[i].add_button(stof(line_cut[1]), stof(line_cut[2]), stof(line_cut[3]), stof(line_cut[4]), line_cut[5]);
		}
		
		line_cut.clear();
	}

	return menus;
}
