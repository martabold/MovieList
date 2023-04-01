#pragma once
#include "Movie.hpp"
#include <vector>
#include <string>

class MovieDatabase
{
    private:
    Movie movie;
    std::vector<Movie> movies;

    public:
    MovieDatabase(Movie &movie);
    void viewAllData();
    void loadData(const std::string myBase);
    void viewRecord(std::istream & n);
    

};