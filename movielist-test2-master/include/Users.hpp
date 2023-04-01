#pragma once
#include "Movie.hpp"
#include "MovieDatabase.hpp"
//#include "MovieUsers.hpp"
#include <iostream>
#include <vector>
#include <string>

class User
{
    private:
    std::string username;
    std::string password;

    public:
    User(std::string username, std::string password);
    std::string getUsername();
    std::string getPassword();
    
};