#include "Library.h"
#include <iostream>

Library::Library() {

}

Library::~Library() {

	std::unordered_map<std::string, std::pair<Book*, unsigned int >>::iterator it;

	for (it = _libraryMap.begin(); it != _libraryMap.end();) {
		delete it->second.first;
	}
}


void Library::print() {

	//checks first if the library hashmap is empty
	if (_libraryMap.empty()) {
		std::cout << "Library currently does not hold any books!\n";
		return;
	}


	std::unordered_map<std::string, std::pair<Book*, unsigned int >>::iterator it;
	
	std::cout << "******************************************\n";
	std::cout << "*****   BOOKS,    NUM AVAILABLE   ********\n";
	std::cout << "******************************************\n";


	for (it = _libraryMap.begin(); it != _libraryMap.end(); it++) {

		//prints the book name
		std::cout << it->first << ',\t';
		
		//handles availability
		//more options other can be added
		if (it->second.second > 0) {
			std::cout << it->second.second <<" Available\n";
		}
		else if (it->second.second == 0) {
			std::cout << "Not Available\n";
		}
		else {
			std::cout << "Unknown\n";
		}

		//for readability
		std::cout << '\n';
	}


	std::cout << "\n******************************************\n";

	return;
}

void Library::insertBook(std::string bookName) {

	if (checkBookAvailability(bookName)) {
		
		//since the book was found in the library, we find the number of books available
		unsigned int num = _libraryMap.find(bookName)->second.second;

		//grammar check
		if(num == 1)
			std::cout << num << " books titled " << bookName << " was found in the library. Adding to storage...";
		else 
			std::cout << num << " books titled " << bookName << " were found in the library. Adding to storage...";
		
		//increment the number of books available
		_libraryMap.find(bookName)->second.second++;
	}
	else {

		std::cout << "Book " << bookName << "was not found in the library. Adding to storage...";
		Book *book = new Book(bookName);
		
		//put the book on the shelf!
		_libraryMap.emplace(bookName, std::make_pair(book , (unsigned int) 1));
	}


	

}


bool Library::checkBookAvailability(std::string bookName) {

	int num = _libraryMap.find(bookName)->second.second;

	//handles availability
	//more options other can be added
	if ( num > 0 ) {
		//std::cout << "Book " << bookName<< " is available!\n";
		return true;
	}
	else if ( num == 0 ) {
		//std::cout << "Book " << bookName << "is not available!\n";
		return false;
	}
	else {
		//std::cout << "Book is in Limbo...\n";
		return false;
	}
}

void Library::checkoutBook(std::string bookName) {

	if (!checkBookAvailability(bookName)) {
		std::cout << "Book " << bookName << " is not available!";
		return;
	}

	std::cout << "Checking out book " << bookName << '\n';

	//decrements the number of available books
	_libraryMap.find(bookName)->second.second--;

}
