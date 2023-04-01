#include "MovieDatabase.hpp"
#include "Movie.hpp"
//#include "MovieUsers.hpp"
#include "Manager.hpp"
#include "Users.hpp"
#include "MovieController.hpp"
#include "Watched.hpp"
#include "CurrentlyWatching.hpp"
#include "ToBeWatched.hpp"
#include "UserManager.hpp"
#include "MenuTextView.hpp"
#include <iostream>

using namespace std;

int main() 
{
    Movie movie{"id", "title", "year"};
    MovieDatabase database{movie};
    User newUser{"username", "password"};
    //string username,password;
    
    Watched listOfWatched {movie, "opinion"};
    CurrentlyWatching listOfWatching {movie};
    ToBeWatched listOfToBeWatched {movie};
    MenuTextView textView{};
    
    Manager manager{movie, database, newUser, listOfWatched, listOfWatching, listOfToBeWatched, textView};
    UserManager usrmngr{newUser, manager};
    MovieController controller{movie, database, newUser, manager, usrmngr};
    
    
    //manager.existenceOfTheUser();
    //manager.display(); 
    //controller.display();
    controller.mainDisplay();
    //listOfWatched.addToWatched("");

    return 0;
}
