#pragma once
#include <string>
#include <vector>

class User
{
public:

    //setters
    void setName(std::string name){_name = name;}
    void setEmail(std::string email){_email = email;}
    void setPhoneNumber(std::string phoneNumber){_phoneNumber = phoneNumber;}

    //getters
    std::string getName() {return _name;}
    std::string getEmail() {return _email;}
    std::string getPhoneNumber() {return _phoneNumber;}

private:

    std::string _name;
    std::string _email;
    std::string _phoneNumber;
    std::vector<std::string> _booksRented;

};

