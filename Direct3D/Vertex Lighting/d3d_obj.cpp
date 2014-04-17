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
int CD3DObj::mMaxLights = 0; // Maximum number of lights for the display device
D3DLIGHT9* CD3DObj::mLights = NULL; // Pointer to an array of D3D lights

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
		
	// Init the lights
	if(!initLights())
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

	// Turn on the z-buffer
	mResult = mDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
	assert(mResult == D3D_OK);
}

// Sets the type of light for "which" light
void CD3DObj::setLightType(int which, D3DLIGHTTYPE type)
{
	assert(which >= 0 && which < mMaxLights);

	mLights[which].Type = type;
}

// Sets the world position of "which" light
void CD3DObj::setLightPos(int which, const CPos &pos)
{
	assert(which >= 0 && which < mMaxLights);

	mLights[which].Position.x = pos.x;
	mLights[which].Position.y = pos.y;
	mLights[which].Position.z = pos.z;
}

// Sets the direction "which" light is shinning
void CD3DObj::setLightDir(int which, const CVector &dir)
{
	assert(which >= 0 && which < mMaxLights);

	mLights[which].Direction.x = dir.x;
	mLights[which].Direction.y = dir.y;
	mLights[which].Direction.z = dir.z;
}

// Sets "which" light three color values
// D3DLIGHT9 color values are between (0.0f, 1.0f)
void CD3DObj::setLightColor(int which, int diffuse, int specular, int ambient)
{
	assert(which >= 0 && which < mMaxLights);

	mLights[which].Diffuse.a = GET_A(diffuse) / 255.0f;
	mLights[which].Diffuse.b = GET_B(diffuse) / 255.0f;
	mLights[which].Diffuse.g = GET_G(diffuse) / 255.0f;
	mLights[which].Diffuse.r = GET_R(diffuse) / 255.0f;

	mLights[which].Specular.a = GET_A(specular) / 255.0f;
	mLights[which].Specular.b = GET_B(specular) / 255.0f;
	mLights[which].Specular.g = GET_G(specular) / 255.0f;
	mLights[which].Specular.r = GET_R(specular) / 255.0f;

	mLights[which].Ambient.a = GET_A(ambient) / 255.0f;
	mLights[which].Ambient.b = GET_B(ambient) / 255.0f;
	mLights[which].Ambient.g = GET_G(ambient) / 255.0f;
	mLights[which].Ambient.r = GET_R(ambient) / 255.0f;
}

// Sets "which" light's inner and outer radius that define
// it's intensity.  "innerCone" is the angle in radians of where the full intensity of the
// light will hit.  It must in the range of (0.0f, outerCone).  "outerCone" is the angle
// in radians of the complete area the light will illuminate.  It must be in the
// range of (0.0f, PI) 
void CD3DObj::setLightRadius(int which, float innerCone, float outerCone)
{
	assert(which >= 0 && which < mMaxLights);
	assert(innerCone >= 0.0f && innerCone <= outerCone);
	assert(outerCone >= 0.0f && outerCone <= D3DX_PI);	

	mLights[which].Theta = innerCone;
	mLights[which].Phi = outerCone;
}

// Sets the status (either on or off) of "which" light
void CD3DObj::setLightActive(int which, bool onOrOff)
{
	assert(which >= 0 && which < mMaxLights);

	// Tell the device about the light 
	mResult = mDevice->SetLight(which, &mLights[which]);
	assert(mResult == D3D_OK);

	// Either turn it on or off
	mResult = mDevice->LightEnable(which, onOrOff);
	assert(mResult == D3D_OK);
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
		return (mResult == D3D_OK);
}

// Renders a list of SVertex as a triangle strip
bool CD3DObj::renderTriStrip(SVertex *vertList, int numVerts)
{
	// Set the FVF 
	mDevice->SetFVF(SVertexType);

	// Render the line segments
	mResult = mDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, numVerts - 2, vertList, sizeof(SVertex));
		return (mResult == D3D_OK);
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
	if(mLights)
		delete[] mLights;

	if(mDevice != NULL)
		mDevice->Release();

	if(mInterface != NULL)
		mInterface->Release();

	// Zero out our D3D interface, device, and light pointer 
	mDevice = NULL;
	mInterface = NULL;
	mLights = NULL;

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

bool CD3DObj::initLights()
{
	D3DCAPS9 caps; // Struct to hold the device's capabilites

	// First we need to get the device's capabilites so we can determine
	// how many lights we can have
	if(mInterface->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps) != D3D_OK)
		return false;

	// Store the maximum number of lights
	mMaxLights = caps.MaxActiveLights;

	// Now we'll create an array of lights that is as big as 
	// the maximum number of lights we could possibly have
	mLights = new D3DLIGHT9[mMaxLights];

		// Error Check
		if(!mLights) return false;
		
	// Zero out the light structs
	ZeroMemory(mLights, sizeof(D3DLIGHT9) * mMaxLights);
		
	// Init each light struct to default values
	for(int i = 0; i < mMaxLights; ++i)
	{
		mLights[i].Type = D3DLIGHT_POINT;
		mLights[i].Attenuation1 = 1.0f;
		mLights[i].Falloff = 1.0f;
		mLights[i].Range = 255.0f;
		mLights[i].Diffuse.a = 1.0f; // Set diffuse color to solid white with full alpha
		mLights[i].Diffuse.b = 1.0f;
		mLights[i].Diffuse.g = 1.0f;
		mLights[i].Diffuse.r = 1.0f;
		mLights[i].Specular = mLights[i].Diffuse; // Specular is the same as diffuse color
		mLights[i].Phi = DEG2RAD(180);
		mLights[i].Theta = DEG2RAD(45);
		mLights[i].Direction = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	}
	
	return true; // Lights initialized properly
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

/*
#include <assert.h>
#include "d3d_obj.h"

// Constructor -- Zero out our data
CD3DObj::CD3DObj()
{
d3d_interface = NULL;
mDevice = NULL;

// Set data to zero
fov = aspect_ratio = near_clip = far_clip = 0.0f;
mResult = 0;

// Zero out lights
memset(lights, 0, sizeof(D3DLIGHT9));
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
params.SwapEffect = D3DSWAPEFFECT_DISCARD; // This is our D3DSWAPEFFECT parameter.  Similar to 
// Win32, you can optionally set up back buffers when
// using D3D.  However since we do not care about any
// back buffer stuff for this tutorial, we will discard
// any "swap effect".  This basically means things should
// technically be faster, but you may get a tearing effect
// or garbage rendered if you're not careful.								  
params.BackBufferFormat = D3DFMT_UNKNOWN; // Here we set what we want our D3DFORMAT to be.
// An example format would be D3DFMT_R8G8B8 which
// is a 24-bit RGB format.  However we choose 
// D3DFMT_UNKNOWN so that when the device is created
// the format that will be selected is the current
// desktop display format.
params.EnableAutoDepthStencil = true;
params.AutoDepthStencilFormat = D3DFMT_D16;


// All right we're done setting up our device parameters.  Time to make the
// device.  So by parameter:
// D3DADAPTER_DEFAULT -- Specifies which adapter to use.  D3DADAPTER_DEFAULT means always
//						 use the primary adapter.
// D3DDEVTYPE_HAL -- This is the D3DDEVTYPE.  It specifies what the device type will
//       			 be.  D3DDEVTYPE_HAL says the device will use hardware rasterization.
// hwnd -- This is the HWND to the window that the focus of the device belongs to.  Basically
//		   this answers the question "Which window owns this device?"
// D3DCREATE_HARDWARE_VERTEXPROCESSING -- This is a D3DCREATE flag.  It controls the behavior
//										  of the device.  This specific flag says, "Do the
//										  vertex processing in hardware."
// &params -- This is the address of the devices "presentation parameters".  It dictates how
//			  the device will present itself to the screen.  So such things as back buffers,
//			  refresh rate, and stencil format can be specified in this struct.
// &mDevice -- This is the address of a pointer to a IDirect3DDevice9.  This will get 
//				  filled in with the created device.
mResult = d3d_interface->CreateDevice(D3DADAPTER_DEFAULT,
D3DDEVTYPE_HAL,
hwnd,
D3DCREATE_HARDWARE_VERTEXPROCESSING,
&params,
&mDevice);

// It's possible we'll get an error because not all vid-cards can handle vertex processing
// So in the event we do get an error we'll try to make the device again.  We will
// only change D3DCREATE_HARDWARE_VERTEXPROCESSING to D3DCREATE_SOFTWARE_VERTEXPROCESSING
// which says, "Do the vertex processing in software" 
if(mResult != D3D_OK)
{
mResult = d3d_interface->CreateDevice(D3DADAPTER_DEFAULT,
D3DDEVTYPE_HAL,
hwnd,
D3DCREATE_SOFTWARE_VERTEXPROCESSING,
&params,
&mDevice);
if(mResult != D3D_OK)
return false; // Couldn't create a D3D 9.0 device
}

D3DCAPS9 d3dCaps;
mDevice->GetDeviceCaps(&d3dCaps);

// Make sure we can do spot lights and positional lights
if((d3dCaps.VertexProcessingCaps & D3DVTXPCAPS_POSITIONALLIGHTS) == 0)
return false; // Can't do spot/positional lights

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

// Init lights
for(int i = 0; i < mLights; ++i)
{
lights[i].Type = D3DLIGHT_POINT;
lights[i].Attenuation1 = 1.0f;
lights[i].Falloff = 1.0f;
lights[i].Range = 255.0f;
lights[i].Diffuse.a = lights[i].Diffuse.b = lights[i].Diffuse.g = lights[i].Diffuse.r = 1.0f;
lights[i].Specular = lights[i].Diffuse;
lights[i].Phi = DEG2RAD(180);
lights[i].Theta = DEG2RAD(45);
lights[i].Direction = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
}
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

// This presents (draws) the next back buffer (we only have one in our case) to the screen
// By parameter:
// NULL -- Must be NULL unless a swap chain was created with D3DSWAPEFFECT_COPY
//		   **NOTE** We used D3DSWAPEFFECT_DISCARD
// NULL -- Must be NULL unless a swap chain was created with D3DSWAPEFFECT_COPY
// NULL -- HWND whose client area is taken as the target for this presentation.  If this is
//		   NULL then the HWND set in the D3DPRESENT_PARAMETERS (set in our init() function)
//		   is used
// NULL -- Must be NULL unless a swap chain was created with D3DSWAPEFFECT_COPY 
mResult = mDevice->Present(NULL, NULL, NULL, NULL);
assert(mResult == D3D_OK);
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

// Sets the type of light for "which" light
void CD3DObj::setLightType(int which, D3DLIGHTTYPE type)
{
assert(which >= 0 && which < mLights);

lights[which].Type = type;
}

// Sets the world position of "which" light
void CD3DObj::setLightPos(int which, const CPos &pos)
{
assert(which >= 0 && which < mLights);

lights[which].Position.x = pos.x;
lights[which].Position.y = pos.y;
lights[which].Position.z = pos.z;
}

// Sets the direction "which" light is shinning
void CD3DObj::setLightDir(int which, const CVector &dir)
{
assert(which >= 0 && which < mLights);

lights[which].Direction.x = dir.x;
lights[which].Direction.y = dir.y;
lights[which].Direction.z = dir.z;
}

// Sets "which" light three color values
// D3DLIGHT9 color values are between (0.0f, 1.0f)
void CD3DObj::setLightColor(int which, int diffuse, int specular, int ambient)
{
assert(which >= 0 && which < mLights);

lights[which].Diffuse.a = GET_A(diffuse) / 255.0f;
lights[which].Diffuse.b = GET_B(diffuse) / 255.0f;
lights[which].Diffuse.g = GET_G(diffuse) / 255.0f;
lights[which].Diffuse.r = GET_R(diffuse) / 255.0f;

lights[which].Specular.a = GET_A(specular) / 255.0f;
lights[which].Specular.b = GET_B(specular) / 255.0f;
lights[which].Specular.g = GET_G(specular) / 255.0f;
lights[which].Specular.r = GET_R(specular) / 255.0f;

lights[which].Ambient.a = GET_A(ambient) / 255.0f;
lights[which].Ambient.b = GET_B(ambient) / 255.0f;
lights[which].Ambient.g = GET_G(ambient) / 255.0f;
lights[which].Ambient.r = GET_R(ambient) / 255.0f;
}

// Sets "which" light's inner and outer radius that define
// it's intensity.  "innerCone" is the angle in radians of where the full intensity of the
// light will hit.  It must in the range of (0.0f, outerCone).  "outerCone" is the angle
// in radians of the complete area the light will illuminate.  It must be in the
// range of (0.0f, PI) 
void CD3DObj::setLightRadius(int which, float innerCone, float outerCone)
{
assert(which >= 0 && which < mLights);
assert(innerCone >= 0.0f && innerCone <= outerCone);
assert(outerCone >= 0.0f && outerCone <= D3DX_PI);	

lights[which].Theta = innerCone;
lights[which].Phi = outerCone;
}

// Sets the status (either on or off) of "which" light
void CD3DObj::setLightStatus(int which, bool onOrOff)
{
assert(which >= 0 && which < mLights);

// Tell the device about the light 
mResult = mDevice->SetLight(which, &lights[which]);
assert(mResult == D3D_OK);

// Either turn it on or off
mResult = mDevice->LightEnable(which, onOrOff);
assert(mResult == D3D_OK);
}

// Renders the passed in tri strip
bool CD3DObj::renderTriStrip(SVertex *vList, int vertCount)
{
assert(vertCount > 2); // Better to be safe than sorry

IDirect3DVertexBuffer9 *vertexBuf = NULL; // Our interface for manipulating vertex buffers

// Get the size of our vertex list
int vertListSize = sizeof(SVertex) * vertCount;
assert(vertListSize > 0);

// Create the vertex buffer
mResult = mDevice->CreateVertexBuffer(vertListSize, 0, SVertexType, 
D3DPOOL_MANAGED, &vertexBuf, NULL);

if(mResult != D3D_OK)
return false;

VOID *verts = NULL; // We'll use this as our pointer to the vertices

// Now we fill the vertex buffer. To do this, we need to Lock() the vertex buffer to
// gain access to the vertices
mResult = vertexBuf->Lock(0, 0, (void**)&verts, D3DLOCK_DISCARD);

// Error Check
if(mResult != D3D_OK)
{
vertexBuf->Release();
return false;
}

// We have a pointer to our vertices, so we copy over our vertex list
// that was passed into the function
memcpy(verts, vList, vertListSize);
vertexBuf->Unlock(); // We're done with the vertex buffer so we unlock it

// Tell our 3D device where the vertex data is coming from
mResult = mDevice->SetStreamSource(0, vertexBuf, 0, sizeof(SVertex));
assert(mResult == D3D_OK);

// Specify the vertex type
mDevice->SetFVF(SVertexType);

// Draw the geometry
mResult = mDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, vertCount - 2);
assert(mResult == D3D_OK);

// Free up our buffers
vertexBuf->Release();
return true;
}

// Clears the viewport to a specified ARGB color and the Z-buffer to the far clip plane
bool CD3DObj::clear(int color, float zDepth)
{
// Clear the viewport to the color and z-depth passed in
mResult = mDevice->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, 
color, zDepth, 0);
return (mResult == D3D_OK);
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