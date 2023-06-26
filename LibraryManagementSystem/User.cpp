#include "User.h"

User::User() {


}

User::User(std::string name) : 
	_name(name) {


}

User::User(std::string userID, std::string name, std::string email, std::string phoneNumber) : 
	_userID(userID), _name(name),
	_email(email), _phoneNumber(phoneNumber),
	_booksRented({})
	{


}


User::~User() {


}