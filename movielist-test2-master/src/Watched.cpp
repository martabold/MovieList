#include "Watched.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

Watched::Watched(Movie &movie, std::string opinion) :
MovieDatabase(movie),
opinion(opinion)
{

}

void Watched::addToWatched(std::string p)
{   bool ok;
    std::string id, line, line2;
    std::fstream watched("watched.dsv", std::ios::in | std::ios::app);
    std::cout << "Select an id of a film you'd like to add to a list of watched movies: ";
    std::cin >> id;
    watched.seekg(0);
    if(watched.is_open())
    {
        while(!watched.eof())
        {
            getline(watched, line, ';');
            getline(watched, line2, '\n');
            if(id == line2)
            {
            std::cout << "You can't add the same movie twice." << std::endl;
            addToWatched(p);
            ok = true;
            break;

            }

        }
    }
    watched.clear();
    if(!ok)
    {
        watched << p <<";"<< id <<"\n";
    }
    
    
    
    watched.close();



}

std::string Watched::getOpinion()
{
    std::string opinion;
    std::cout<<"Your opinion about the movie you've just watched";
    std::cin>>opinion;
    return opinion;
}

void Watched::addOpinion(std::string p)
{
    int id; 
    std::cout<<"Enter an id of a movie you want to add an opinion about: ";
    std::cin>>id;
    std::string opinion=getOpinion();
    std::fstream myFile;
    std::ofstream opinions("opinion.dsv", std::ios_base::app);
    opinions<<id<<";"<<p<<';'<<opinion<<"\n";

}

void Watched::displayList(std::string username)
{
    std::fstream myFile;
    std::vector<int> ids;
    int idsL;
    std::string user,id,title,year, idF,a,b,c;
    myFile.open("watched.dsv", std::ios::in);
    if(myFile.is_open())
    {
        
        while (!myFile.eof())
        {
            getline(myFile,user,';');
            getline(myFile,id,'\n');
            if (username==user)
            {
                ids.push_back(std::stoi(id));
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

void Watched::displayOpinions(std::string username)
{
    std::fstream myFile;
    std::vector<int> ids;
    std::vector<std::string> hold;
    int idsL;
    std::string user,id, opinion,title,year, idF,a,b,c;
    myFile.open("opinion.dsv", std::ios::in);
    if(myFile.is_open())
    {
        
        while (!myFile.eof())
        {
            getline(myFile,id,';');
            getline(myFile,user,';');
            getline(myFile,opinion, '\n');
            if (username==user && id.length()>0)
            {
                hold.push_back(opinion);
                ids.push_back(std::stoi(id));
            }
        }
    }
    myFile.close();
    idsL=ids.size();
    //opinions = hold.size();
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
                    std::cout<<idF<<" | "<<title<< " | "<<year << " |  Opinion given to this movie: " ;

                    for(std::string i : hold)
                    {
                        std::cout << i << std::endl;
                    }
            
                    }
                }
            }
        }
    }
    myFile.close();
}
