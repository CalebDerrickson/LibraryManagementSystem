#include "UserManager.h"
#include "FileManager.h"

UserManager::UserManager() {


}


UserManager::~UserManager() {


}

int UserManager::registerUser(std::string name) {

	//find if a user with given name is already registered
	std::unordered_map<int, User*>::iterator it;

	for (it = _userBase.begin(); it != _userBase.end(); it++) {
		
		if ((it->second)->getName() == name) {
			std::cout << "User " << name << " already has an account in the library!\n";
			return 0;
		}
	} 
	
	//user not found in library, setting an id 

	std::mt19937 randomEngine;
	randomEngine.seed((unsigned int)time(nullptr));
	std::uniform_int_distribution<unsigned int> randId(0, UINT16_MAX);
	unsigned int userid = randId(randomEngine);


	//getting a unique id
	for (it = _userBase.begin(); it != _userBase.end(); it++) {

		if ((it->first) == userid) {
			userid = randId(randomEngine);
			it = _userBase.begin();
		}
	}

	std::cout << "Registering user... " << name << '\n';
	
	User* user = new User(name);

	std::string password{};
	std::string password2{};

	while (true) {
	
		std::cout << "Enter password for user ->";
		std::cin >> password;

		std::cout << "ReEnter password ->";
		std::cin >> password2;
	
		if (password.compare(password2) == 0) 
			break;

		std::cout << "Passwords do not match. Please try again.\n";
		password.clear();
		password2.clear();
	}

	user->setPassword(password);

	//need to add to Users.txt
	_userBase.emplace(userid, user);

	std::cout << "User " << name << " has been added to the library registry.\n";
	std::cout << "Please update user properties (email, phone number).\n";


	return 0;
}

int UserManager::init() {


	std::cout << "Loading in registered users...";

	FileManager fileManager;
	fileManager.readFile("Users.txt");
	std::vector<std::vector<std::string>> userContents = fileManager.getContents();

	for (int i = 0; i < userContents.size(); i++) {
			
			User* newUser = new User( userContents[i][0], userContents[i][1], userContents[i][2], userContents[i][3], userContents[i][4]);
			_userBase.emplace(newUser->getID(), newUser);
	}

	std::cout << "successful.";
	return 0;
}

int UserManager::updateUser(User* user, std::string email, std::string phoneNumber) {

	user->setEmail(email);
	user->setPhoneNumber(phoneNumber);

	std::cout << "Email updated for " << user->getName() << " to " << email << '\n';
	std::cout << "Phone number updated for " << user->getName() << " to " << phoneNumber << '\n';
}


int UserManager::updateUser(User* user, std::string email) {

	user->setEmail(email);
	std::cout << "Email updated for " << user->getName() << " to " << email << '\n';
}


int UserManager::updateUser(User* user, std::string phoneNumber) {

	user->setPhoneNumber(phoneNumber);
	std::cout << "Phone number updated for " << user->getName() << " to " << phoneNumber << '\n';
}

User* UserManager::userLogin() {

	std::string userId{};
	std::string password{};
	
	while (true) {

		std::cout << "User ID ->";
		std::cin >> userId;
		std::cout << "Password ->";
		std::cin >> password;

		if (userId.compare("exit") == 0 || (password).compare("exit") == 0) {
			std::cout << "Returning...";
			return nullptr;
		}

		if (_userBase[std::stoi(userId)]->getPassword() == password)
			return _userBase[std::stoi(userId)];

		std::cout << "Invalid userId or password. Please try again.\n";
	
		userId.clear();
		password.clear();
		userId.resize(0);
		password.resize(0);
	}

}