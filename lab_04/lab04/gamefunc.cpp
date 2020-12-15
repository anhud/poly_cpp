#include "pch.h"
#include "gamefunc.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

static ball ball_;
static platform platform_;
static level blocks;

level ReadLevel(string FileName)
{
	level level_;
	
	std::ifstream input(FileName);
	string line;
	text lines;
	text line_cut;

	int i = 0;
	int k = 0;

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
		
		i = 0;
		for (auto &word : line_cut)
		{
			if (stof(word) != 0)
				level_.push_back(block(i, k, stof(word)));
			i++;
		}
		k++;
		line_cut.clear();
	}

	return level_;
}

void InitGame(string FileName)
{
	blocks = ReadLevel(FileName);
	ball_ = ball();
	platform_ = platform_;
}

void MovePlatform(move_direction dir)
{
	platform_.Move(dir);
}

void StopPlatform(move_direction dir)
{
	platform_.Stop(dir);
}

void CloseGame(void)
{
	blocks.empty();
	BackToMenu();
}

void UpdateGame(void)
{
	for (auto &block_cur : blocks)
	{
		ball_.BlockCollision(&block_cur);
	}
	ball_.PlatformCollision(platform_);
	ball_.Update();
	platform_.Update();

	if ((ball_.GetCenter().y < -1))
		CloseGame();
	else for (auto &block_cur : blocks)
	{
		if (block_cur.GetType() != 0)
			return;
	}
	CloseGame();
	return;
}

void RenderGame(void)
{
	for (auto &block_cur : blocks)
	{
		block_cur.Draw();
	}
	ball_.Draw();
	platform_.Draw();
}

