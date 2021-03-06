#include "Stacker.h"

Stacker::Stacker(string file)
{
	ifstream iFile;

	magic_number = "P3";

	iFile.open(file.c_str());
	getline(iFile, temp);

	iFile >> height >> width >> max_color;            // Store the number of rows and columns.

	for (int i = 0; i < height*width; i++)
	{
		pixel a;
		iFile >> a.r >> a.g >> a.b;
		pixels.push_back(a);
	}

	for (int i = 0; i < 7; i++)						// get rid of the last 7 characters in the filename (001.ppm)
	{
		file.pop_back();
	}

	filename = file;

	iFile.close();
}

void Stacker::Stack(int numFiles) 
{
	int tempFileNum = 1;		// Created to keep track of the number of files so that I dont have to convert the string to an int.

	for (int i=0; i < numFiles - 1; i++)
	{
		ifstream iFile;

		int currFile = i + 2;
		string fileNum = to_string(currFile);

		while (fileNum.size() < 3)
		{
			fileNum.insert(0, "0");
		}
		
		cout << filename + fileNum + ".ppm" << endl; // use this to generate what file to open


		iFile.open((filename + fileNum + ".ppm").c_str());
		getline(iFile, temp);

		iFile >> height >> width >> max_color;

		for (int i = 0; i < height*width; i++)
		{
			pixel a;
			iFile >> a.r >> a.g >> a.b;
			pixels[i].r += a.r;				// do the adding of the pixels
			pixels[i].g += a.g;
			pixels[i].b += a.b;			
		}

		iFile.close();
		tempFileNum++;
	}

	for (int i = 0; i < height*width; i++)
	{
		pixels[i].r /= tempFileNum;				// do the adding of the pixels
		pixels[i].g /= tempFileNum;
		pixels[i].b /= tempFileNum;
	}
}

void Stacker::saveToDisk(string outfile)
{
	ofstream oFile;

	oFile.open(outfile.c_str());

	oFile << magic_number << endl                                 // Prints header at beginning of file.
		<< height << " " << width << "\n"
		<< max_color << "\n";

	for (int i = 0; i < width*height; i++)
	{
		oFile << pixels[i].r << " " << pixels[i].g << " " << pixels[i].b;
		oFile << '\n';
	}

	oFile.close();
}