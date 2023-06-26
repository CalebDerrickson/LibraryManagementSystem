#pragma once

#include <string>
#include <vector>

//forward declaration
class Book;

class User
{
public:

    User();
    User(std::string name);
    User(std::string userID, std::string name, std::string email, std::string phoneNumber);
    ~User();

    //setters
    void setID(std::string userID) { _userID = _userID; }
    void setName(std::string name){_name = name;}
    void setEmail(std::string email){_email = email;}
    void setPhoneNumber(std::string phoneNumber){_phoneNumber = phoneNumber;}
    void setPassword(std::string password) { _password = password; }

    //getters
    std::string getName() {return _name;}
    std::string getEmail() {return _email;}
    std::string getPhoneNumber() {return _phoneNumber;}
    std::string getPassword() { return _password; }
    std::vector<Book*> getBookVec() { return _booksRented; }

    std::string getID() { return _userID; }

private:

    std::string _userID;
    std::string _name;
    std::string _email;
    std::string _phoneNumber;
    
    std::string _password;

    //for now, no cap on number of rented books
    std::vector< Book* > _booksRented;

};

