#include "Library.h"



std::unique_ptr<Author>& Library::addAuthor(const std::string& authorName)
{
    if (authors.find(authorName) == authors.end()) {
        authors[authorName] = std::make_unique<Author>(authorName);
    }
    return authors[authorName];
}

bool Library::addLibraryItem(std::unique_ptr<LibraryItem> item, const std::string& authorName)
{
    
    std::unique_ptr<Author>& author = addAuthor(authorName);
    if (author->addWork(std::move(item))) {
        return true;
    }
    return false; // Failed to add (e.g., duplicate title)
}

void Library::findBooksByAuthor(const std::string& authorName) const
{
    auto it = authors.find(authorName);
    if (it != authors.end()) {
        if (!it->second->getWorks().empty())
        {
            std::cout << "Books by " << authorName << ":\n";
            for (const auto& item : it->second->getWorks()) {
                item->display();
            }
        }
        else
        {
            std::cout << authorName << " doesn't have any books yet.\n";
        }
    }
    else {
        std::cout << "Author '" << authorName << "' not found.\n";
    }
}

void Library::findAuthorByBook(const std::string& bookTitle) const
{
    for (const auto& pair : authors) {
        for (const auto& item : pair.second->getWorks()) {
            if (item->getTitle() == bookTitle) {
                std::cout << "The author of the book '" << bookTitle << "' is " << pair.second->getName() << ".\n";
                return;
            }
        }
    }
    std::cout << "Book with title '" << bookTitle << "' not found.\n";
}

void Library::displayLibrary() const
{
    for (const auto& pair : authors) {
        pair.second->displayWorks();
    }
}

int Library::getValidatedInput(const std::string& prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "\033[A\033[K";
            std::cout << "\033[A\033[K";
            std::cout << "Invalid input. Please enter a numeric value." << std::endl;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline
            return value; // Valid input
        }
    }
}
