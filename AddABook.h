#pragma once
#include "Menu.h"
class AddABook :
    public Menu
{
public:
    AddABook(const std::wstring i_name, Library* i_pLibrary);
    void show() override;

private:
    std::wstring m_sMenuTitle;
    Library* m_pLibrary;
};

