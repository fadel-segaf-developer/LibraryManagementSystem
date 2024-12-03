#pragma once
#include "LibraryItem.h"
class Book : public LibraryItem
{
    std::string authorName;
    std::string genre;
    int pageCount;

public:
    Book(int id, const std::string& title, const std::string& authorName,
        const std::string& genre, int pageCount)
        : LibraryItem(id, title), authorName(authorName), genre(genre), pageCount(pageCount) {}

    std::string getAuthorName() const { return authorName; }
    std::string getGenre() const { return genre; }
    int getPageCount() const { return pageCount; }

    void display() const override;
};

