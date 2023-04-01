#include "MovieDatabase.hpp"
#include "Movie.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

Movie::Movie(std::string id, std::string title, std::string year) :
id(id), title(title), year(year)
{

}   

std::string Movie::getId()
{
    return id;
}

std::string Movie::getTitle()
{
    return title;
}

std::string Movie::getYear()
{
    return year;
}

void Movie::showData()
{
    std::cout << "Movie id: " << getId() << std::endl;
}