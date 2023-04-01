#include "Users.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

User::User(std::string username, std::string password) :
username(username),
password(password)
{

}

std::string User::getUsername()
{
    return username;
}

std::string User::getPassword()
{
    return password;
}

