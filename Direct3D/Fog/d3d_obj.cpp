#include "d3d_obj.h"

// Declare our static variables
IDirect3D9* CD3DObj::mInterface = NULL;
IDirect3DDevice9* CD3DObj::mDevice = NULL;
HRESULT CD3DObj::mResult = 0;
bool CD3DObj::mFullScreen = false; // Start out windowed
HWND CD3DObj::mHWND = NULL;
float CD3DObj::mFOV = 0.0f; // Field of view
float CD3DObj::mNearClip = 0.0f; // Near clip plane
float CD3DObj::mFarClip = 0.0f; // Far clip plane
float CD3DObj::mAspectRatio = 0.0f; // Width / Height of display screen

// Initializes our D3D object -- Returns true on success, false otherwise
bool CD3DObj::init(HWND hwnd)
{
	if(!hwnd)
		return false;

	mHWND = hwnd; // Store window handle

	// Create the D3D object, which is needed to create the D3DDevice.
	mInterface = Direct3DCreate9(D3D_SDK_VERSION);

	// Error Check
	if(mInterface == NULL)
		return false;

	// Create the D3D device
	if(!createDevice())
		return false;

	// Setup default render states	
	setDefaultRenderState();
		return true; // We got loaded!
}

// Begins the scene
void CD3DObj::begin()
{
	// This begins our scene.
	mResult = mDevice->BeginScene();
	assert(mResult == D3D_OK);
}

// End the scene and draw it
void CD3DObj::end()
{
	// This ends the scene
	mResult = mDevice->EndScene();
	assert(mResult == D3D_OK);

	// Present the current buffer (we have two in our case) to the screen
	mResult = mDevice->Present(NULL, NULL, NULL, NULL);
	assert(mResult == D3D_OK);
}

// Set all the render states to a default value
void CD3DObj::setDefaultRenderState()
{
	assert(mDevice != NULL);

	// Turn off D3D lighting
	mResult = mDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	assert(mResult == D3D_OK);

	// Turn on the z-buffer
	mResult = mDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
	assert(mResult == D3D_OK);
}

// Sets the fog color
bool CD3DObj::setFogColor(DWORD color)
{
	mResult = mDevice->SetRenderState(D3DRS_FOGCOLOR, color);
	return (mResult == D3D_OK);
}

// Sets the mode, either D3DFOG_NONE, D3DFOG_EXP, D3DFOG_EXP2, or D3DFOG_LINEAR,
// for pixel based fog
bool CD3DObj::setPixelFogMode(D3DFOGMODE mode)
{
	mResult = mDevice->SetRenderState(D3DRS_FOGTABLEMODE, mode);
	return (mResult == D3D_OK);
}

// Sets the mode, either D3DFOG_NONE, D3DFOG_EXP, D3DFOG_EXP2, or D3DFOG_LINEAR,
// for vertex based fog
bool CD3DObj::setVertexFogMode(D3DFOGMODE mode)
{
	mResult = mDevice->SetRenderState(D3DRS_FOGVERTEXMODE, mode);
	return (mResult == D3D_OK);
}

// Sets the starting distance of the fog (applies only to D3DFOG_LINEAR fog) 
bool CD3DObj::setFogStart(float start)
{
	mResult = mDevice->SetRenderState(D3DRS_FOGSTART, (*(DWORD*)(&start)));
	return (mResult == D3D_OK);
}

// Sets the ending distance of the fog (applies only to D3DFOG_LINEAR fog) 
bool CD3DObj::setFogEnd(float end)
{
	mResult = mDevice->SetRenderState(D3DRS_FOGEND, (*(DWORD*)(&end)));
	return (mResult == D3D_OK);
}

// Sets the thickness of the fog (applies to D3DFOG_EXP and D3DFOG_EXP2 fog)
bool CD3DObj::setFogDensity(float density)
{
	mResult = mDevice->SetRenderState(D3DRS_FOGDENSITY, *((DWORD*)(&density)));
	return (mResult == D3D_OK);
}

// Turns on or off fog
bool CD3DObj::setFogActive(bool onOrOff)
{
	mResult = mDevice->SetRenderState(D3DRS_FOGENABLE, (DWORD)onOrOff);
	return (mResult == D3D_OK);
}

bool CD3DObj::toggleFullScreen()
{
	assert(mDevice != NULL);

	static RECT winRect = {0};
	D3DPRESENT_PARAMETERS params = {0}; // Presentation parameters to be filled

	// Toggle full screen flag
	mFullScreen = !mFullScreen; 

	// Get presentation parameters for the new current full screen mode
	setPresentationParams(params);

	// If we're changing to full screen mode, save off the window's RECT so
	// we can put the window back in position when switching back to windowed mode
	if(mFullScreen == true)
		GetWindowRect(mHWND, &winRect);

	// Reset the device to the new parameters
	if(mDevice->Reset(&params) != D3D_OK)
	{
		// Put flag back
		mFullScreen = !mFullScreen;
		return false;
	}

	// If we've changed to windowed mode
	if(mFullScreen == false)
	{
		// Move and resize window
		SetWindowPos(mHWND, HWND_NOTOPMOST, winRect.left, winRect.top, winRect.right - winRect.left,
			winRect.bottom - winRect.top, SWP_SHOWWINDOW);
	}

	// Calculate the new aspect ratio
	float aspectRatio = (float)params.BackBufferWidth / (float)params.BackBufferHeight;

	// We must reset the render states
	setDefaultRenderState();
	setProjMatrix(mFOV, aspectRatio, mNearClip, mFarClip);
	return true;
}

// This renders a list of SVertex type vertices that is "numVerts" long
bool CD3DObj::render(SVertex *vertList, int numVerts)
{
	// We're rendering triangles so the number of verts should evenly be divisible by 3
	assert(numVerts % 3 == 0); 

	// Set the flexible vertex format
	mDevice->SetFVF(SVertexType);

	// Draw the vertex list
	mResult = mDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, numVerts / 3, vertList, sizeof(SVertex));
	return (mResult == D3D_OK);
}

// Renders a indexed list of SVertex as triangles
bool CD3DObj::render(SVertex *vertList, int numVerts, WORD *indexList, int numIndices)
{
	// We're rendering triangles so the number of indices should evenly be divisible by 3
	assert(numIndices % 3 == 0); 

	// Set the flexible vertex format
	mDevice->SetFVF(SVertexType);

	// Draw the indexed vertex list
	mResult = mDevice->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, numVerts, numIndices / 3,
		indexList, D3DFMT_INDEX16, vertList, sizeof(SVertex));
	return (mResult == D3D_OK);
}

bool CD3DObj::renderLine(SVertex *vertList, int numVerts)
{
	// We're rendering line segments so there should  be an even number of vertices
	assert(numVerts % 2 == 0); 

	// Set the FVF 
	mDevice->SetFVF(SVertexType);

	// Render the line segments
	mResult = mDevice->DrawPrimitiveUP(D3DPT_LINELIST, numVerts / 2, vertList, sizeof(SVertex));
	return (mResult == D3D_OK); // Returns status of DrawPrimitiveUP()
}

// Sets the projection matrix, which dictates how our 3D scene is projected onto our 2D monitor
// using the passed in field of view, aspect ratio, near clip plane, and far clip plane
void CD3DObj::setProjMatrix(float fov, float aspectRatio, float nearClip, float farClip)
{
	D3DXMATRIXA16 matrix;

	mFOV = fov;
	mAspectRatio = aspectRatio;
	mNearClip = nearClip;
	mFarClip = farClip;

	// Create and set projection matrix
	D3DXMatrixPerspectiveFovLH(&matrix, fov, aspectRatio, nearClip, farClip);
	mDevice->SetTransform(D3DTS_PROJECTION, &matrix);
}

// Sets up the view of the scene based on passed in eye and target
void CD3DObj::setViewMatrix(const CPos &eye, const CPos &lookAt)
{
	D3DXMATRIXA16 matrix;
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f); // World's up vector

	// Create and set the view matrix
	D3DXMatrixLookAtLH(&matrix, (D3DXVECTOR3*)(&eye), (D3DXVECTOR3*)(&lookAt), &up);
	mDevice->SetTransform(D3DTS_VIEW, &matrix); // Set our view of the world
}

// Sets up the view of the scene based on passed in eye and target
void CD3DObj::setViewMatrix(const CCamera *camera)
{
	D3DXMATRIXA16 matrix;
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f); // World's up vector

	// Create and set the view matrix
	// **NOTE** The syntax looks ugly but heres what is happening:
	//			D3DXMatrixLookAtLH() takes a D3DXVECTOR3* for it's 2nd, 3rd, and 4th arguments
	//			We store the camera's eye and target in our own class CVector, however, it's data
	//			is laid out the same way as a D3DXVECTOR3, so we can cast the pointer
	//			and everything works as expected
	D3DXMatrixLookAtLH(&matrix, (D3DXVECTOR3*)(&camera->getEye()), 
		(D3DXVECTOR3*)(&camera->getTarget()), &up);
	mDevice->SetTransform(D3DTS_VIEW, &matrix); // Set our view of the world
}

// Sets the world matrix to the matrix passed in
void CD3DObj::setWorldMatrix(const D3DXMATRIX *matrix)
{
	mDevice->SetTransform(D3DTS_WORLD, matrix);
}

// Clears the viewport to a specified ARGB color
bool CD3DObj::clear(int color, float zDepth)
{
	// This clears our viewport to the color and zDepth passed in
	mResult = mDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, color, zDepth, 0);
	return (mResult == D3D_OK);
}

// Free up all the memory
void CD3DObj::deinit()
{
	if(mDevice != NULL)
		mDevice->Release();

	if(mInterface != NULL)
		mInterface->Release();

	// Zero out our D3D interface and device 
	mDevice = NULL;
	mInterface = NULL;

	// Zero out window handle
	mHWND = NULL;
}

////////////////////////////////
// *** Private Functions *** //
//////////////////////////////

bool CD3DObj::createDevice()
{
	assert(mInterface != NULL);
	assert(mDevice == NULL); // Should be destroyed before reallocated

	D3DPRESENT_PARAMETERS params = {0}; // Presentation parameters to be filled

	// Fill the presentation parameters
	setPresentationParams(params);

	// Set the Aspect Ratio
	mAspectRatio = (float)params.BackBufferWidth / (float)params.BackBufferHeight;

	mResult = mInterface->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		mHWND,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&params,
		&mDevice);

	// It's possible we'll get an error because not all vid-cards can handle vertex processing
	// So in the event we do get an error we'll try to make the device again.  We will
	// only change D3DCREATE_HARDWARE_VERTEXPROCESSING to D3DCREATE_SOFTWARE_VERTEXPROCESSING
	// which says, "Do the vertex processing in software" 
	if(mResult != D3D_OK)
	{
		mResult = mInterface->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			mHWND,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&params,
			&mDevice);

		if(mResult != D3D_OK)
			return false; // Couldn't create a D3D 9.0 device
	}

	return true; // Device got loaded
}

// Fill the D3DPRESENT_PARAMETERS with the correct parameters based 
// on windowed or full screen mode
void CD3DObj::setPresentationParams(D3DPRESENT_PARAMETERS &params)
{
	// Zero out the params struct 
	ZeroMemory(&params, sizeof(D3DPRESENT_PARAMETERS));

	// Set all parameters that can be shared between windowed and full screen mode
	params.hDeviceWindow = mHWND; // Handle to window
	params.BackBufferCount = 2; // Number of render surfaces
	params.SwapEffect = D3DSWAPEFFECT_FLIP; // We want to treat the back buffers as a circular
	// queue and rotate through them
	params.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE; // Draw everything immediately, don't
	// wait for V-sync
	params.EnableAutoDepthStencil = TRUE; // We want a Z-buffer
	params.AutoDepthStencilFormat = D3DFMT_D16; // 16-bit Z-buffer (should be safe on most cards...)

	if(mFullScreen)
	{
		D3DDISPLAYMODE dispMode = {0};

		// Get the current configuration of the primary monitor
		mResult = mInterface->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &dispMode);
		assert(mResult == D3D_OK);

		// Fill in the rest of the parameters with the primary display device's parameters
		params.Windowed = FALSE;
		params.BackBufferWidth = dispMode.Width;
		params.BackBufferHeight = dispMode.Height;
		params.FullScreen_RefreshRateInHz = dispMode.RefreshRate;
		params.BackBufferFormat = dispMode.Format; // Use the current color depth of the monitor	
	}
	else
	{
		// Get client rect
		RECT rect = {0};
		GetClientRect(mHWND, &rect);

		params.Windowed = true; // We want a window
		params.BackBufferWidth = rect.right; // Backbuffer's width equals client rect's width
		params.BackBufferHeight = rect.bottom; // Backbuffer's height equals client rect's height
		params.BackBufferFormat = D3DFMT_UNKNOWN; // Use whatever the current color depth of the
		// monitor is for the back buffer
	}
}

CD3DObj theD3DObj; // Create our 3D Object
CD3DObj *g3D = &theD3DObj; // Set the global pointer to our 3D Object

/*#include <assert.h>
#include "d3d_obj.h"

// Constructor -- Zero out our data
CD3DObj::CD3DObj()
{
	d3d_interface = NULL;
	mDevice = NULL;

	// Set data to zero
	fov = aspect_ratio = near_clip = far_clip = 0.0f;
	result = 0;
}

// Initializes our D3D object -- Returns true on success, false otherwise
bool CD3DObj::init(HWND hwnd)
{
	// Create the D3D object, which is needed to create the D3DDevice.
	d3d_interface = Direct3DCreate9(D3D_SDK_VERSION);

		// Error Check
		if(d3d_interface == NULL)
			return false;

	// This is the structure that defines how our 3D device (the thing that allows us
	// to render) is going to be created.
	D3DPRESENT_PARAMETERS params = {0}; // Start by zeroing out the parameters
    
	// There's a bunch of parameters we could set up, however for this tutorial we
	// only care about a few.
	params.Windowed = TRUE; // This parameter says if the application runs in a window (TRUE)
						   // or is full screen (FALSE)
	params.SwapEffect = D3DSWAPEFFECT_DISCARD; // We're not enabling any double buffering, thus
											  // we discard any swap effect					  
    params.BackBufferFormat = D3DFMT_UNKNOWN; // We specify unknown for our back buffer so that
											 // it will choose whatever is the current display mode
											// as the format for the back buffer 
	params.EnableAutoDepthStencil = true; // Allow a Z-buffer and stencil buffer
	params.AutoDepthStencilFormat = D3DFMT_D16; // The format for the Z-buffer is 16-bit

	
	// Create the Direct3D device that lets us talk to the graphics card
	result = d3d_interface->CreateDevice(D3DADAPTER_DEFAULT,
										 D3DDEVTYPE_HAL,
										 hwnd,
										 D3DCREATE_HARDWARE_VERTEXPROCESSING,
										 &params,
										 &mDevice);

	// It's possible we'll get an error because not all vid-cards can handle vertex processing
	// So in the event we do get an error we'll try to make the device again.  We will
	// only change D3DCREATE_HARDWARE_VERTEXPROCESSING to D3DCREATE_SOFTWARE_VERTEXPROCESSING
	// which says, "Do the vertex processing in software" 
	if(result != D3D_OK)
	{
		result = d3d_interface->CreateDevice(D3DADAPTER_DEFAULT,
											 D3DDEVTYPE_HAL,
											 hwnd,
											 D3DCREATE_SOFTWARE_VERTEXPROCESSING,
											 &params,
											 &mDevice);
		if(result != D3D_OK)
			return false; // Couldn't create a D3D 9.0 device
	}
		
	// Turn off lighting
	mDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	
	// Turn on the zbuffer
    mDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
		
	RECT rect;
	GetClientRect(hwnd, &rect); // Get the client rect

	// Set the Aspect Ratio
	aspect_ratio = (float)rect.right / (float)rect.bottom;

	// Initialize all other parameters to a default value
	initToDefaultParams();
		return true; // We got loaded!
}

// Init all applicable parameters to a default value
void CD3DObj::initToDefaultParams()
{
	fov = kFOV; // Field of View
	near_clip = kNearClip; // Near Clip Plane
	far_clip = kFarClip; // Far Clip Plane
}

// Begins the scene
void CD3DObj::begin()
{
	// This begins our scene.
	result = mDevice->BeginScene();
	assert(result == D3D_OK);
}

// End the scene and draw it
void CD3DObj::end()
{
	// This ends the scene
	result = mDevice->EndScene();
	assert(result == D3D_OK);

	// This draws the scene to the screen
	result = mDevice->Present(NULL, NULL, NULL, NULL);
	assert(result == D3D_OK);
}

// Sets up the view of the scene based on the CCamera passed in
void CD3DObj::setViewMatrix(const CCamera *camera)
{
	D3DXMATRIXA16 matrix;

	// Create "D3D Vector" versions of our camera's eye, look at position, and up vector
	D3DXVECTOR3 eye(camera->getEye().x, camera->getEye().y, camera->getEye().z);
	D3DXVECTOR3 lookAt(camera->getTarget().x, camera->getTarget().y, camera->getTarget().z);
	D3DXVECTOR3 up(0, 1, 0); // The world's up vector
	
	// Using our camera's stuff (you know the eye, look at, and up vector) we 
	// create a matrix that represents our camera's view of the world.  Notice
	// the "LH" on the end of the function.  That says, "Hey create this matrix for
	// a left handed coordinate system".
	D3DXMatrixLookAtLH(&matrix, &eye, &lookAt, &up);
    mDevice->SetTransform(D3DTS_VIEW, &matrix); // Set our view of the world
}

void CD3DObj::setProjMatrix()
{
	D3DXMATRIXA16 matrix;

	// Here we're creating our projection matrix.  This is sometimes 
	// referred to as a "perspective transform" because what it does
	// is take our 3D geometry from our world and project it to 2D space,
	// our screen.  A quick run down of the parameters:
	// fov -- Field of View.  Essentially your peripheral vision
	// aspect_ratio -- Width of viewing area / Height of viewing area
	// near_clip -- Represents the plane that nothing can be rendered before
	// far_clip -- Represents the plane that nothing can be rendered after
    D3DXMatrixPerspectiveFovLH(&matrix, fov, aspect_ratio, near_clip, far_clip);
    mDevice->SetTransform(D3DTS_PROJECTION, &matrix);
}

// Sets "which" world matrix
void CD3DObj::setWorldMatrix(int which, D3DXMATRIX *matrix)
{
	assert(which >= 0 && which <= 255);
	assert(matrix != NULL);
	
	mDevice->SetTransform(D3DTS_WORLDMATRIX(which), matrix);
}

// Turns on or off fog
bool CD3DObj::setFogStatus(bool onOrOff)
{
	result = mDevice->SetRenderState(D3DRS_FOGENABLE, (DWORD)onOrOff);
		return (result == D3D_OK);
}

// Sets the fog color
bool CD3DObj::setFogColor(int color)
{
	result = mDevice->SetRenderState(D3DRS_FOGCOLOR, (DWORD)color);
		return (result == D3D_OK);
}

// Sets the mode, either D3DFOG_NONE, D3DFOG_EXP, D3DFOG_EXP2, or D3DFOG_LINEAR,
// for pixel based fog
bool CD3DObj::setPixelFogMode(D3DFOGMODE mode)
{
	result = mDevice->SetRenderState(D3DRS_FOGTABLEMODE, mode);
		return (result == D3D_OK);
}

// Sets the mode, either D3DFOG_NONE, D3DFOG_EXP, D3DFOG_EXP2, or D3DFOG_LINEAR,
// for vertex based fog
bool CD3DObj::setVertexFogMode(D3DFOGMODE mode)
{
	result = mDevice->SetRenderState(D3DRS_FOGVERTEXMODE, mode);
		return (result == D3D_OK);
}

// Sets the starting distance of the fog (applies only to D3DFOG_LINEAR fog) 
bool CD3DObj::setFogStart(float start)
{
	result = mDevice->SetRenderState(D3DRS_FOGSTART, (*(DWORD*)(&start)));
		return (result == D3D_OK);
}

// Sets the ending distance of the fog (applies only to D3DFOG_LINEAR fog) 
bool CD3DObj::setFogEnd(float end)
{
	result = mDevice->SetRenderState(D3DRS_FOGEND, (*(DWORD*)(&end)));
		return (result == D3D_OK);
}

// Sets the thickness of the fog (applies to D3DFOG_EXP and D3DFOG_EXP2 fog)
bool CD3DObj::setFogDensity(float density)
{
	result = mDevice->SetRenderState(D3DRS_FOGDENSITY, *((DWORD*)(&density)));
		return (result == D3D_OK);
}

// Renders the passed in vertex list using the passed in index list
bool CD3DObj::render(SVertex *vList, int vertCount, WORD *iList, int indexCount)
{
	IDirect3DVertexBuffer9 *vertexBuf = NULL; // Our interface for manipulating vertex buffers
	IDirect3DIndexBuffer9 *indexBuf = NULL; // Our interface for manipulating index buffers
	
	// Get the size of our vertex list
	int vertListSize = sizeof(SVertex) * vertCount;
	assert(vertListSize > 0);

	// Create the vertex buffer
	result = mDevice->CreateVertexBuffer(vertListSize, 0, SVertexType, 
											D3DPOOL_MANAGED, &vertexBuf, NULL);
											
	if(result != D3D_OK)
		return false;

	VOID *verts = NULL; // We'll use this as our pointer to the vertices

	// Now we fill the vertex buffer. To do this, we need to Lock() the vertex buffer to
	// gain access to the vertices
	result = vertexBuf->Lock(0, 0, (void**)&verts, 0);
	
		// Error Check
		if(result != D3D_OK)
		{
			vertexBuf->Release();
				return false;
		}
	
	// We have a pointer to our vertices, so we copy over our vertex list
	// that was passed into the function
	memcpy(verts, vList, vertListSize);
	vertexBuf->Unlock(); // We're done with the vertex buffer so we unlock it
	
	// Calculate the size of the index list
	int indexListSize = sizeof(WORD) * indexCount;
	assert(indexListSize > 0);

	// Create the index buffer
	result = mDevice->CreateIndexBuffer(indexListSize, 0, D3DFMT_INDEX16, 
										   D3DPOOL_MANAGED, &indexBuf, NULL);
	
	if(result != D3D_OK)
	{
		vertexBuf->Release(); // Free memory to this point
			return false;
	}

	VOID* indices = NULL; // We'll use this as the pointer to our indices 
	
	// Before we can fill the index buffer we need to Lock() the index buffer to
	// gain access to the indices
	result = indexBuf->Lock(0, 0, (void**)&indices, 0);

    if(result != D3D_OK)
    {
		// Free memory to this point
		vertexBuf->Release();
		indexBuf->Release();
			return false;
	}

	// Copy over the index buffer list
	memcpy(indices, iList, indexListSize);
	indexBuf->Unlock(); // We've copied the data, unlock the buffer

	// Tell our 3D device where the vertex data is coming from
	result = mDevice->SetStreamSource(0, vertexBuf, 0, sizeof(SVertex));
	assert(result == D3D_OK);

	// Tell our 3D device where the index data is coming from
	result = mDevice->SetIndices(indexBuf);
	assert(result == D3D_OK);

	// Specify the vertex type
	mDevice->SetFVF(SVertexType);
	
	// Draw the geometry
	result = mDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,vertCount,0,indexCount / 3);
	assert(result == D3D_OK);

	// Free up our buffers
	vertexBuf->Release();
	indexBuf->Release();
		return true;
}

// Clears the viewport to a specified ARGB color and the Z-buffer to the far clip plane
bool CD3DObj::clear(int color, float zDepth)
{
	// This clears our viewport and z-depth
	result = mDevice->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
							   color, zDepth, 0);
	return (result == D3D_OK);
}

// Deconstructor -- Free up all the memory
CD3DObj::~CD3DObj()
{
	if(mDevice != NULL)
		mDevice->Release();

    if(d3d_interface != NULL)
		d3d_interface->Release();

	// Zero out our D3D interface and device 
	mDevice = NULL;
	d3d_interface = NULL;
}

CD3DObj theD3DObj; // Create our 3D Object
CD3DObj *g3D = &theD3DObj; // Set the global pointer to our 3D Object
*/