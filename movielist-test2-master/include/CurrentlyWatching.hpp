#pragma once
#include "Movie.hpp"
#include "MovieDatabase.hpp"
#include <vector>
#include <string>

class CurrentlyWatching : public MovieDatabase
{
    private:
    //std::vector<Movie> currentlyWatching;

    public:
    CurrentlyWatching(Movie &movie);
    void addToCurrentlyWatching(std::string p);
    void displayList(std::string username);

};