//***********************************************************************//
//																		 //
//		- "Talk to me like I'm a 3 year old!" Programming Lessons -		 //
//                                                                       //
//		$Author:		DigiBen		digiben@gametutorials.com			 //
//																		 //
//		$Program:		Camera											 //
//																		 //
//		$Description:	Create and move a camera around in our world	 //
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

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

#define kSpeed	0.03f									// This is how fast our camera moves

// These are externed in main.h.  Look in main.h for more explanation on externing.
// Basically, it allows Init.cpp to use them too.  We do this for all global variables.

CCamera	g_Camera;										// Define our camera object

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

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

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

	// Below we call our init function for our camera.  We pass in the
	// starting position of our last tutorial where we are looking dead
	// on at the color triangle.  I added .5 to the Y since the last tutorial.
	// Remember, we only need to init this stuff ONCE, then we never call this again.

						// Position        View		   Up Vector
	g_Camera.PositionCamera(0, 0.5f, 6,   0, 0.5f, 0,   0, 1, 0);

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

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
		else if(LockFrameRate(60))						// if it is time to render
		{ 
			// Render the scene every frame
			RenderScene();
        } 
	}

	DeInit();											// Free everything after the program finishes

	return(msg.wParam);									// Return from the program
}

///////////////////////////////// RENDER SCENE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function renders the entire scene.
/////
///////////////////////////////// RENDER SCENE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void RenderScene() 
{
	int i=0;	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();									// Reset The matrix

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

	// Now instead of passing in hard coded values, we give gluLookAt()
	// the values that our global camera has.  Now we can check if we
	// hit the LEFT RIGHT UP and DOWN arrow keys, then update the camera.
	// It will automatically update right here.  Cool huh?

	// Give openGL our camera position, then camera view, then camera up vector
	gluLookAt(g_Camera.m_vPosition.x, g_Camera.m_vPosition.y, g_Camera.m_vPosition.z,	
			  g_Camera.m_vView.x,	  g_Camera.m_vView.y,	  g_Camera.m_vView.z,	
			  g_Camera.m_vUpVector.x, g_Camera.m_vUpVector.y, g_Camera.m_vUpVector.z);

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

	// Below we say that we want to draw triangles
	glBegin (GL_TRIANGLES);								// This is our BEGIN to draw

		glColor3ub(255, 0, 0);							// Make the top vertex RED
		glVertex3f(0, 1, 0);							// Here is the top point of the triangle

		glColor3ub(0, 255, 0);							// Make the left vertex GREEN
		glVertex3f(-1, 0, 0);							// Here is the left point of the triangle

		glColor3ub(0, 0, 255);							// Make the right vertex BLUE
		glVertex3f(1, 0, 0);							// Here is the right point of the triangle
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

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

		switch(wParam) {								// Check if we hit a key
			case VK_ESCAPE:
				PostQuitMessage(0);						// Send a QUIT message
				break;

			case VK_UP:									// If we hit the UP arrow key
				g_Camera.MoveCamera(kSpeed);			// Move our camera forward by a positive speed
				RenderScene();							// Redraw the screen to reflect changes
				break;

			case VK_DOWN:								// If we hit the DOWN arrow key
				g_Camera.MoveCamera(-kSpeed);			// Move our camera backward by a negative speed
				RenderScene();							// Redraw the screen to reflect changes
				break;
		}
		break;

//////////// *** NEW *** ////////// *** NEW *** ///////////// *** NEW *** ////////////////////

    case WM_CLOSE:									// If the window is being closed
        PostQuitMessage(0);							// Post a QUIT message to the window;										// Release memory and restore settings
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
// The functions that are in this source file are the ones that we will
// be changing on a regular basis.  The functions left in init.cpp are ones
// we will rarely touch, and when we do, it is maybe a line or so.  From now
// on, the tutorials that follow will use this project format.  It will allow
// us to simply focus on the main.cpp with less code, rather than sifting through
// tons of superfluous initialization code.
//
// So now we can actually move around somewhat in our world!  Excited yet?
// Okay, so moving forward and backward isn't to exciting, but it's a start.
// I decided NOT to do any camera rotations in this tutorial because I wanted
// you to suck up all of this camera stuff before we got more complicated.  If
// you understand what we did here, you should be prepared for the next tutorial
// that deals with camera rotations.  In the next tutorial we will do the code that
// allows us to rotate our view left and right, and then walk in that direction.
// It's not hard, but it's a bit too much to digest with the other stuff.  I want
// to make sure you understand everything that we did here.
// 
// So, what DID we do in this tutorial?  Well, if you notice the ** NEW ** tags,
// you will see what has been added to the previous tutorial.  This will be common
// with the rest of the tutorials since we have so much code now.  We didn't touch
// init.cpp at all, and we probably won't for a long time.  We create a CCamera class
// that holds our position, view, and up vector, along with a bunch of helper functions.
// If you still don't understand the up vector, don't worry about it.  You won't ever
// have to change it in my tutorials.  Really, just think of it as pointing up.  That's it.
//
// In this tutorial we also started to create our vector class, CVector3.  We will add
// to this class in the next tutorial.  Basically, this just holds an X Y and Z, or in
// other words, a 3D point.
// 
// You will notice that we also do a check for keyboard input in our WinProc().
// VK_UP and VK_DOWN are the key codes for the UP and DOWN arrow on the keyboard.
// You can change this to what ever you want, but I would advise sticking to this
// for now, since I will be using it throughout the rest of my tutorials.
//
// Now that we have a class that holds our position and view, we can use that to
// pass into the gluLookAt() function.  No more hard coding numbers.  If we want
// to move, we have to use variables that hold the changes to our camera.
//
// We added another source file called Camera.cpp which will hold all of our camera code.
// Later, we will add an Input.cpp which will hold our input code, but that's later.
//
// Once again, I just wanted to make this tutorial as simple as possible.  Go on
// to the next tutorial if you are ready to rotate! :)
//
// * INPUT NOTE *
// 
// You will notice that the input is kinda jumpy and choppy.  That is because we
// are using the WM_KEYDOWN method of checking for Input.  Later, in the next 
// tutorials we will do another method that gives us liquid fast results: GetKeyState().
//
//
// Ben Humphrey (DigiBen)
// Game Programmer
// DigiBen@GameTutorials.com
// Co-Web Host of www.GameTutorials.com
//
//
