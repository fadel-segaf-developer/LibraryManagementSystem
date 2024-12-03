#include "Book.h"

void Book::display() const
{
    std::cout << "< Book > ID: " << id << ", Title: " << title
        << ", Author: " << authorName << ", Genre: " << genre
        << ", Pages: " << pageCount << "\n";
}
