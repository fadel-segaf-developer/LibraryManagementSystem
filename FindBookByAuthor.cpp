#include "FindBookByAuthor.h"

FindBookByAuthor::FindBookByAuthor(const std::wstring i_name, Library* i_pLibrary) :
	Menu(i_name, i_pLibrary), m_sMenuTitle(i_name), m_pLibrary(i_pLibrary)
{
}

void FindBookByAuthor::show()
{
	std::string authorName;
	std::cout << "===== Find a book by Author's name =====" << std::endl;
	std::cout << "Enter the Author's name : ";
	std::getline(std::cin, authorName);
	m_pLibrary->findBooksByAuthor(authorName);
	std::cout << "Press anything to go back to main menu..." << std::endl;
	_getch();
}