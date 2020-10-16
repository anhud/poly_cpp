#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
using text = vector<vector<string>>;
using sentence = vector<string>;

void TextInput(string FileName, int str_len);
void TextToWords(sentence line_cur, int str_len);
void TextFormat(text words, int str_len);