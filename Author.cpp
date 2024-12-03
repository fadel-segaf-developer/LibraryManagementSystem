#include "Author.h"

bool Author::addWork(std::unique_ptr<LibraryItem> work)
{
    // Ensure no duplicate titles for the same author
    for (const auto& existingWork : works) {
        if (existingWork->getTitle() == work->getTitle()) {
            std::cout << "Error: Author already has a work titled '" << work->getTitle() << "'.\n";
            return false;
        }
    }
    works.push_back(std::move(work));
    return true;
}

void Author::displayWorks() const
{
    if (!works.empty()) {
        std::cout << "[ AUTHOR :" << name << " ] \n";
        for (const auto& work : works) {
            work->display();
        }
    }
    else {
        std::cout << "[ AUTHOR :" << name << " ] :\n - No works have been submitted yet - \n";
    }
}
