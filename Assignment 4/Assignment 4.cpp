// Assignment 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Stacker.h"
#include <iostream>

using namespace std;

int main()
{
	string iFilename, oFilename;
	int files;
    cout << "What file do you wish to stack? "; 
	cin >> iFilename;
	cout << "\nWhat should the output file be named? ";
	cin >> oFilename;
	cout << "\nHow many files are there to be stacked? ";
	cin >> files;



	Stacker a = Stacker(iFilename);
	a.Stack(files);
	a.saveToDisk(oFilename);

}

