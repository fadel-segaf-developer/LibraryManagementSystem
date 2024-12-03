#pragma once
#include <iostream>

class LibraryItem {
protected:
    int id;
    std::string title;

public:
    LibraryItem(int id, const std::string& title) : id(id), title(title) {}
    virtual ~LibraryItem() {}

    std::string getTitle() const;
    int getId() const;

    virtual void display() const = 0;// Pure virtual function for displaying details
};

