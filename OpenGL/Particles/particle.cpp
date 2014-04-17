#include "particle.h"
#include "gl_obj.h"

// Default constructor -- Zero everything out
CParticle::CParticle()
{
	color = ARGB(255, 255, 255, 255);
	size = 0.0f;
	life = 0.0f;
	angle = 0.0f;
	
	// All other variables gets initialized with it's constructor
}

// Init the particle
bool CParticle::init(const CPos &p, const CVector &v, float lifeSpan, float s, float a, int c,
					 const char *texName)
{
	pos = p; // Set the position
	vel = v; // Set the velocity
	
	// Don't allow initialization of a "dead" particle 
	if(lifeSpan <= 0.0f)
		return false;
	
	life = lifeSpan; // Set the time, in seconds, the particle will remain alive
	
	// Size must be positive
	if(s <= 0.0f)
		return false;
		
	size = s; // Set the size
	angle = a; // Set the angle of texture UV rotation per second
	color = c; // Set the color
	
	if(texName) // If a texture name was specified
		return texture.load(texName); // Load the texture
	else
		return true;
}

void CParticle::process(float dt)
{
	// If particle is dead, reset it's position
	if(isAlive() == false)
	{
		life = RAND(1.0f, 2.0f); // Make it alive again
		pos = CPos(0,0,0);
			return;
	}		

	// Apply velocity
	pos.x += vel.x * dt;
	pos.y += vel.y * dt;
	pos.z += vel.z * dt;
	
	// Apply gravity
	pos.y += kParticleGravity * dt;
		
	life -= dt; // Decrease particle's life span
	
	// Apply rotation by "angle" per second if applicable
	if(angle != 0.0f)
		texture.setRotation(texture.getRotAngle() + (angle * dt));
}

void CParticle::render()
{
	// If particle isn't alive, then there is nothing to render
	if(isAlive() == false)
		return;
	
	// Can't render a particle that does not have a valid texture 
	if(texture.getId() == TEXTURE_NOT_LOADED)
		return;
	
	// This OpenGL functions makes the Z-buffer "read only".  That means OpenGL will
	// use current z-buffer values to determine if a particle should be rendered or not, BUT,
	// if it does render a particle it will NOT set any z-buffer values.  Why do we do this?
	// Well we want the particles to blend, and not cover each other up.  So now we can
	// render them in the same Z-depth and they will blend, but at the same time, they 
	// won't render over top of anything with a lesser Z-depth
	glDepthMask(false);

	// Set the color and texture for rendering
	glColor4ub(GET_R(color), GET_G(color), GET_B(color), GET_A(color));
	texture.select();
	
	glPushMatrix();
	
		// Move to the world position of where to draw the particle
		glTranslatef(pos.x, pos.y, pos.z);
		
		float halfSize = size * 0.5f;
			
		// Draw the particle
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-halfSize, halfSize, 0.0f); // Top left vertex
			
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-halfSize, -halfSize, 0.0f); // Bottom left vertex
			
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(halfSize, -halfSize, 0.0f); // Bottom right vertex
			
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(halfSize, halfSize, 0.0f); // Top right vertex
		glEnd();
		
	glPopMatrix();
	
	glDepthMask(true); // Put the Z-buffer back into it's normal "Z-read and Z-write" state
}
	
	
	
		
	
	
	
	
	
	