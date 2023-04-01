#include "ToBeWatched.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

ToBeWatched::ToBeWatched(Movie &movie) : MovieDatabase(movie)
{

}

void ToBeWatched::addMoviesToBeWatched(std::string p)
{
    bool ok;
    std::string id, line, line2;
    std::fstream willWatch("tobewatched.dsv", std::ios::in | std::ios::app);
    std::cout << "Select an id of a film you'd like to add to a list of movies that you will watch in the future: ";
    std::cin >> id;
    willWatch.seekg(0);
    if(willWatch.is_open())
    {
        while(!willWatch.eof())
        {
            getline(willWatch, line, ';');
            getline(willWatch, line2, '\n');
            if(id == line2)
            {
            std::cout << "You can't add the same movie twice." << std::endl;
            addMoviesToBeWatched(p);
            ok = true;
            break;

            }

        }
    }
    willWatch.clear();
    if(!ok)
    {
        willWatch << p <<";"<< id <<"\n";
    }
    
    
    
    willWatch.close();
    
}

void ToBeWatched::displayList(std::string username)
{
    std::fstream myFile;
    std::vector<int> ids;
    int idsL;
    std::string user,id,title,year, idF,a,b,c;
    myFile.open("tobewatched.dsv", std::ios::in);
    if(myFile.is_open())
    {
        
        while (!myFile.eof())
        {
            getline(myFile,user,';');
            getline(myFile,id,'\n');
            if (username==user)
            {
                ids.push_back(stoi(id));
            }
        }
    }
    myFile.close();
    idsL=ids.size();
    myFile.open("lista.dsv");
    if(myFile.is_open())
    {
    getline(myFile,a);
    while(!myFile.eof())
        {
            getline(myFile,idF,';');
            getline(myFile,title,';');
            getline(myFile,year,'\n');
            if(myFile)
            {
            for (int i=0;i<idsL;i++)
                {
                if (ids[i]==stoi(idF))
                    {
                    std::cout<<idF<<" | "<<title<< " | "<<year<<'\n';
            
                    }
                }
            }
        }
    }
    myFile.close();
}