#include "UserManager.hpp"
#include "Manager.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

UserManager::UserManager(User &newUser, Manager &manager) : newUser(newUser), manager(manager)
{

}

void UserManager::registration(std::vector<User> &newUsers)
{
    bool ok;
    std::string a,b;
    
    std::fstream users("users.dsv", std::ios::in | std::ios::app /*std::ios_base::app*/);
    std::string username,password;
    std::cout << "Enter your username: ";
    std::cin>>username;
    users.seekg(0);
    if(users.is_open())
    {
        while(!users.eof())
        {
            getline(users, a, ';');
            getline(users, b, '\n');
            newUsers.push_back(User(a,b));
            if(a == username)
            {
                std::cout << "This username already exists" << std::endl;
                registration(newUsers);
                ok = true;
                break;
            }

        }
        users.clear();
        if(!ok)
        {
            std::cout << "Enter your password: ";
            std::cin>>password;
            users << username<<";"<<password<<"\n";
        }
        users.close();
    }

    
    
    manager.display(username);

}

void UserManager::findUser(std::string name)
{
    bool isFound;
    std::string line, line2;
    std::fstream myFile;
    std::string x=name;
    myFile.open("users.dsv");
    if(myFile.is_open())
    {
        while(!myFile.eof())
        {
            getline(myFile, line, ';');
            getline(myFile, line2, '\n');
            if((line.find(name)) != std::string::npos)
            {
                std::cout << "The username " << name <<" already exists." <<std::endl;
                checkPassword(name);
                manager.display(x);
                isFound = true;
                break;
            }
            
            
        }
            if(!isFound)
            {
                std::cout << "The username " << name <<" doesn't exist." <<std::endl;
                registration(newUsers);
            }
            
            
        myFile.close();
     
    }
    else
    {
        std::cout << "Error" <<std::endl;
    }
}

void UserManager::checkPassword(std::string z)
{
    bool ok;
    std::fstream myFile;
    myFile.open("users.dsv");
    std::string pass, c, b, line;
    std::cout << "Enter your username's password: ";
    std::cin >> pass;
    if(myFile.is_open())
    {
        while(!myFile.eof())
        {
            getline(myFile, c, ';');
            getline(myFile, b, '\n');
            newUsers.push_back(User(c,b));
            if((pass == b) && (z == c))
            {
                std::cout << "Correct password!"<<std::endl;
                ok = true;
                break;
            }
        }
        if(!ok)
            {
                std::cout << "Incorrect password! You can try again." <<std::endl;
                checkPassword(z);
            }
            
        myFile.close();
    }
    else
    {
        std::cout << "error" <<std::endl;
    }
}

void UserManager::loadUsers(const std::string myBase)
{
    std::ifstream myFile;
    myFile.open(myBase, std::ios::in);
    std::string a, b;
    std::string line;
    while(!(myFile.eof()))
    {
        getline(myFile, a, ';');
        getline(myFile, b, '\n');
        newUsers.push_back(User(a,b));
    }
}

void findUsername(std::vector<User> &newUsers)
{
    bool ok;
    std::fstream myFile;
    myFile.open("users.dsv");
    std::string a, b, c;
    std::string line;
    std::cout << "Enter user's name to find it: ";
    std::cin >> c;
    if(myFile.is_open())
    {
        while(!myFile.eof())
        {
            getline(myFile, a, ';');
            getline(myFile, b, '\n');
            newUsers.push_back(User(a,b));
                if(c == a)
                {
                    std::cout << c << " " << b << std::endl;
                    ok = true;
                    break;
                }
                
         }
            if(!ok)
            {
                std::cout << "Not found" <<std::endl;
            }
            
        myFile.close();     
    }
    else
    {
        std::cout << "error" <<std::endl;
    }
}