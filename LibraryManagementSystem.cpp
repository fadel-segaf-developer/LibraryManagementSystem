// LibraryManagementSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "LibraryManagementSystem.h"
#include "Menu.h"
#include "AddABook.h"
#include "AddAComic.h"
#include "AddAnAuthor.h"
#include "FindAuthorByBook.h"
#include "FindBookByAuthor.h"

#include "Library.h"
using namespace std;

std::vector<Menu*> menuVector;
int input;
int activeMenuIndex = 99;
bool firstInput = false;
bool initDone = false;
std::shared_ptr<Library> libraryPtr = NULL;



void LibraryManagementSystem::Init()
{
    libraryPtr = std::make_shared<Library>();

    //Initial Data for example
    // Create and add a book
    libraryPtr->addLibraryItem(std::make_unique<Book>(1, "The Great Adventure", "John Smith", "Adventure", 300), "John Smith");

    // Create and add a comic
    libraryPtr->addLibraryItem(std::make_unique<Comic>(2, "Spider-Man", "Stan Lee", "Steve Ditko", 1), "Stan Lee");

    // Attempt to add a duplicate title for the same author
    libraryPtr->addLibraryItem(std::make_unique<Book>(3, "The Great Adventure", "John Smith", "Fiction", 250), "John Smith");

    // Add another comic by a different author
    libraryPtr->addLibraryItem(std::make_unique<Comic>(4, "Batman", "Bob Kane", "Jerry Robinson", 1), "Bob Kane");

    // Display the entire library
    libraryPtr->displayLibrary();

    //Initialize all menu
    Menu::AddNewMenu(new AddABook(L"Add a book", libraryPtr));
    Menu::AddNewMenu(new AddAComic(L"Add a comic", libraryPtr));
    Menu::AddNewMenu(new AddAnAuthor(L"Add an author", libraryPtr));
    Menu::AddNewMenu(new FindAuthorByBook(L"Find the author of a book", libraryPtr));
    Menu::AddNewMenu(new FindBookByAuthor(L"Search for books by an author", libraryPtr));
 }

void LibraryManagementSystem::MainMenu()
{
    activeMenuIndex = 99;
    clearScreen();
    std::wcout << "======================== LIBRARY MANAGEMENT SYSTEM ========================" << std::endl;
    std::wcout << "=  Fadel Achmad Assegaf(fadelsegaf.developer@gmail.com) - FRYS Developer  =" << std::endl;
    std::wcout << "===========================================================================" << std::endl;
    std::cout<< std::endl;

    std::map<Menu*, std::wstring> menuMap = Menu::getAllMenus();
    int menuSize = menuMap.size();
    int i = 1;
    while (i < menuSize)
    {
        for (const auto& entry : menuMap)
        {
            //if index is correct
            if (entry.first->getIndex() == i)
            {
                if (!initDone)
                {
                    menuVector.push_back(entry.first);
                    
                }
                std::wcout << "(" << i << ") " << entry.second << std::endl;
                i += 1;
            }
        }
    }
    initDone = true;

    std::wcout << "(99) Display library" << std::endl;

    std::wcout << std::endl<< "Enter menu index : ";
}

void LibraryManagementSystem::UserInput()
{
    if (activeMenuIndex == 99)
    {
        input = -1;
        int numChoices = menuVector.size();
        string inputStr;

        // Read the input as a string
        std::getline(std::cin, inputStr);

        // Convert the string to an int using std::stringstream
        std::stringstream ss(inputStr);
        ss >> input;

        if (input >= 1 && input <= numChoices) {
            firstInput = false;
            activeMenuIndex = input - 1;
            clearScreen();
            menuVector[activeMenuIndex]->show();

        }
        else if (input == 99)
        {
            clearScreen();
            std::wcout << "======================== LIBRARY MANAGEMENT SYSTEM ========================" << std::endl;
            std::wcout << "=                             LIBRARY DATA                                =" << std::endl;
            std::wcout << "===========================================================================" << std::endl;
            std::cout << std::endl;
            libraryPtr->displayLibrary();
            std::cout << std::endl << "Press anything to go back to main menu..." << std::endl;
            _getch();

        }
        else {
                std::cout << "\033[A\033[K";
                std::cout << "\033[A\033[K";
                std::cout << "Invalid choice! Please select a valid option." << std::endl;
                std::wcout  << "Enter menu index : ";
                activeMenuIndex = 99;
                UserInput();
        }
            
    }
        
}  


int main()
{
    LibraryManagementSystem::Init();
    while (true)
    {
        LibraryManagementSystem::MainMenu();
        LibraryManagementSystem::UserInput();
    }
    
}

void LibraryManagementSystem::clearScreen() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Unix/Linux
#endif
}



