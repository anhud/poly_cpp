#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void TextInput(string FileName, int str_len);
void TextToWords(vector<string> line_cur, int str_len);
void TextFormat(vector<vector<string>> words, int str_len);