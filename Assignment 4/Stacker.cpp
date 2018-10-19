#include "Stacker.h"


Stacker::~Stacker()
{
}

Stacker::Stacker() {

}

Stacker::Stacker(string file)
{
	cout << filename << endl;
	ifstream iFile;

	iFile.open(file.c_str());
	getline(iFile, temp);

	iFile >> height >> width >> max_color;            // Store the number of rows and columns.

	
	cout << "\n" << height << width << max_color << endl;
	for (int i = 0; i < height*width; i++)
	{
		pixel a;
		iFile >> a.r >> a.g >> a.b;
		pixels.push_back(a);
	}
	/*for (int i = 0; i < width*height; i++)
	{
		cout << pixels[i].r << " " << pixels[i].g << " " << pixels[i].b;
		cout << endl;
	}*/
	
	for (int i = 0; i < 7; i++)
	{
		file.pop_back();
	}

	filename = file;

	iFile.close();
}

void Stacker::Stack(int numFiles) 
{
	for (int i=0; i < numFiles - 1; i++)
	{
		ifstream iFile;

		int currFile = i + 2;
		string fileNum = to_string(currFile);

		while (fileNum.size() < 3)
		{
			fileNum.insert(0, "0");
		}
		
		cout << filename + fileNum + ".ppm" << endl;


		iFile.open(filename.c_str());
		getline(iFile, temp);

		iFile >> height >> width >> max_color;

		/*for (int i = 0; i < height*width; i++)
		{
			pixel a;
			iFile >> a.r >> a.g >> a.b;
			pixels.push_back(a);
			//iFile.get();
		}*/
		iFile.close();
	}
}