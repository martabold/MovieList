#pragma once
#include "Users.hpp"
#include <vector>
#include <string>

class Admin : public User
{
    private: 

    public:
    Admin(User &newUser);
    void deleteUsers();


};