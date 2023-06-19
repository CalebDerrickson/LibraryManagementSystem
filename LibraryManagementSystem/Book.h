#pragma once
#include <string>
class Book
{
public:

	Book();
	Book(std::string name);
	Book(std::string name, std::string authorName, std::string genre, int numPages, int yearPublished);
	
	~Book();

	//getters
	std::string getName() { return _name; }
	std::string getAuthorName() {return _authorName;}
	std::string getGenre() { return _genre;}
	int getNumPages() {return _numPages;}
	int getYearPublished(){ return _yearPublished;}

private:

	std::string _name;
	std::string _authorName;
	std::string _genre;

	int _numPages;
	int _yearPublished;

};

