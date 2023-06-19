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
	void printLibrary();

	//prints the information of a given book
	void accessBook();

	//Inserts a book into the library
	void insertBook(std::string bookName);

	//Completely removes a book from the library
	void removeBook(std::string bookName);

	//checks the availability of a book.
	bool checkBookAvailability(std::string bookName);

	//checks out book
	//TODO: ASSIGN BOOK TO USER CHECKING OUT
	void checkoutBook(std::string bookName);

	//prints out the given properites of a book
	void printBookProperties(std::string bookName);
private:

	//holds book and the number of books available. Key is the name of the book
	std::unordered_map<std::string, std::pair<Book*, unsigned int> > _libraryMap;



};

