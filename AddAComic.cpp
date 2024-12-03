#include "AddAComic.h"


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
	std::cout << "====== Add a comic ======" << std::endl;
	std::cout << "Enter the comic ID : ";
	std::cin >> comicID;
	std::cin.ignore();  // Clear the newline character left in the buffer
	std::cout << "Enter the comic title : ";
	std::getline(std::cin, comicTitle);
	std::cout << "Enter the comic author : ";
	std::getline(std::cin, comicAuthor);
	std::cout << "Enter the comic illustrator : ";
	std::getline(std::cin, comicIllustrator);
	std::cout << "Enter the volume number : ";
	std::cin >> volumeNumber;
	std::cin.ignore();  // Clear the newline character left in the buffer
	m_pLibrary->addLibraryItem(std::make_unique<Comic>(comicID, comicTitle, comicAuthor, comicIllustrator, volumeNumber), comicAuthor);
	std::cout << "Comic has been added to the library!" << std::endl;
	std::cout << "Press anything to go back to main menu..." << std::endl;
	_getch();
}