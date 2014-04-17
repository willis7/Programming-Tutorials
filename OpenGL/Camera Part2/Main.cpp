//***********************************************************************//
//																		 //
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -		 //
//                                                                       //
//		$Author:		DigiBen		digiben@gametutorials.com			 //
//																		 //
//		$Program:		Camera2											 //
//																		 //
//		$Description:	Rotate our existing camera around in the world	 //
//																		 //
//		$Date:			6/18/01  (Updated Last:  11/27/03)				 //
//																		 //
//***********************************************************************//

// This is a compiler directive that includes libraries (For Visual Studio)
// You can manually include the libraries in the "Project->settings" menu under
// the "Link" tab.  You need these libraries to compile this program.
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#include "main.h"										// This includes our header file

#define kSpeed	0.02f									// This is how fast our camera moves

CCamera g_Camera;										// This is our global camera object

bool  g_bFullScreen = TRUE;								// Set full screen as default
HWND  g_hWnd;											// This is the handle for the window
RECT  g_rRect;											// This holds the window dimensions
HDC   g_hDC;											// General HDC - (handle to device context)
HGLRC g_hRC;											// General OpenGL_DC - Our Rendering Context for OpenGL
HINSTANCE g_hInstance;									// This holds the global hInstance for UnregisterClass() in DeInit()

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

	// Init our camera position

						// Position        View		   Up Vector
	g_Camera.PositionCamera(0, 0.5f, 6,   0, 0.5f, 5,   0, 1, 0);
}

///////////////////////////////// LOCK FRAME RATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	Locks the frame rate at "frame_rate".  Returns true when it's okay to draw,
/////   false otherwise.
/////
///////////////////////////////// LOCK FRAME RATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

bool LockFrameRate(int frame_rate)
{
	static float lastTime = 0.0f;
	
	// Get current time in seconds (milliseconds * .001 = seconds)
	float currentTime = GetTickCount() * 0.001f; 

	// Get the elapsed time by subtracting the current time from the last time
	// If the desired frame rate amount of seconds has passed -- return true (ie Blit())
	if((currentTime - lastTime) > (1.0f / frame_rate))
	{
		// Reset the last time
		lastTime = currentTime;	
			return true;
	}

	return false;
}

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

//////////////////////////// CHECK FOR MOVEMENT \\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function handles the input faster than in the WinProc()
/////
//////////////////////////// CHECK FOR MOVEMENT \\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void CheckForMovement()
{
	// This might look like it's not too much better than what we had before,
	// but believe me, it responds a whole lot better.  If we are just checking
	// for a single keypress, yah, the WinProc() works fine, but when we want to
	// check for constant input like MOVING, we need a faster method.  You noticed
	// that we moved really choppy when we were checking for input in the WinProc.
	// Well, if we call GetKeyState() it reacts faster and allows us to move smoothly.
	
	// The reason why we & the result of the function with 0x80 is because the HIGH bit
	// of the return value tells us if the key is down.  The LOW bit tells us if
	// the key is toggled.  Caps Lock would be an example of a toggled key if it was down.
	// Read MSDN for further information, but just know it's necessary.  In a first person
	// shooter, we would just use this for forward, backward and straffing left to right.
	// The rotation and view would be controlled in spherical coordinates using the mouse.
	// That must wait for another tutorial.

	if(GetKeyState(VK_UP) & 0x80) {				// If we hit the UP arrow key
		g_Camera.MoveCamera(kSpeed);			// Move our camera forward by a positive speed
	}

	if(GetKeyState(VK_DOWN) & 0x80) {			// If we hit the DOWN arrow key
		g_Camera.MoveCamera(-kSpeed);			// Move our camera backward by a negative speed
	}

	if(GetKeyState(VK_LEFT) & 0x80) {			// If we hit the LEFT arrow key

		// We want to rotate around the Y axis so we pass in (0, 1, 0) for the axis
		g_Camera.RotateView(kSpeed, 0, 1, 0);	// Rotate our camera LEFT by the positive speed
	}

	if(GetKeyState(VK_RIGHT) & 0x80) {			// If we hit the RIGHT arrow key

		// Use a positive speed to rotate around the Y axis (0, 1, 0)
		g_Camera.RotateView(-kSpeed, 0, 1, 0);	// Rotate our camera RIGHT by the negative speed
	}
}

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////


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
		else if(LockFrameRate(60))						// if it is time to draw
		{ 

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

			// When we aren't reveiving windows messages we now check for input
			// from the keyboard.  This is a lot better method if we want movement.
			CheckForMovement();

			RenderScene();								// Redraw the screen every frame

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

        } 
	}

	DeInit();											// Clean up and free all allocated memory

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

	// Give openGL our camera position, then camera view, then camera up vector
	gluLookAt(g_Camera.m_vPosition.x, g_Camera.m_vPosition.y, g_Camera.m_vPosition.z,	
			  g_Camera.m_vView.x,	  g_Camera.m_vView.y,     g_Camera.m_vView.z,	
			  g_Camera.m_vUpVector.x, g_Camera.m_vUpVector.y, g_Camera.m_vUpVector.z);

	// Below we say that we want to draw triangles
	glBegin (GL_TRIANGLES);								// This is our BEGIN to draw

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////
		
		// Draw 10 triangles of the same type down the -Z axis (in front of the camera)
		for(float i = -10; i < 0; i++)
		{
			glColor3ub(255, 0, 0);						// Make the top vertex RED
			glVertex3f(0, 1, i);						// Here is the top point of the triangle
	
			glColor3ub(0, 255, 0);						// Make the left vertex GREEN
			glVertex3f(-1, 0, i);						// Here is the left point of the triangle
	
			glColor3ub(0, 0, 255);						// Make the right vertex BLUE
			glVertex3f(1, 0, i);						// Here is the right point of the triangle
		}

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

	glEnd();											// This is the END of drawing

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
		if(!g_bFullScreen)								// Do this only if we are in window mode
		{
			SizeOpenGLScreen(LOWORD(lParam),HIWORD(lParam));// LoWord=Width, HiWord=Height
			GetClientRect(hWnd, &g_rRect);					// Get the window rectangle
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
		
		// We got rid of the input for the arrow keys because it's choppy here

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
// In this tutorial we allowed the camera to rotate left and right.  Also, we fixed
// the choppy movement by taking out the movement checks from the WinProc().
// By using GetKeyState(), it allows us to make more liquid fast responses if a
// key is being held down.
// 
// Eventually, we will want to use spherical coordinates for the view.  This means
// that we will be translating the mouse coordinates to direct where we are looking,
// just like in most first person shooter type games.
// 
// By now you should be able to make some walls and levels to walk around.  Give it a
// try.  I wanted to make a small maze, but I didn't want to complicate the tutorial.
// The creativity should come from you, not me :)  I just deliver the know how.
// 
// I did however, add more triangles by creating a for loop in the glBegin() scope.
// It just draws 10 triangles instead of one.  Walk around and check them out!
// 
// 
// Ben Humphrey (DigiBen)
// Game Programmer
// DigiBen@GameTutorials.com
// Co-Web Host of www.GameTutorials.com
//
//