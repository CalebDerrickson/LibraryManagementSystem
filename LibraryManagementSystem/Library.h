#pragma once

#include <unordered_map>
#include <string>
#include <utility>
#include "Book.h"
class Library
{
public:
	Library();
	~Library();

	//prints all books in the library, denotes availability
	void print();

	//Inserts a book into the library
	void insertBook(std::string bookName);

	//checks if a given book is not checked out.
	bool checkBookAvailability(std::string bookName);

	void checkoutBook(std::string bookName);

private:

	//holds book and the number of books available. Key is the name of the book
	std::unordered_map<std::string, std::pair<Book*, unsigned int> > _libraryMap;



};

