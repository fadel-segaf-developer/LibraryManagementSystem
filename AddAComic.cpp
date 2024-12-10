#include "AddAComic.h"
#include "Library.h"


AddAComic::AddAComic(const std::wstring i_name, std::shared_ptr<Library> i_pLibrary) :
	Menu(i_name, i_pLibrary), m_sMenuTitle(i_name), m_pLibrary(i_pLibrary)
{
}

void AddAComic::show()
{
	int comicID;
	std::string comicTitle;
	std::string comicAuthor;
	std::string comicIllustrator;
	int volumeNumber;
	std::wcout << "======================== LIBRARY MANAGEMENT SYSTEM ========================" << std::endl;
	std::wcout << "=                              ADD A COMIC                                =" << std::endl;
	std::wcout << "===========================================================================" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	comicID = Library::getValidatedInput("Enter the comic ID : ");
	std::cout << "Enter the comic title : ";
	std::getline(std::cin, comicTitle);
	std::cout << "Enter the comic author : ";
	std::getline(std::cin, comicAuthor);
	std::cout << "Enter the comic illustrator : ";
	std::getline(std::cin, comicIllustrator);
	volumeNumber = Library::getValidatedInput("Enter the volume number : ");
	m_pLibrary->addLibraryItem(std::make_unique<Comic>(comicID, comicTitle, comicAuthor, comicIllustrator, volumeNumber), comicAuthor);
	std::cout << "Comic has been added to the library!" << std::endl;
	std::cout << "Press anything to go back to main menu..." << std::endl;
	_getch();
}
