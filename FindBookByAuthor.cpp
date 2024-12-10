#include "FindBookByAuthor.h"

FindBookByAuthor::FindBookByAuthor(const std::wstring i_name, std::shared_ptr<Library> i_pLibrary) :
	Menu(i_name, i_pLibrary), m_sMenuTitle(i_name), m_pLibrary(i_pLibrary)
{
}

void FindBookByAuthor::show()
{
	std::string authorName;
	std::wcout << "======================== LIBRARY MANAGEMENT SYSTEM ========================" << std::endl;
	std::wcout << "=                           FIND BOOK BY AUTHOR                           =" << std::endl;
	std::wcout << "===========================================================================" << std::endl;
	std::cout << "Enter the Author's name : ";
	std::getline(std::cin, authorName);
	m_pLibrary->findBooksByAuthor(authorName);
	std::cout << "Press anything to go back to main menu..." << std::endl;
	_getch();
}