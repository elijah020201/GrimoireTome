#include "spell.h"
#include <iostream>

void Spell::Print() const {
	std::cout << "--- " << name << " ---" << std::endl;
	std::cout << "Category: " << category << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << std::endl;
}

