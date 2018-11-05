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
	string magic_number; //this is the p3 value
	string filename, temp; // this string will allow us to open the users sample file
	int width; // how wide the image will be
	int height; // how tall the image will be
	int max_color; // the maximum color depth
	vector <pixel> pixels; // the vector of pixels we need to create the image 
	Stacker(string file);
	/* 
	 *Description: this will open the input file given by the users and then store values into the pixel vector
	 *Inputs: string file which is the file the user wants to use to create an image
	 */
	void Stack(int numFiles);
	void saveToDisk(string outfile);
};

