#include <iostream>
#include <clocale>
#include <fstream>
#include "Header.h"


using namespace std;

int main()
{
	sea t;
	setlocale(LC_ALL, "ru");
	ifstream txt("txt.txt");
	t.init(txt);
	return 0;
}