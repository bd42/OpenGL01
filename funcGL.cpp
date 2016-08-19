#include "funcGL.h"
#include "funcMisc.h"

#include <stdlib.h> // Needed for "exit" function

#include <GL/glut.h>

// Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y)
{
	#define ESCAPE 27

	switch (key)
	{
		case ESCAPE:
			exit(0); // Exit the program
			break;
	}
}

// Initializes 3D rendering
void initRendering()
{
	// Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
	// Allows us to use colors
	glEnable(GL_COLOR_MATERIAL);
}

// Called when the window is resized
void handleResize(int w, int h)
{
	// Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION); // Switch to setting the camera perspective
	
	// Set the camera perspective
	glLoadIdentity(); // Reset the camera
	gluPerspective(45.0,                  // The camera angle
				   (double)w / (double)h, // The width-to-height ratio
				   1.0,                   // The near z clipping coordinate
				   200.0);                // The far z clipping coordinate
}

// Draws the 3D scene
void drawScene()
{
	double deltaTime = getDeltaTime();

	// Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW); // Switch to the drawing perspective
	glLoadIdentity(); // Reset the drawing perspective
	
	glBegin(GL_QUADS); // Begin quadrilateral coordinates
	
	// Trapezoid
	glVertex3f(-0.7f, -1.5f, -5.0f);
	glVertex3f(0.7f, -1.5f, -5.0f);
	glVertex3f(0.4f, -0.5f, -5.0f);
	glVertex3f(-0.4f, -0.5f, -5.0f);
	
	glEnd(); // End quadrilateral coordinates
	
	glBegin(GL_TRIANGLES); // Begin triangle coordinates
	
	// Pentagon
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, -5.0f);
	glVertex3f(1.5f, 0.5f, -5.0f);
	glVertex3f(0.5f, 1.0f, -5.0f);
	
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.5f, 1.0f, -5.0f);
	glVertex3f(1.5f, 0.5f, -5.0f);
	glVertex3f(1.5f, 1.0f, -5.0f);
	
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, 1.0f, -5.0f);
	glVertex3f(1.5f, 1.0f, -5.0f);
	glVertex3f(1.0f, 1.5f, -5.0f);
	
	// Triangle
	glVertex3f(-0.5f, 0.5f, -5.0f);
	glVertex3f(-1.0f, 1.5f, -5.0f);
	glVertex3f(-1.5f, 0.5f, -5.0f);
	
	glEnd(); // End triangle coordinates
	
	glutSwapBuffers(); // Send the 3D scene to the screen
}