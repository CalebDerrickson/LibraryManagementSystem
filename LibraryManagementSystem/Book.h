#pragma once
#include <string>
class Book
{
public:

	Book();
	Book(std::string name);
	~Book();

	std::string getName() { return _name; }
	

private:

	std::string _name;

};

