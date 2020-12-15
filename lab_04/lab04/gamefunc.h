#include "pch.h"
#include "gameobj.h"
#include <vector>

using namespace std;
using level = vector<block>;

void MovePlatform(move_direction dir);
void StopPlatform(move_direction dir);
void InitGame(string FileName);
void UpdateGame(void);
void RenderGame(void);