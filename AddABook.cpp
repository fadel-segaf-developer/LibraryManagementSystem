#include "AddABook.h"
#include "Library.h"


AddABook::AddABook(const std::wstring i_name, std::shared_ptr<Library> i_pLibrary) :
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
	std::wcout << "======================== LIBRARY MANAGEMENT SYSTEM ========================" << std::endl;
	std::wcout << "=                               ADD A BOOK                                =" << std::endl;
	std::wcout << "===========================================================================" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	bookID = Library::getValidatedInput("Enter the book ID : ");
	std::cout << "Enter the book title : ";
	std::getline(std::cin, bookTitle);
	std::cout << "Enter the book author : ";
	std::getline(std::cin, bookAuthor);
	std::cout << "Enter the book genre : ";
	std::getline(std::cin, bookGenre);
	pageCount = Library::getValidatedInput("Enter the page count :");
	m_pLibrary->addLibraryItem(std::make_unique<Book>(bookID, bookTitle, bookAuthor, bookGenre, pageCount), bookAuthor);
	std::cout << "Book has been added to the library!" << std::endl;
	std::cout << "Press anything to go back to main menu..." << std::endl;
	_getch();
}