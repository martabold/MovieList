#pragma once
#include <vector>
#include <string>


class Movie
{
    private:
    std::string id;
    std::string title;
    std::string year;


    public:
    Movie(std::string id, std::string title, std::string year);
    std::string getId();
    std::string getTitle();
    std::string getYear();
    void showData();
};