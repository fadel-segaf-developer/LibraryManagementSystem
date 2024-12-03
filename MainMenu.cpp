#include "MainMenu.h"

MainMenu::MainMenu(const std::wstring i_name, std::shared_ptr<Library> i_pLibrary):
	Menu(i_name, i_pLibrary), m_sMenuTitle(i_name)
{
}

void MainMenu::show()
{
	std::wcout <<"====== Main Menu ======" << std::endl;
	std::wcout <<"(1) Add a book" << std::endl;
	std::wcout <<"(2) Add an author" << std::endl;
	std::wcout <<"(3) Find author by book " << std::endl;
	std::wcout <<"(4) Find book by author " << std::endl;
}
