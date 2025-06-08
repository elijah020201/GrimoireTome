#pragma once

#include "spell.h" // Lets page know what a spell is
#include <vector> // Page will hold a list (vector) of spells
#include <string>
#include "json.hpp"
using json = nlohmann::json;

class Page
{
public:
		// --Member Variables--
		int pageNumber;
		std::vector<Spell> spells; //List to hold all Spell Objects on a page

	//-- Constructor --
	//Create new page with page number 
		Page() = default;
	Page(int pageNum) : pageNumber(pageNum) {

	}
	// -- Methods --
	void AddSpell(const Spell& spell); //Add a spell to page list
	void Print() const; // Print page number and all spells on it
};

inline void to_json(json& j, const Page& p) {
	j = json{
		{"pageNumber", p.pageNumber},
		{"spells", p.spells} // This will automatically convert every spell in the list!
	};
}

inline void from_json(const json& j, Page& p) {
	j.at("pageNumber").get_to(p.pageNumber);
	j.at("spells").get_to(p.spells);
}