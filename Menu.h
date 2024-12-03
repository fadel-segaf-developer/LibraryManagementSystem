#pragma once
#include "LibraryManagementSystem.h"
#include "Library.h"
#include <conio.h>  // For _kbhit() and _getch()
class Menu
{
public:
    static int MenuCount;
    static std::map<Menu*, std::wstring> m_menuMap;
    static std::map<Menu*, std::wstring> getAllMenus();
    static void AddNewMenu(Menu* i_pMenu);

public:
    Menu(const std::wstring& i_name, std::shared_ptr<Library> i_pLibrary);
    std::wstring getName();

    virtual void show() = 0;

    int getIndex()
    {
        return m_nMenuIndex;
    }
private:
    std::wstring m_sMenuTitle;
    
    std::shared_ptr<Library> m_pLibrary;
    int m_nMenuIndex;
};

