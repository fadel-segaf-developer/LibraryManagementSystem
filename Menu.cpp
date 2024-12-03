#include "Menu.h"

std::vector<Menu*> Menu::menus;
int Menu::MenuCount = 1;
void Menu::AddNewMenu(Menu* i_pMenu)
{
    menus.push_back(i_pMenu);
    MenuCount += 1;
}
Menu::Menu(const std::wstring& i_name, Library* i_pLibrary):
    m_sMenuTitle(i_name), m_pLibrary(i_pLibrary), m_nMenuIndex(MenuCount)
{
    std::wcout << m_sMenuTitle << L" created with an index of " << m_nMenuIndex <<std::endl;
}

std::wstring Menu::getName()
{
    return m_sMenuTitle;
}
