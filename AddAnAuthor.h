#pragma once
#include "Menu.h"
class AddAnAuthor :
    public Menu
{
public:
    AddAnAuthor(const std::wstring i_name, std::shared_ptr<Library> i_pLibrary);
    void show() override;

private:
    std::wstring m_sMenuTitle;
    std::shared_ptr<Library> m_pLibrary;
};

