#pragma once
#include "LibraryManagementSystem.h"
#include "Library.h"
#include <conio.h>  // For _kbhit() and _getch()
class Menu
{
public:
    static int MenuCount;
    static std::vector<Menu*> menus;
    // Static function to return a map of books and their names
    static std::map<Menu*, std::wstring> getAllMenus() {
        std::map<Menu*, std::wstring> menuMap;

        // Populate the map with Menu pointers and their names
        for (const auto& menu : menus) {
            menuMap[menu] = menu->getName();
        }

        return menuMap; // Return the sorted map
    }
    static void AddNewMenu(Menu* i_pMenu);

    

public:
    Menu(const std::wstring& i_name, Library* i_pLibrary);
    std::wstring getName();

    virtual void show() = 0;

    int getIndex()
    {
        return m_nMenuIndex;
    }
private:
    std::wstring m_sMenuTitle;
    Library* m_pLibrary;
    int m_nMenuIndex;
};

