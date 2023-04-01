#include "MenuTextView.hpp"

MenuTextView::MenuTextView()
{

}

void MenuTextView::menuTextView(std::string usrnm)
{
    std::cout << "===========" << std::endl;
    std::cout << "Hi " << usrnm << "!" << std::endl;
    std::cout << "===========" << std::endl;
    std::cout << "Press 1 to see the whole movie database" <<std::endl;
    std::cout << "Press 2 to search for a movie"<< std::endl;
    std::cout << "Press 3 to go to 'Watched Movies'" << std::endl;
    std::cout << "Press 4 to go to 'Currently Watched'" << std::endl;
    std::cout << "Press 5 to go to 'To Be Watched'" << std::endl;
    std::cout << "Press 0 to exit the program" << std::endl;
}