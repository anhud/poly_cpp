#include "func.h"

int main(int argv, char **argc)
{
	if (argv == 3)
	{
		TextInput(argc[1], std::atoi(argc[2]));
		system("pause");
		return 0;
	}
	else
	{
		std::cout << "Incorrect parameters." << endl;
		system("pause");
		return 1;
	}
}
