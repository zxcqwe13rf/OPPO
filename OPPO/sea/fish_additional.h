#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>


struct fish
{
    std::string nameoffish;

    static bool is_valid_name_fish(const std::string& name);

    static std::vector<fish> read_fish(std::istream& ist);

};
