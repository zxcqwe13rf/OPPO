#pragma once
#include <iostream>

using namespace std;

struct sea
{
    string nazvanie;

    double glubina;

    double solenost;

    void ciin(ifstream& ist, int i, sea* arr);
    
    void couut(int i, int k, sea* arr);
    
    void vivod(int i, sea* arr);  
    
    int init(ifstream& ist);
};

