#include "AddAnAuthor.h"

AddAnAuthor::AddAnAuthor(const std::wstring i_name, Library* i_pLibrary) :
	Menu(i_name,i_pLibrary), m_sMenuTitle(i_name), m_pLibrary(i_pLibrary)
{
}

void AddAnAuthor::show()
{
	std::string AuthorName;
	std::wcout << "====== Add an Author ======" << std::endl;
	std::wcout << "Enter the Author's name : ";
	std::getline(std::cin, AuthorName);
	m_pLibrary->addAuthor(AuthorName);
	std::cout << "Author has been added to the library!" << std::endl;
	std::cout << "Press anything to go back to main menu..." << std::endl;
	_getch();
	
}
