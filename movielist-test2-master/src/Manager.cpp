#include "Manager.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <optional>


Manager::Manager(Movie &movie, MovieDatabase &database, User &newUser, Watched &watched, CurrentlyWatching &watching, ToBeWatched &willBeWatched, MenuTextView &textView) : 
movie(movie), 
database(database),
newUser(newUser),
watched(watched),
watching(watching),
willBeWatched(willBeWatched),
textView(textView)
{

}

void Manager::display(std::string usrnm)
{
    while(1)
    {
    textView.menuTextView(usrnm);

    int choice;
    std::cin >> choice;

    switch(choice)
    {
        case 1:
        system("clear");
        database.viewAllData();
        break;

        case 2:
        system("clear");
        database.loadData("lista.dsv");
        database.viewRecord(std::cin);
        std::cout<<std::endl;  
        break;

        case 3:
        system("clear");
        std::cout << "Press 1 to add a film to the 'Watched Movies' list." <<std::endl;
        std::cout << "Press 2 to see the whole list." << std::endl;
        std::cout << "Press 3 to add an opinion about a film." << std::endl;
        std::cout << "Press 4 to see your added opinions." << std::endl;
        std::cout << "Press 0 to return to menu." << std::endl;
        
        int choice;
        std::cin >> choice;
        switch(choice)
        {
            case 1:
            system("clear");
            watched.addToWatched(usrnm);
            break;

            case 2:
            watched.displayList(usrnm);
            break;

            case 3:
            system("clear");
            watched.addOpinion(usrnm);
            break;

            case 4:
            watched.displayOpinions(usrnm);
            break;

            case 0:
            break;

            default:
            std::cout <<"You've pressed a wrong number!" << std::endl;
            break;

        }
        
        break;

        case 4:
        system("clear");
        std::cout << "Press 1 to add a film to the 'Currently Watched' list." <<std::endl;
        std::cout << "Press 2 to see the whole list." << std::endl;
        std::cout << "Press 0 to return to menu." << std::endl;
        int choice2;
        std::cin >> choice2;
        switch(choice2)
        {
            case 1:
            system("clear");
            watching.addToCurrentlyWatching(usrnm);
            break;

            case 2:
            watching.displayList(usrnm);
            break;

            case 0:
            break;

            default:
            std::cout <<"You've pressed a wrong number!" << std::endl;
            break;
        }
        
        break;

        case 5:
        system("clear");
        std::cout << "Press 1 to add a film to the 'To Be Watched' list." <<std::endl;
        std::cout << "Press 2 to see the whole list." << std::endl;
        std::cout << "Press 0 to return to menu." << std::endl;
        int choice3;
        std::cin >> choice3;
        switch(choice3)
        {
            case 1:
            system("clear");
            willBeWatched.addMoviesToBeWatched(usrnm);
            break;

            case 2:
            willBeWatched.displayList(usrnm);
            break;

            case 0:
            break;

            default:
            std::cout <<"You've pressed a wrong number!" << std::endl;
            break;
        }
        
        break;

        case 0:
        exit(1);

        default:
        std::cout <<"You've pressed a wrong number!" << std::endl;
        break;
    }
    }
}
