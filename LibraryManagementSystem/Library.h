#pragma once

#include <unordered_map>
#include <string>
#include <utility>
#include "Error.h"
#include "Book.h"
class Library
{
public:
	Library();
	~Library();

	//prints all books in the library, denotes availability
	int printLibrary();


	//Inserts a book into the library
	int insertBook(std::string bookName);

	//Completely removes a book from the library
	int removeBook(std::string bookName);

	//checks the availability of a book.
	int checkBookAvailability(std::string bookName);

	//checks out book
	//TODO: ASSIGN BOOK TO USER CHECKING OUT
	int checkoutBook(std::string bookName);

	//prints out the given properites of a book
	int printBookProperties(std::string bookName);

private:

	//holds book and the number of books available. Key is the name of the book
	std::unordered_map<std::string, std::pair<Book*, unsigned int> > _libraryMap;



};

