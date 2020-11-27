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
	std::ifstream input(FileName);
	level level_;
	/*   */
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

void UpdateGame(void)
{
	ball_.Update();
}

void RenderGame(void)
{
	ball_.Draw();
	platform_.Draw();
}