#ifndef _IMAGE_H
#define _IMAGE_H

#include "jpeglib.h"


// These defines are used to tell us about the type of TARGA file it is
#define TGA_RGB		 2		// This tells us it's a normal RGB (really BGR) file
#define TGA_A		 3		// This tells us it's a ALPHA file
#define TGA_RLE		10		// This tells us that the targa is Run-Length Encoded (RLE)

// This is our image structure for our targa data
struct tImage
{
	int channels;			// The channels in the image (3 = RGB : 4 = RGBA)
	int sizeX;				// The width of the image in pixels
	int sizeY;				// The height of the image in pixels
	unsigned char *data;	// The image pixel data
};


// This loads and returns the BMP data
tImage *LoadBMP(const char *strFileName);

// This loads and returns the TGA data
tImage *LoadTGA(const char *strFileName);

// This loads and returns the JGP data
tImage *LoadJPG(const char *strFileName);

// This decompresses the JPEG and fills in the image data
void DecodeJPG(jpeg_decompress_struct* cinfo, tImage *pImageData);


#endif


/////////////////////////////////////////////////////////////////////////////////
//
// * QUICK NOTES * 
//
// Nothing new was added to this file for this tutorial.
//
//
// Ben Humphrey (DigiBen)
// Game Programmer
// DigiBen@GameTutorials.com
// Co-Web Host of www.GameTutorials.com
//
//