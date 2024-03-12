#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;

void sea::ciin(ifstream& ist, int i, sea* arr)
{
	ist >> arr[i].nazvanie >> arr[i].glubina >> arr[i].solenost;
}

void sea::couut(int i, int k, sea* arr)
{
	cout << arr[k].nazvanie << " " << arr[k].glubina << " " << arr[k].solenost << endl;
}

void sea::vivod(int i, sea* arr)
{
	for (int k = 0; k < i; k++)
	{
		couut(i, k, arr);
	}
}

int sea::init(ifstream& ist)
{
	sea* arr = new sea[255];
	int i = 0;
	while (!ist.eof())
	{
		ciin(ist, i, arr);
		i += 1;
	}
	vivod(i, arr);
	return 0;
}
