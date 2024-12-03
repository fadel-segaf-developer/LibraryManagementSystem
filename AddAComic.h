#pragma once
#include "Menu.h"
class AddAComic :
    public Menu
{
public:
    AddAComic(const std::wstring i_name, Library* i_pLibrary);
    void show() override;

private:
    std::wstring m_sMenuTitle;
    Library* m_pLibrary;
};

