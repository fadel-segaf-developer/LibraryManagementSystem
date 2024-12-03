#pragma once
#include "Book.h"
#include "Comic.h"
#include "Author.h"

class Library {
public:
    std::unordered_map<std::string, Author*> authors;
    std::vector<Book*> books;
    std::vector<Comic*> comics;
    ~Library();

    Author* addAuthor(const std::string& authorName);

    bool addLibraryItem(std::unique_ptr<LibraryItem> item, const std::string& authorName);

    void findBooksByAuthor(const std::string& authorName) const;

    void findAuthorByBook(const std::string& bookTitle) const;

    void displayLibrary() const;
};

