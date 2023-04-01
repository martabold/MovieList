#pragma once
#include "Movie.hpp"
#include "MovieDatabase.hpp"
#include <vector>
#include <string>

class ToBeWatched : public MovieDatabase
{
    private:
    //std::vector<Movie> willBeWatched;

    public:
    ToBeWatched(Movie &movie);
    void addMoviesToBeWatched(std::string p);
    void displayList(std::string username);
    

};

