#include "FindAuthorByBook.h"


FindAuthorByBook::FindAuthorByBook(const std::wstring i_name, Library* i_pLibrary) :
	Menu(i_name, i_pLibrary), m_sMenuTitle(i_name), m_pLibrary(i_pLibrary)
{
}

void FindAuthorByBook::show()
{
	std::string bookTitle;
	std::wcout << "===== Find an Author by book name =====" << std::endl;
	std::wcout << "Enter the book's title : ";
	std::cin >> bookTitle;
	std::cin.ignore();
	m_pLibrary->findAuthorByBook(bookTitle);
	std::cout << "Press anything to go back to main menu..." << std::endl;
	_getch();

}