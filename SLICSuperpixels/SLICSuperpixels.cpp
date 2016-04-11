
// SLICSuperpixelsDlg.cpp : implementation file
//
#include "PictureHandler.h"
#include "SLIC.h"
#include "SLICSuperpixels.h"
#include <fstream>

int g_Width, g_Height;
void readLabel(char* datFilePath, char* outputFilePath, int width, int height){
	
	ifstream in(datFilePath, ios::in | ios::binary);
	ofstream out(outputFilePath, ios::out);
	
	for( int j = 0; j < height; j++ )
	{
		for( int k = 0; k < width; k++ )
		{
			int temp;
			in.read((char*)&temp, sizeof(int));
			out<<temp;
			if (k == width-1)
				continue;
			out.put(',');
		}
		out.put('\n');
	}
	in.close();
	out.close();
}

void createSuperpixels(char* bmpFilePath, char* imgSegOutputPath, int m_spcount, int m_compactness){
	PictureHandler picHand;
	vector<string> picvec(0);
	picvec.resize(0);
	string path = bmpFilePath;
	picvec.push_back(bmpFilePath);//user chooses one or more pictures
	
	string savLocation = imgSegOutputPath;
	// BrowseForFolder(saveLocation);
	int numPics( picvec.size() );
	// return the image width and Height
	for( int k = 0; k < numPics; k++ )
	{
		UINT* img = NULL;
		int width(0);
		int height(0);
		
		picHand.GetPictureBuffer( picvec[k], img, width, height );
		
		
		g_Width = width;
		g_Height = height;
		
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

int main(){
	createSuperpixels("beauty.bmp", "", 200, 10);
	return 0;
}