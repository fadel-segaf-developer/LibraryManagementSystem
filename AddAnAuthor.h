#pragma once
#include "Menu.h"
class AddAnAuthor :
    public Menu
{
public:
    AddAnAuthor(const std::wstring i_name, Library* i_pLibrary);
    void show() override;

private:
    std::wstring m_sMenuTitle;
    Library* m_pLibrary;
};

