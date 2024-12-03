# LibraryManagementSystem

A console application for managing a library, with features including:

- Adding comics
- Adding books
- Searching for authors by books/comics
- Searching for books/comics by author

### Additional Features:
- The class structure is designed with scalability in mind. Menu pages are constructed through an initialized function in `libraryManagementSystem.cpp` (which contains `int main()`). This structure allows for easy expansion—future menus can be added simply by creating new classes derived from the existing menu system.
- Utilizes smart pointers for all pointer management, ensuring better memory management and preventing memory leaks.
