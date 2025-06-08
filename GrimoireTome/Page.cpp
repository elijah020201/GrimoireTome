#include <iostream>
#include "Page.h"
#include "json.hpp" 
using json = nlohmann::json;

//Add spell to pages internal list
void Page::AddSpell(const Spell& spell)
{
	spells.push_back(spell);
}

void Page::Print() const
{
    std::cout << "=============== Page " << pageNumber << " ===============" << std::endl;
    std::cout << std::endl;

    if (spells.empty())
    {
        std::cout << "(This page is empty)" << std::endl;
    }
    else
    {
        // Loop through all the spells on this page and print each one.
        // This re-uses the Spell::Print() function 
        for (const auto& spell : spells)
        {
            spell.Print();
        }
    }

    std::cout << "=======================================" << std::endl << std::endl;
}

