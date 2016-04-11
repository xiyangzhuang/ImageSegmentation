#pragma once
#include <vector>
#include <string>
#include "PictureHandler.h"
#include "SLIC.h"
#include "SuperpixelSLIC.h"
using namespace std;

void readLabel(char *datpath, char *outputcsvpath, int width, int height);

void doSuperpixelSegmentation(char* image_path, char* saveLocation, int m_spcount, int m_compactness){
	PictureHandler picHand;
	vector<string> picvec(0);
	picvec.resize(0);
	string path = image_path;
	picvec.push_back(image_path);//user chooses one or more pictures
	
	string savLocation = saveLocation;
	// BrowseForFolder(saveLocation);
	int numPics( picvec.size() );

	for( int k = 0; k < numPics; k++ )
	{
		UINT* img = NULL;
		int width(0);
		int height(0);
		
		picHand.GetPictureBuffer( picvec[k], img, width, height );

		int sz = width*height;
		//---------------------------------------------------------
		if(m_spcount < 20 || m_spcount > sz/4) m_spcount = sz/200;//i.e the default size of the superpixel is 200 pixels
		if(m_compactness < 1.0 || m_compactness > 80.0) m_compactness = 20.0;
		//---------------------------------------------------------
		int* labels = new int[sz];
		int numlabels(0);
		SLIC slic;
		slic.DoSuperpixelSegmentation_ForGivenNumberOfSuperpixels(img, width, height, labels, numlabels, m_spcount, m_compactness);
		slic.SaveSuperpixelLabels(labels, width, height, picvec[k], savLocation);
		//slic.DoSuperpixelSegmentation_ForGivenSuperpixelSize(img, width, height, labels, numlabels, 10, m_compactness);//demo
		slic.DrawContoursAroundSegments(img, labels, width, height, 0);
		if(labels){
			delete [] labels;
		}
		picHand.SavePicture(img, width, height, picvec[k], savLocation, 1, "_SLIC");// 0 is for BMP and 1 for JPEG)
	}
}

void readLabel(char *datpath, char *outputcsvpath, int width, int height){
	//char *filepath = "C:\\Users\\Admin\\Documents\\Visual Studio 2013\\Projects\\ConsoleApplication1\\Release\\beauty.dat";
	//char *outputfilepath = "C:\\Users\\Admin\\Documents\\Visual Studio 2013\\Projects\\ConsoleApplication1\\Release\\beauty.txt";
	FILE* pf = fopen(datpath, "r");
	FILE* outPF = fopen(outputcsvpath, "w+");
	int sz = width*height;
	int* vals = new int[sz];
	int* labels = new int[sz];
	int elread = fread((char*)vals, sizeof(int), sz, pf);

	//temp variable to store the function
	char sTemp[25];

	for (int j = 0; j < height; j++)
	{
		for (int k = 0; k < width; k++)
		{
			
			int i = j*width + k;
			labels[i] = vals[i];
			itoa(labels[i], sTemp, 10);
			fputs(sTemp, outPF);
			fputs(",", outPF);
		}
		fputs("\n", outPF);
	}
	delete[] vals;
	fclose(pf);
}