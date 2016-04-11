/* File: SLICSuperpixels.i */
%module SLICSuperpixels
%include "cstring.i"
%{
extern int g_Width; 
extern int g_Height; 
#define SWIG_FILE_WITH_INIT
#include "SLICSuperpixels.h"
%}
void readLabel(char* datFilePath, char* outputFilePath, int width, int height);
void createSuperpixels(char* bmpFilePath, char* saveLocation, int m_spcount, int m_compactness);
int g_Width; 
int g_Height; 
