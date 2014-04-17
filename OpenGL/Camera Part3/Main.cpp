//***********************************************************************//
//																		 //
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -		 //
//                                                                       //
//		$Author:		DigiBen		digiben@gametutorials.com			 //
//																		 //
//		$Program:		Camera3											 //
//																		 //
//		$Description:	Allow the mouse to control our camera's view	 //
//																		 //
//		$Date:			6/23/01 (Updated Last: 11/28/03)				 //
//																		 //
//***********************************************************************//

// This is a compiler directive that includes libraries (For Visual Studio)
// You can manually include the libraries in the "Project->settings" menu under
// the "Link" tab.  You need these libraries to compile this program.
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#include "main.h"										// This includes our header file

#define kSpeed	0.03f									// This is how fast our camera moves

CCamera g_Camera;										// This is our global camera object

bool  g_bFullScreen = true;								// Set full screen as default
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
	g_Camera.PositionCamera(0, 1.5f, 6,   0, 1.5f, 5,   0, 1, 0);

	ShowCursor(false);									// Hide the cursor (NEW)
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

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////	

	// Now we check if we hit the UP arrow key or the W key (like in 3D shooter games).
	if( (GetKeyState(VK_UP) & 0x80) || (GetKeyState('W') & 0x80) ) {
		g_Camera.MoveCamera(kSpeed);			// Move our camera forward by a positive speed
	}

	// Now we check if we hit the DOWN arrow key or the S key (like in 3D shooter games).
	if( (GetKeyState(VK_DOWN) & 0x80) || (GetKeyState('S') & 0x80) ) {
		g_Camera.MoveCamera(-kSpeed);			// Move our camera backward by a negative speed
	}

	// * NOTE *
	
	// Notice we ditched the LEFT and RIGHT keys because we use the camera instead!!
	
//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

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
		else if(LockFrameRate(60))						// if it time to render
		{ 

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////
			
			// Here we check for mouse and key movements every frame
			g_Camera.SetViewByMouse();					// Move the camera by the mouse
			CheckForMovement();							// Check if we pressed a key
			
			RenderScene();								// Update the screen	
			
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

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

	// Below, instead of drawing triangle we draw 3D rectangles, or QUADS as they are called.
	// So, now instead of passing GL_TRIANGLES we say GL_QUADS.
	// Triangles take 3 points, but Quads take 4, so we need to add an extra 3D point for each primative.

	// Below there is about 20 quads draw upwards to form a tower type shape.
	// I slowly make each quads smaller, and it makes an interesting effect.

	// Below we say that we want to draw QUADS
	glBegin (GL_QUADS);								// This is our BEGIN to draw
		
		for(float i = 0; i < 100; i += 5)
		{
			glColor3ub(255, 255,   0);				// Make this corner YELLOW
			glVertex3f(-10 + i/5,   i,  10 - i/5);	// Here is the bottom left corner of the QUAD

			glColor3ub(255,   0,   0);				// Make this corner RED
			glVertex3f(-10 + i/5,   i, -10 + i/5);	// Here is the top left corner of the QUAD
		
			glColor3ub(0,   255, 255);				// Make the left vertex CYAN
			glVertex3f(10 - i/5,    i, -10 + i/5);	// Here is the top right corner of the QUAD
		
			glColor3ub(0,     0, 255);				// Make the right vertex BLUE
			glVertex3f(10 - i/5,    i,  10 - i/5);	// Here is the bottom right corner of the QUAD
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
		if(!g_bFullScreen)								// Do this is we are not in full screen
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
// In this tutorial we learned a simple way to make the camera rotate with the mouse.
// There is 2 more things that we are missing with cameras and that is straffing, and
// camera paths.  See if you can make the camera strafe left or right.  Since you should
// now know about the CROSS product, you can calculate your strafing vector to be applied
// to the current position and current view.  
// 
// The main functions in this file changed are MainLoop(), CheckForMovement(), and RenderScene()..
// Not to much coded aded to this tutorial, but still a neat one that is a must for any first
// person view.
// 
//
// Ben Humphrey (DigiBen)
// Game Programmer
// DigiBen@GameTutorials.com
// Co-Web Host of www.GameTutorials.com
// © 2000-2003 GameTutorials
//

