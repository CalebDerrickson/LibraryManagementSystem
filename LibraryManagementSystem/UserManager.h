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


	int registerUser(std::string name);
	int userLogin();



private:

	std::unordered_map< int , User* > _userBase;
};


