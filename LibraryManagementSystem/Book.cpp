#include "Book.h"


Book::Book(){}

Book::Book(std::string name) : 
    _name(name),
    _authorName(""),
    _genre(""),
    _numPages(0),
    _yearPublished(0) {
    
        //Empty
}

Book::Book(std::string name, std::string authorName, std::string genre , int numPages, int yearPublished) : 
    _name(name),
    _authorName(authorName),
    _genre(genre),
    _numPages(numPages),
    _yearPublished(yearPublished) {

        //Empty
}


Book::~Book() {

}
