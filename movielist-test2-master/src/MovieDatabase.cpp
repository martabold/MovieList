#include "MovieDatabase.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

MovieDatabase::MovieDatabase(Movie &movie) : movie(movie)
{
    
}

void MovieDatabase::viewAllData()
{
    std::fstream myFile;
    myFile.open("lista.dsv", std::ios::in);
    if(myFile.is_open())
    {
        std::string line;
        while(getline(myFile, line, ';'))
        {
            std::cout<<line<<"\t";
            
        }
        std::cout<<std::endl;
    }
    myFile.close();

}

void MovieDatabase::loadData(const std::string myBase)
{
    std::ifstream myFile;
    myFile.open(myBase, std::ios::in);
    std::string a, b, c;
    std::string line;
    while(!(myFile.eof()))
    {
        getline(myFile, a, ';');
        getline(myFile, b, ';');
        getline(myFile, c, '\n');
        movies.push_back(Movie(a,b,c));
    }

}

void MovieDatabase::viewRecord(std::istream & n)
{
    int a;
    std::cout << "Enter the id of the movie you're looking for: ";
    n >> a;
    Movie temp = movies[a];
    std::cout << temp.getId() << " " << temp.getTitle() << " " <<temp.getYear() << std::endl;
}
