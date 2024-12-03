#pragma once
#include "LibraryItem.h"

class Comic : public LibraryItem {
    std::string authorName;
    std::string illustrator;
    int volumeNumber;

public:
    Comic(int id, const std::string& title, const std::string& authorName,
        const std::string& illustrator, int volumeNumber)
        : LibraryItem(id, title), authorName(authorName), illustrator(illustrator), volumeNumber(volumeNumber) {}

    void display() const override;
};


