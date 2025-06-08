#include "Grimoire.h"
#include <iostream>
#include <fstream> 
#include <stdexcept>
#include "json.hpp" 
using json = nlohmann::json;

// Adds a page to the grimoire's list of pages
void Grimoire::AddPage(const Page& page)
{
    pages.push_back(page);
}

// Prints the Grimoire's information and all of its pages
void Grimoire::Print() const
{
    std::cout << "***************************************" << std::endl;
    std::cout << "          " << title << std::endl;
    std::cout << "             by " << author << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

    if (pages.empty())
    {
        std::cout << "This grimoire has no pages." << std::endl;
    }
    else
    {
        // Loop through all pages and call their Print() function.
        for (const auto& page : pages)
        {
            page.Print();
        }
    }
}

void Grimoire::saveToFile(const std::string& filename) const
{
    // 1. Convert this Grimoire object to a JSON object
    json j = *this;

    // 2. Open a file for writing
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Could not open file for writing: " + filename);
    }

    // 3. Write the JSON object to the file, with 4 spaces for indentation to make it readable
    outFile << j.dump(4) << std::endl;
}

Grimoire Grimoire::loadFromFile(const std::string& filename)
{
    // 1. Open a file for reading
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw std::runtime_error("Could not open file for reading: " + filename);
    }

    // 2. Parse the file content into a JSON object
    json j;
    inFile >> j;

    // 3. Convert the JSON object back into a Grimoire object and return it
    return j.get<Grimoire>();
}

