#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "LibraryItem.h"

class Author {
    std::string name;
    std::vector<std::unique_ptr<LibraryItem>> works;

public:
    explicit Author(const std::string& name) : name(name) {}

    
    bool addWork(std::unique_ptr<LibraryItem> work);

    void displayWorks() const;

    const std::vector<std::unique_ptr<LibraryItem>>& getWorks() const { return works; }
    const std::string& getName() const { return name; }
};

