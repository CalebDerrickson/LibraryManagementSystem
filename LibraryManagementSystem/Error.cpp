#include "Error.h"
#include <iostream>
#include <conio.h>

void fatalError(std::string fatalString) {

	std::cout << fatalString << '\n';
	std::cout << "Press any key to quit...";
	_getch();
	exit(255);
}
