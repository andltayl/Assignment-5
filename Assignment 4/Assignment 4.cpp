// Assignment 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Stacker.h"
#include <iostream>

using namespace std;

int main()
{
	string filename;
    cout << "Hello World!\n"; 
	cin >> filename;

	Stacker a = Stacker(filename);
	a.Stack(10);

}

