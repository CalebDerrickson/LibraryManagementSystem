#include "Library.h"
#include "FileManager.h"

#include <iostream>

Library::Library() {

}

Library::~Library() {

	std::unordered_map<std::string, std::pair<Book*, unsigned int >>::iterator it;

	for (it = _libraryMap.begin(); it != _libraryMap.end();) {
		delete it->second.first;
	}
}


int Library::init() {


	std::cout << "Loading in books...";

	FileManager fileManager;
	fileManager.readFile("Books.txt");
	std::vector<std::vector<std::string>> userContents = fileManager.getContents();

	for (int i = 0; i < userContents.size(); i++) {

		Book* newBook = new Book(userContents[i][0], userContents[i][1], userContents[i][2], userContents[i][3], userContents[i][4]);
		_libraryMap.emplace(newBook->getName(), std::make_pair(userContents[i][5], newBook));
	}

	std::cout << "successful.";
	return 0;

}


int Library::printLibrary() {

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

	return 0;
}


int Library::insertBook(std::string bookName) {

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


	return 0;

}

int Library::removeBook(std::string bookName){

	Book* book = _libraryMap.find(bookName)->second.first;

	if(book == nullptr){
		
		std::cout<<"Book "<< bookName <<" was not found in the library.\n";
		return;
	}

	std::cout<<"Deleting book "<<bookName<<".\n";

	//hopefully no memory leak
	delete _libraryMap.find(bookName)->second.first;
	delete book;
	_libraryMap.erase(bookName);

	return 0;
}

int Library::checkBookAvailability(std::string bookName) {

	int num = _libraryMap.find(bookName)->second.second;

	//handles availability
	//more options other can be added
	if ( num > 0 ) {
		//std::cout << "Book " << bookName<< " is available!\n";
		return 1;
	}
	else if ( num == 0 ) {
		//std::cout << "Book " << bookName << "is not available!\n";
		return 0;
	}
	else {
		//std::cout << "Book is in Limbo...\n";
		return -1;
	}
}

int Library::checkoutBook(std::string bookName) {

	if (!checkBookAvailability(bookName)) {
		std::cout << "Book " << bookName << " is not available!";
		return;
	}

	std::cout << "Checking out book " << bookName << '\n';

	//decrements the number of available books
	_libraryMap.find(bookName)->second.second--;
	
	return 0;
}

int Library::printBookProperties(std::string bookName){

	Book* book = _libraryMap.find(bookName)->second.first;

	if(book == nullptr){
		std::cout<< "Book "<< bookName <<" was not found in the library.\n";
		return;
	}

	int bookAvailable = _libraryMap.find(bookName)->second.second;

	std::cout<<"~~BOOK PROPERTIES~~\n";

	std::cout<<"Title : "<< book->getName()<<'\n';
	std::cout<<"Author Name : " <<book->getAuthorName()<<'\n';
	std::cout<<"Genre : "<<book->getGenre()<<'\n';
	std::cout<<"Pages : "<<book->getNumPages()<<'\n';
	std::cout<<"Year Published : "<<book->getYearPublished()<<'\n';
	
	std::cout<<'\n';
	std::cout<<"Number Available : " <<bookAvailable<<'\n';


	return 0;
}
