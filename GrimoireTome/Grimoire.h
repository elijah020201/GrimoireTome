#pragma once

#include "Page.h"
#include <string>
#include <vector>
#include "json.hpp"
using json = nlohmann::json;

class Grimoire
{
public:
    // --- Member Variables ---
    std::string title;
    std::string author;
    std::vector<Page> pages;

    // --- Constructor ---
    // Creates a new grimoire with a title and author
    Grimoire() = default;
    Grimoire(const std::string& title, const std::string& author)
        : title(title), author(author)
    {
    }

    // --- Methods ---
    void AddPage(const Page& page); // Adds a completed page to the grimoire
    void Print() const; // Prints grimoire, cover to cover
    void saveToFile(const std::string& filename) const;
    static Grimoire loadFromFile(const std::string& filename);
};

inline void to_json(json& j, const Grimoire& g) {
    j = json{
        {"title", g.title},
        {"author", g.author},
        {"pages", g.pages}
    };
}

inline void from_json(const json& j, Grimoire& g) {
    j.at("title").get_to(g.title);
    j.at("author").get_to(g.author);
    j.at("pages").get_to(g.pages);
}