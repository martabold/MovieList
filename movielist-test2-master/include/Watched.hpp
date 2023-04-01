#pragma once
#include "Movie.hpp"
#include "MovieDatabase.hpp"
#include <vector>
#include <string>

class Watched : public MovieDatabase
{
    private:
    std::string opinion;
    std::vector<Movie> watchedMovies;

    public:
    Watched(Movie &movie, std::string opinion);
    void addToWatched(std::string p);
    std::string getOpinion();
    void addOpinion(std::string opinion);
    void displayList(std::string username);
    void displayOpinions(std::string username);


};