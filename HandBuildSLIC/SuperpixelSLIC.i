 %module SuperpixelSLIC
 %{
	 /* Put header files here or function declarations like below */
	#define SWIG_FILE_WITH_INIT
	#include "SuperpixelSLIC.h"
 %}
void doSuperpixelSegmentation(char* image_path, char* saveLocation, int m_spcount, int m_compactness);
void readLabel(char *datpath, char *outputcsvpath, int width, int height);