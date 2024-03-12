#include <iostream>
#include <clocale>
#include <fstream>
#include <vector>
#include "sea_additional.h"
#include "fish_additional.h"


using namespace std;

int main()
{
    sea test;
    string path = "txt.txt";
    setlocale(LC_ALL, "ru");
    ifstream txt;
    txt.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        txt.open(path);
    }
    catch (const std::exception& ex)
    {
        cout << "Ошибка открытия файла!" << endl;
        cout << ex.what() << endl;
        return 0;
    }
    vector<sea> vect;
    vect = sea::initialization(txt);
    sea::write(vect, cout);
    return 0;
}
