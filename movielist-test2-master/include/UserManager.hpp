#pragma once
#include "Movie.hpp"
#include "MovieDatabase.hpp"
#include "Users.hpp"
#include "Watched.hpp"
#include "Manager.hpp"
#include <iostream>
#include <vector>
#include <string>

class UserManager
{
    private:
    User newUser;
    std::vector<User> newUsers;
    Manager manager;

    public:
    UserManager(User &newUser, Manager &manager);
    void registration(std::vector<User> &newUsers);
    void findUser(std::string name);
    void checkPassword(std::string z);
    void viewAllUsers();
    void loadUsers(const std::string myBase);
    void findUsername(std::vector<User> &newUsers);


};