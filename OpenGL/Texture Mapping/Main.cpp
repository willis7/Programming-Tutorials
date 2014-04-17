//***********************************************************************//
//																		 //
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -		 //
//                                                                       //
//		$Author:		DigiBen		digiben@gametutorials.com			 //
//																		 //
//		$Program:		Texturing										 //
//																		 //
//		$Description:	Texture maps a shape							 //
//																		 //
//		$Date:			7/3/01											 //
//																		 //
//***********************************************************************//

// This is a compiler directive that includes libraries (For Visual Studio)
// You can manually include the libraries in the "Project->settings" menu under
// the "Link" tab.  You need these libraries to compile this program.
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glaux.lib")

#include "main.h"										// This includes our header file

bool  g_bFullScreen = TRUE;								// Set full screen as default
HWND  g_hWnd;											// This is the handle for the window
RECT  g_rRect;											// This holds the window dimensions
HDC   g_hDC;											// General HDC - (handle to device context)
HGLRC g_hRC;											// General OpenGL_DC - Our Rendering Context for OpenGL
HINSTANCE g_hInstance;									// This holds the global hInstance for UnregisterClass() in DeInit()

/////// * /////////// * /////////// * NEW * /////// * /////////// * /////////// *

UINT g_Texture[MAX_TEXTURES];							// This will reference to our texture data stored with OpenGL UINT is an unsigned int (only positive numbers)

/////// * /////////// * /////////// * NEW * /////// * /////////// * /////////// *

///////////////////////////////// INIT GAME WINDOW \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function initializes the game window.
/////
///////////////////////////////// INIT GAME WINDOW \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void Init(HWND hWnd)
{
	g_hWnd = hWnd;										// Assign the window handle to a global window handle
	GetClientRect(g_hWnd, &g_rRect);					// Assign the windows rectangle to a global RECT
	InitializeOpenGL(g_rRect.right, g_rRect.bottom);	// Init OpenGL with the global rect

/////// * /////////// * /////////// * NEW * /////// * /////////// * /////////// *

	// This is where we load all of our texture.  We are loading
	// just one in this case, but you can add many many more if you want.
	// We pass in our global textureArray, our file we want to load, and the texture ID we want associated with it.

	CreateTexture(g_Texture, "bitmap.bmp", 0);			// Load "bitmap.bmp" into openGL as a texture

/////// * /////////// * /////////// * NEW * /////// * /////////// * /////////// *

}

///////////////////////////////// MAIN GAME LOOP \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function Handles the main game loop
/////
///////////////////////////////// MAIN GAME LOOP \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

WPARAM MainLoop()
{
	MSG msg;

	while(1)											// Do our infinate loop
	{													// Check if there was a message
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
        { 
			if(msg.message == WM_QUIT)					// If the message wasnt to quit
				break;
            TranslateMessage(&msg);						// Find out what the message does
            DispatchMessage(&msg);						// Execute the message
        }
		else											// if there wasn't a message
		{ 
			RenderScene();								// Redraw the scene every frame
        } 
	}

	DeInit();											// Free all the app's memory allocated

	return(msg.wParam);									// Return from the program
}

///////////////////////////////// RENDER SCENE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function renders the entire scene.
/////
///////////////////////////////// RENDER SCENE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void RenderScene() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();									// Reset The matrix
	
		// 	  Position      View	   Up Vector
	gluLookAt(0, 0, 6,     0, 0, 0,     0, 1, 0);		// This determines where the camera's position and view is

/////// * /////////// * /////////// * NEW * /////// * /////////// * /////////// *
	
	// Below we draw a texture mapped square. Remember, GL_QUADS draws a 4 point polygon.
	// In order to assign a texture map to a polygon, we need to call glBindTexture().
	// This passes in the type of texture map (always use GL_TEXTURE_2D) and the index
	// into our generated texture array - g_Texture[].  If we want to use another
	// texture map, and we have multiple loaded, we just change the index into the array.

	// Bind the texture stored at the zero index of g_Texture[]
	glBindTexture(GL_TEXTURE_2D, g_Texture[0]);

	// Display a quad texture to the screen
	glBegin(GL_QUADS);

		// glTexCoord2f() takes the X and Y offset (or U and V) into the bitmap.
		// Then, the next point sent to be rendered attaches that part of the bitmap
		// to itself.  The (U, V) coordinates range from (0, 0) being the top left corner
		// of the bitmap, to (1, 1) being the bottom left corner of the bitmap.
		// You can go above 1 but it just is wrapped around back to zero and repeats the texture.
		// Try setting the 1's to 2's and see what it does, then try setting them to 0.5's.
		// The higher the number, the more instances of the texture will appear on the square,
		// Where the lower the number, it stretches the incomplete texture over the surface of the square.
		// For every vertice we need a U V coordinate, as shown below.  You might have to play
		// around with the values to make it texture correctly, otherwise it will be flipped, upside down,
		// or skewed.  It also depends on where you are looking at it.  We are looking down the -Z axis.

		// Display the top left vertice
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1, 1, 0);

		// Display the bottom left vertice
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1, -1, 0);

		// Display the bottom right vertice
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1, -1, 0);

		// Display the top right vertice
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1, 1, 0);

	glEnd();											// Stop drawing QUADS

/////// * /////////// * /////////// * NEW * /////// * /////////// * /////////// *

	SwapBuffers(g_hDC);									// Swap the backbuffers to the foreground
}

///////////////////////////////// WIN PROC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function handles the window messages.
/////
///////////////////////////////// WIN PROC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

LRESULT CALLBACK WinProc(HWND hWnd,UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    LONG    lRet = 0; 
    PAINTSTRUCT    ps;

    switch (uMsg)
	{ 
    case WM_SIZE:										// If the window is resized
		if(!g_bFullScreen)								// Do this only if we are NOT in full screen
		{
			SizeOpenGLScreen(LOWORD(lParam),HIWORD(lParam));// LoWord=Width, HiWord=Height
			GetClientRect(hWnd, &g_rRect);				// Get the window rectangle
		}
        break; 
 
	case WM_PAINT:										// If we need to repaint the scene
		BeginPaint(hWnd, &ps);							// Init the paint struct		
		EndPaint(hWnd, &ps);							// EndPaint, Clean up
		break;

	case WM_KEYDOWN:
		switch(wParam) {								// Check if we hit a key
			case VK_ESCAPE:								// If we hit the escape key
				PostQuitMessage(0);						// Send a QUIT message to the window
				break;
		}
		break;
 
    case WM_CLOSE:										// If the window is being closes
        PostQuitMessage(0);								// Send a QUIT Message to the window
        break; 
     
    default:											// Return by default
        lRet = DefWindowProc (hWnd, uMsg, wParam, lParam); 
        break; 
    } 
 
    return lRet;										// Return by default
}

/////////////////////////////////////////////////////////////////////////////////
//
// * QUICK NOTES * 
//
// BE SURE TO INCLUDE glaux.lib and gluax.h IN YOUR PROJECTS TO USE CreateTexture().
//
// There you have it!  That is how to texture map a primative.  It's pretty simple
// once you get the texture loaded.  That is the only challenging part.
// 
// Here are the steps to texture mapping:
// 
// 1) Turn on texture mapping by saying:  
//
//	  glEnable(GL_TEXTURE_2D);
//
//    This is usually done in the beginning of the program.  BUT, you will
//    want to turn it back off before you draw primatives using color instead.
//    So, say:  glDisable(GL_TEXTURE_2D)  - Then draw your colored shapes, then
//    turn it back on by saying glEnable(GL_TEXTURE_2D);
// 
// 2) Load a texture.  Once you have the data of the texture you loaded, you need to
//    register it with OpenGL.  The first step to do this is:
//
//	  glGenTextures(1, &textureArray[textureID]);
//
//    This generates a unique texture reference to the desired index of our texture array.
//	  We then pass this data into glBindTexture() to set the current texture being mapped.
//
//	  glBindTexture(GL_TEXTURE_2D, textureArray[textureID]);
//
//    We NEED to call glBindTexture() after we generate the texture using glGenTextures, 
//    otherwise it won't be assigned the data from the next function, gluBuild2DMipmaps();
//
//	  gluBuild2DMipmaps(GL_TEXTURE_2D, 3, pBitmap->sizeX, pBitmap->sizeY, GL_RGB, GL_UNSIGNED_BYTE, pBitmap->data);
//
//    What is a mip map you ask?  Mip maps are a bunch of different scaled sizes of the texture.
//    The reason for this is because it makes the texture look nicer if we are farther away or
//    up close to the texture.  It picks the best size depending on the distance we are from it.
//    It is a good idea to make textures that are a power of 2, like 2, 4, 8, 16, 32, 64, 128, 256, etc...
//    This makes it so it can get a smoother representation when it scales, otherwise it could look worse when scaled.
//    After we build the mip maps, we then need to set the type of filter we want to use.
//
//	  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//	  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	
//
//    If we use GL_LINEAR it will look smoother, but takes a little speed hit.  If we use
//    GL_NEAREST it will be a bit faster, but will look pixelated and blotchy.  The MIN filter
//    is used whenever the pixel being textured maps to an area greater than one texture element. 
//    The MAX filter is used when the pixel being textured maps to an area less than or equal to one texture element
//
// 3) After we load the texture, we just need to call glBindTexture() to set that as the current
//    texture being mapped.
// 
// 4) Next, we need to give each vertex a texture coordinate, also called (U, V) coordinates.
//    We do that by calling:
//
//    glTexCoord2f(U, V);
//
//    This assigns a part of the bitmap to the next vertice passed in.  It's like putting a
//    sticker on paper, you just match the correct corner with the correct paper corner.
//    You have to be carefull when you do this or else the image will be flipped or upside down.
//    It depends on the direction of your camera though.  The order is VERY important.
// 
// 5) Lastly, you need to delete the textures after you are finished.  You do this by calling:
// 
//    glDeleteTextures(1, &textureArray[textureIndex]);
// 
// That's it!  Let us know at GameTutorials.com if this tutorial helps you.  We would love to
// see what you come up with.
// 
// DigiBen
// www.GameTutorials.com
//
// Below is a function that might come in handy for creating a quad or a cube easily.
// The VECTOR3D data type is just a structure that as 3 floats:  float x, y, z;
// It makes it easier instead of passing in 3 parameters for the center.  Basically it
// takes a center point in 3D space, then allows you to size the QUAD, by doing this you
// also choose which axis it goes down, or which axis's.

/*
///////////////////////////////// RENDER QUAD \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This renders a textured or non texture quad to the screen
/////
///////////////////////////////// RENDER QUAD \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void RenderQuad(VECTOR3D vCenter, float widthX, float widthY, float widthZ, int textureID)
{	
	// Bind the correct texture to the quad if the ID isn't a negative number
	if(textureID >= 0) glBindTexture(GL_TEXTURE_2D, g_Texture[textureID]);

	// Display a quad texture to the screen
	glBegin(GL_QUADS);

		// Display the top left vertice
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(vCenter.x - widthX, vCenter.y - widthY, vCenter.z - widthZ);

		// Display the bottom left vertice
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(vCenter.x - widthX, vCenter.y + widthY, vCenter.z - widthZ);

		// Display the top right vertice
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(vCenter.x + widthX, vCenter.y + widthY, vCenter.z + widthZ);

		// Display the bottom right vertice
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(vCenter.x + widthX, vCenter.y - widthY, vCenter.z + widthZ);

	glEnd();
}
*/
//
// Ben Humphrey (DigiBen)
// Game Programmer
// DigiBen@GameTutorials.com
// Co-Web Host of www.GameTutorials.com
// © 2000-2003 GameTutorials
//