#pragma once

#include "User.h"
#include <unordered_map>
#include <ctime> 
#include <iostream>
#include <random>
class UserManager
{
public:
	UserManager();
	~UserManager();

	//adds user (name only) to userbase
	int registerUser(std::string name);
	
	//loads in all previously registeres users from a text file
	int init();

	//updates the contacts of the given user. 
	//Should check if the user if logged in before updating. 
	int updateUser(User* user, std::string email, std::string phoneNumber);
	int updateUser(User* user, std::string email);
	int updateUser(User* user, std::string phoneNumber);

	//logs in the user, provided username and password given
	//is correct. Returns pointer to user.
	//user logout should be done in MainManager?
	User* userLogin();



private:

	std::unordered_map< int , User* > _userBase;
};


