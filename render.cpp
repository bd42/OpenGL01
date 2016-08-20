#include <iostream>
#include "h/render.h"
#include "h/Object.h"

#include <GL/glut.h>

double rot = 0.0f;
void render(const double deltaTime)
{
	glPushMatrix();

	rot += deltaTime;
	//std::cout << 1 / deltaTime << std::endl; // Frames Per Second
	glRotatef(100.0f * rot, 0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS); // Begin quadrilateral coordinates
	
	// Trapezoid
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.7f, -1.5f, -5.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.7f, -1.5f, -5.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.4f, -0.5f, -5.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.4f, -0.5f, -5.0f);
	
	glEnd(); // End quadrilateral coordinates

	glPopMatrix();
	
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
}
