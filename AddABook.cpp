#include "AddABook.h"


AddABook::AddABook(const std::wstring i_name, Library* i_pLibrary) :
	Menu(i_name, i_pLibrary), m_sMenuTitle(i_name), m_pLibrary(i_pLibrary)
{
}

void AddABook::show()
{
	int bookID;
	std::string bookTitle;
	std::string bookAuthor;
	std::string bookGenre;
	int pageCount;
	std::cout << "====== Add a book ======" << std::endl;
	std::cout << "Enter the book ID : ";
	std::cin >> bookID;
	std::cin.ignore();  // Clear the newline character left in the buffer
	std::cout << "Enter the book title : ";
	std::getline(std::cin, bookTitle);
	std::cout << "Enter the book author : ";
	std::getline(std::cin, bookAuthor);
	std::cout << "Enter the book genre : ";
	std::getline(std::cin, bookGenre);
	std::cout << "Enter the page count : ";
	std::cin >> pageCount;
	std::cin.ignore();  // Clear the newline character left in the buffer
	m_pLibrary->addLibraryItem(std::make_unique<Book>(bookID, bookTitle, bookAuthor, bookGenre, pageCount), bookAuthor);
	std::cout << "Book has been added to the library!" << std::endl;
	std::cout << "Press anything to go back to main menu..." << std::endl;
	_getch();
}