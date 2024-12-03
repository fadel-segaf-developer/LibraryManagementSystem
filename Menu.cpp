#include "Menu.h"

std::map<Menu*, std::wstring> Menu::m_menuMap;
int Menu::MenuCount = 1;

std::map<Menu*, std::wstring> Menu::getAllMenus()
{
    return m_menuMap; // Return the sorted map
    
}
void Menu::AddNewMenu(Menu* i_pMenu)
{
    m_menuMap[i_pMenu] = i_pMenu->getName();
    MenuCount += 1;
}
Menu::Menu(const std::wstring& i_name, std::shared_ptr<Library> i_pLibrary):
    m_sMenuTitle(i_name), m_pLibrary(i_pLibrary), m_nMenuIndex(MenuCount)
{
    std::wcout << m_sMenuTitle << L" created with an index of " << m_nMenuIndex <<std::endl;
}

std::wstring Menu::getName()
{
    return m_sMenuTitle;
}
