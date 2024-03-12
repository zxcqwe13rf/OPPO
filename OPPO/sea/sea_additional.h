#pragma once
#include <iostream>
#include <vector>
#include "fish_additional.h"


struct sea
{
    std:: string name;

    double depth;

    double salinity;

    std::vector<sea> vect1;

    std::vector<fish> name_of_fish;

    static std::vector<sea> read_sea(std::istream& ist);

    static std::string read_name_of_sea(std::istream& ist);

    static const void write(const std::vector<sea> &vect, std::ostream& out);

    static std::vector<sea> initialization(std::istream& ist);
};
