#include "func.h"

void TextInput(string FileName, int str_len)
{
	std::vector<string> line_cur;
	std::string line;
	std::ifstream in(FileName);

	if (in.is_open())
	{
		while (getline(in, line))
		{
			line_cur.push_back(line);
		}
	}
	in.close();
	TextToWords(line_cur, str_len);
}

void TextToWords(vector<string> line_cur, int str_len)
{
	std::vector<vector<string>> words;
	std::string line;
	std::vector<string> words_cur;

	for (auto line_ : line_cur)
	{
		std::istringstream iss(line_);

		while (getline(iss, line, ' '))
		{
			words_cur.push_back(line);
		}
		words.push_back(words_cur);
		words_cur.clear();
	}

	TextFormat(words, str_len);

	return;
}

void TextFormat(vector<vector<string>> words, int str_len)
{
	std::string cur_line;
	int len;
	int spaces;

	for (auto line : words)
	{
		if (line.size() == 0)   // checking for extra line breaks
		{
			cout << endl;
		}
		else
		{
			len = -1;    // first word of a given line doesnt have a space *before* it
			for (auto linecut : line)
			{
				len = len + linecut.length() + 1;
				if (len > str_len)
				{
					// added spaces
					spaces = str_len - (len - linecut.length());
					if (cur_line.size() != 0)
					{
						if (spaces > 0)
						{
							cur_line.insert(cur_line.begin(), spaces / 2, ' ');
							cur_line.insert(cur_line.end(), spaces / 2, ' ');
						}
						cout << cur_line << endl;
					}
					cur_line.erase();
					len = linecut.length();
					// case for words longer than the line length
					while (len > str_len)
					{
						cout << linecut.substr(0, str_len) << endl;
						linecut.erase(0, str_len);
						len = len - str_len;
					}
				}
				cur_line.append(linecut);
				cur_line.append(" ");
			}
			//last bit of given string
			spaces = str_len - (cur_line.length());
			if (spaces > 0)
			{
				cur_line.insert(cur_line.begin(), spaces / 2, ' ');
				cur_line.insert(cur_line.end(), spaces / 2, ' ');
			}
			cout << cur_line << endl;
			cur_line.erase();
		}
	}
}
