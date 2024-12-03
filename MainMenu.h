#pragma once
#include "Menu.h"

class MainMenu :
    public Menu
{
public:
    MainMenu(const std::wstring i_name, std::shared_ptr<Library> i_pLibrary);

    void show() override;

private:
    std::wstring m_sMenuTitle;
};

