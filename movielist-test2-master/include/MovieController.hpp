#pragma once
#include "Movie.hpp"
#include "MovieDatabase.hpp"
//#include "MovieUsers.hpp"
#include "Users.hpp"
#include "Manager.hpp"
#include "UserManager.hpp"
#include <iostream>
#include <vector>
#include <string>

class MovieController
{
    private:
    Movie movie;
    std::vector<Movie> movies;
    MovieDatabase database;
    std::vector<MovieDatabase> dataItems;
    User newUser;
    std::vector<User> newUsers;
    Manager manager;
    UserManager userManager;
    //std::vector<Manager> management;

    public:
    MovieController(Movie &movie, MovieDatabase &database, User &newUser, Manager &manager, UserManager &userManager);
    void mainDisplay();


};