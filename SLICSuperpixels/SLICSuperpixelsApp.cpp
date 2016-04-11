
// SLICSuperpixelsDlg.cpp : implementation file
//
#include "PictureHandler.h"
#include "SLIC.h"
#include <string>
#include <iostream>
using namespace std;
void readLabel(char* datFilePath, char* outputFilePath, int width, int height){
		// input file
		FILE* pf = fopen(datFilePath, "r");
		// output file
		FILE* of = fopen(outputFilePath, "w");
		int sz = width*height;
		int* vals = new int[sz];
		int elread = fread((char*)vals, sizeof(int), sz, pf);
		for( int j = 0; j < height; j++ )
		{
			for( int k = 0; k < width; k++ )
			{
				int i = j*width+k;
				fprintf(of, "%d%s", vals[i], ",");
			}
			fprintf(of, "%s", "\n");
		}
		delete [] vals;
		fclose(pf);
		fclose(of);
}

void createSuperpixels(char* bmpFilePath, char* saveSegPath, int m_spcount, int m_compactness){
	PictureHandler picHand;
	vector<string> picvec(0);
	picvec.resize(0);
	//GetPictures(picvec);//user chooses one or more pictures
	picvec.push_back(bmpFilePath);
	string saveLocation = saveSegPath;

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
		//slic.DoSuperpixelSegmentation_ForGivenSuperpixelSize(img, width, height, labels, numlabels, 10, m_compactness);//demo
		slic.DrawContoursAroundSegments(img, labels, width, height, 0);
		if(labels) delete [] labels;
		cout<<"zhuangxiyang";
		picHand.SavePicture(img, width, height, picvec[k], saveLocation, 1, "_SLIC");// 0 is for BMP and 1 for JPEG)
		if(img) delete [] img;
	}
}

int main(){
	createSuperpixels("C:\\Users\\Admin\\Desktop\\beauty.dat","C:/Users/Admin/Desktop/", 20, 200);
	return 0;
}