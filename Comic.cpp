#include "Comic.h"

void Comic::display() const
{
    std::cout << "< Comic > ID: " << id << ", Title: " << title
        << ", Author: " << authorName << ", Illustrator: " << illustrator
        << ", Volume: " << volumeNumber << "\n";
}
