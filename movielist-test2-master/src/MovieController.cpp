#include "MovieController.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

MovieController::MovieController(Movie &movie, MovieDatabase &database, User &newUser, Manager &manager, UserManager &userManager) :
movie(movie),
database(database),
newUser(newUser),
manager(manager),
userManager(userManager)
{

}


//tu mozna metode mainDisplay() sprobowac zrobic z std::optional
    //czy taki uzytkownik istnieje, jesli tak 
    //zwrocic opcjonalnego uzytkownika 
    //jesli nie znalazl, to tworzymy nowego uzytkownika

void MovieController::mainDisplay()
{
    std::string username;
    std::cout << "Enter the username: ";
    std::cin >> username;
    userManager.findUser(username);
}

