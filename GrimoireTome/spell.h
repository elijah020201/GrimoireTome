#pragma once

#include <string>
#include <vector>
#include "json.hpp"
using json = nlohmann::json;

class Spell
{
public:
    // --- Member Variables ---
    std::string name;
    std::string description;
    std::string category; // e.g., "Type of Spell"

   

    // --- Constructor ---
    Spell() = default;
    Spell(const std::string& name, const std::string& description, const std::string& category)
        : name(name), description(description), category(category)
    {
    }

    // --- Methods ---
    //display the spell's information
    void Print() const;
};

inline void to_json(json& j, const Spell& s) {
    j = json{
        {"name", s.name},
        {"description", s.description},
        {"category", s.category}
    };
}

inline void from_json(const json& j, Spell& s) {
    j.at("name").get_to(s.name);
    j.at("description").get_to(s.description);
    j.at("category").get_to(s.category);
}