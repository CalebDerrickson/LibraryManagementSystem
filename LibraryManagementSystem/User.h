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
    User(int userID, std::string name, std::string email, std::string phoneNumber);
    ~User();

    //setters
    void setName(std::string name){_name = name;}
    void setEmail(std::string email){_email = email;}
    void setPhoneNumber(std::string phoneNumber){_phoneNumber = phoneNumber;}
    void setPassword(std::string password) { _password = password; }

    //getters
    std::string getName() {return _name;}
    std::string getEmail() {return _email;}
    std::string getPhoneNumber() {return _phoneNumber;}
    int getID() { return _userID; }

private:

    int _userID;
    std::string _name;
    std::string _email;
    std::string _phoneNumber;
    
    std::string _password;

    //for now, no cap on number of rented books
    std::vector< Book* > _booksRented;

};

