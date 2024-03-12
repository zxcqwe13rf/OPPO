// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "sea_additional.h"
#include "fish_additional.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>



bool fish::is_valid_name_fish(const std::string& name)
{
    for (size_t i = 0; i < name.size(); i++)
    {
        if (!(isalpha(name[i])))
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    return true;
}

 std::vector<fish> fish::read_fish(std::istream& ist)
{
    fish object1;
    std::string buf;
    size_t i = 1;
    std::string nameofffish;
    getline(ist, buf);
    if (buf.empty())
    {
        return {};
    }
    if (is_valid_name_fish(buf))
    {
        throw std::runtime_error("Некорректные данные!");
    }
    std::vector<fish> vect1;
    std::vector<fish> vect;
    while (buf[i])
    {
        if (buf[i] == ' ')
        {
             object1.nameoffish = nameofffish;
             vect1.push_back(object1);
             i++;
             nameofffish.clear();
        }
        nameofffish += buf[i];
        i++;
        if (i + 1 == buf.length())
        {
            nameofffish += buf[i];
            if (fish::is_valid_name_fish(nameofffish))
            {
                object1.nameoffish = nameofffish;
                vect1.push_back(object1);
            }
            else
            {
                std::cout << "Неккоректные данные! Проверьте вводимые поля рыб!";
                return vect;
            }
        }
        else
        {
            continue;
        }
    }
    std::vector<fish> result;
    for (size_t t = 0; t < vect1.size(); ++t) {
        if (!vect1[t].nameoffish.empty()) {
            result.push_back(vect1[t]);
        }
    }
    return result;
}
