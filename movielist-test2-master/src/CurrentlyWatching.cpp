#include "CurrentlyWatching.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

CurrentlyWatching::CurrentlyWatching(Movie &movie) :
MovieDatabase(movie)
{

}

void CurrentlyWatching::addToCurrentlyWatching(std::string p)
{
    bool ok;
    std::string id, line, line2;
    std::fstream watching("currentlywatching.dsv", std::ios::in | std::ios::app);
    std::cout << "Select an id of a film you'd like to add to a list of currently watched movies, press 0 to cancel"<<"\n"<<": ";
    std::cin >> id;
    if (id=="0")
    {
        return;
    }
    watching.seekg(0);
    if(watching.is_open())
    {
        while(!watching.eof())
        {
            getline(watching, line, ';');
            getline(watching, line2, '\n');
            if(id == line2)
            {
            std::cout << "You can't add the same movie twice." << std::endl;
            addToCurrentlyWatching(p);
            ok = true;
            break;

            }

        }
    }
    watching.clear();
    if(!ok)
    {
        watching << p <<";"<< id <<"\n";
    }
    
    
    
    watching.close();

}

void CurrentlyWatching::displayList(std::string username)
{
    std::fstream myFile;
    std::vector<int> ids;
    int idsL;
    std::string user,id,title,year, idF,a,b,c;
    myFile.open("currentlywatching.dsv", std::ios::in);
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