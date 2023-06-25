#pragma once

#include "Library.h"
class MainManager
{
public:


	MainManager();
	~MainManager();


	//initializes the entire thing. 
	int init();


	//main program loop
	int run();

private:

	Library _Library;
};

