#pragma once
#include "Movie.hpp"
#include "MovieDatabase.hpp"
//#include "MovieUsers.hpp"
#include "Users.hpp"
#include "Watched.hpp"
#include "CurrentlyWatching.hpp"
#include "ToBeWatched.hpp"
#include "MenuTextView.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <optional>

class Manager
{
    private:
    Movie movie;
    std::vector<Movie> movies;
    MovieDatabase database;
    std::vector<MovieDatabase> dataItems;
    User newUser;
    std::vector<User> newUsers;
    Watched watched;
    CurrentlyWatching watching;
    ToBeWatched willBeWatched;
    MenuTextView textView;


    public:
    Manager(Movie &movie, MovieDatabase &database, User &newUser, Watched &watched, CurrentlyWatching &watching, ToBeWatched &willBeWatched, MenuTextView &textView);
    
    void display(std::string usrnm);


};
