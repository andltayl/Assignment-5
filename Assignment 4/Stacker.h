#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct pixel {
	int r;
	int g;
	int b;
};
class Stacker
{
public:
	string magic_number;
	string filename, temp;
	int width;
	int height;
	int max_color;
	vector <pixel> pixels;
	Stacker(string file);
	Stacker();
	~Stacker();
	void Stack(int numFiles);
};

