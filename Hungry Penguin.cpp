#include<GL/glut.h>
#include<iostream>
#include <cmath>
#include<cstdio>
#include <windows.h>
#include<math.h>

#define M_PI (3.14159265358979323846)
# define PI 3.14159265358979323846

GLfloat q = 0.0f;
GLfloat position = 0.0f;
GLfloat speed = 0.01f;
int r = 0;

float angle = 0;

bool keyStates[256];


void setMaterial(GLfloat ambientR, GLfloat ambientG, GLfloat ambientB,
	GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
	GLfloat specularR, GLfloat specularG, GLfloat specularB,
	GLfloat shininess) {

	GLfloat ambient[] = { ambientR, ambientG, ambientB };
	GLfloat diffuse[] = { diffuseR, diffuseG, diffuseB };
	GLfloat specular[] = { specularR, specularG, specularB };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

void update(int value) {

	if (position > 1.0)
		position = -1.0f;

	position += speed;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}

void mainshape()
{
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 250, 250);;
	glVertex2f(-0.01f, 0.7f);
	glVertex2f(0.01f, 0.7f);
	glVertex2f(0.0f, 0.75f);
	glEnd();
	//main base
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 235, 205);
	glVertex2f(-0.2f, -0.1f);
	glVertex2f(0.2f, -0.1f);
	glVertex2f(0.0f, 0.7f);
	glEnd();

	//main base border
	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex2f(0.2f, -0.1f);
	glVertex2f(0.21f, -0.1f);
	glVertex2f(0.01f, 0.7f);
	glVertex2f(0.00f, 0.7f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex2f(-0.2f, -0.1f);
	glVertex2f(-0.21f, -0.1f);
	glVertex2f(-0.01f, 0.7f);
	glVertex2f(-0.00f, 0.7f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 235, 205);
	glVertex2f(0.21f, -0.1f);
	glVertex2f(0.3f, -0.1f);
	glVertex2f(0.06f, 0.5f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 235, 205);
	glVertex2f(-0.21f, -0.1f);
	glVertex2f(-0.3f, -0.1f);
	glVertex2f(-0.06f, 0.5f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex2f(0.3f, -0.1f);
	glVertex2f(0.31f, -0.1f);
	glVertex2f(0.055f, 0.52f);
	glVertex2f(0.054f, 0.5f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex2f(-0.3f, -0.1f);
	glVertex2f(-0.31f, -0.1f);
	glVertex2f(-0.055f, 0.52f);
	glVertex2f(-0.054f, 0.5f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 235, 205);
	glVertex2f(0.31f, -0.1f);
	glVertex2f(0.4f, -0.1f);
	glVertex2f(0.1f, 0.4f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 235, 205);
	glVertex2f(-0.31f, -0.1f);
	glVertex2f(-0.4f, -0.1f);
	glVertex2f(-0.1f, 0.4f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex2f(0.4f, -0.1f);
	glVertex2f(0.41f, -0.1f);
	glVertex2f(0.095f, 0.42f);
	glVertex2f(0.1f, 0.4f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex2f(-0.4f, -0.1f);
	glVertex2f(-0.41f, -0.1f);
	glVertex2f(-0.095f, 0.42f);
	glVertex2f(-0.1f, 0.4f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 235, 205);
	glVertex2f(0.41f, -0.1f);
	glVertex2f(0.5f, -0.1f);
	glVertex2f(0.167f, 0.3f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 235, 205);
	glVertex2f(-0.41f, -0.1f);
	glVertex2f(-0.5f, -0.1f);
	glVertex2f(-0.167f, 0.3f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex2f(0.5f, -0.1f);
	glVertex2f(0.51f, -0.1f);
	glVertex2f(0.1568f, 0.316f);
	glVertex2f(0.16f, 0.3f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex2f(-0.5f, -0.1f);
	glVertex2f(-0.51f, -0.1f);
	glVertex2f(-0.1568f, 0.316f);
	glVertex2f(-0.16f, 0.3f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 235, 205);
	glVertex2f(0.51f, -0.1f);
	glVertex2f(0.6f, -0.1f);
	glVertex2f(0.17f, 0.3f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 235, 205);
	glVertex2f(-0.51f, -0.1f);
	glVertex2f(-0.6f, -0.1f);
	glVertex2f(-0.17f, 0.3f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex2f(0.6f, -0.1f);
	glVertex2f(0.615f, -0.1f);
	glVertex2f(0.15f, 0.33f);
	glVertex2f(0.167f, 0.3f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex2f(-0.6f, -0.1f);
	glVertex2f(-0.615f, -0.1f);
	glVertex2f(-0.15f, 0.33f);
	glVertex2f(-0.167f, 0.3f);
	glEnd();

}

void sky()
{

	glBegin(GL_QUADS);
	glColor3f(0.686, 0.933, 0.933);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glEnd();

}

void sun()
{

	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(0.85, 0.85, 0.0);
	glutSolidSphere(0.1, 100, 100);
	glPopMatrix();
}

void cloud1()
{
	// glLoadIdentity();
	int i;

	GLfloat x = .5f; GLfloat y = .8f; GLfloat radius = .05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	GLfloat a = .55f; GLfloat b = .78f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
	glVertex2f(a, b); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			a + (radius * cos(i * twicePi / triangleAmount)),
			b + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	GLfloat c = .45f; GLfloat d = .78f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
	glVertex2f(c, d); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			c + (radius * cos(i * twicePi / triangleAmount)),
			d + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	GLfloat e = .52f; GLfloat f = .75f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
	glVertex2f(e, f); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			e + (radius * cos(i * twicePi / triangleAmount)),
			f + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	GLfloat g = .6f; GLfloat h = .77f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
	glVertex2f(g, h); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			g + (radius * cos(i * twicePi / triangleAmount)),
			h + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();


}

void cloud2()
{
	// glLoadIdentity();
	int i;

	GLfloat x = -.5f; GLfloat y = .8f; GLfloat radius = .05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	GLfloat a = -.55f; GLfloat b = .78f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
	glVertex2f(a, b); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			a + (radius * cos(i * twicePi / triangleAmount)),
			b + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	GLfloat c = -.45f; GLfloat d = .78f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
	glVertex2f(c, d); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			c + (radius * cos(i * twicePi / triangleAmount)),
			d + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	GLfloat e = -.52f; GLfloat f = .75f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
	glVertex2f(e, f); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			e + (radius * cos(i * twicePi / triangleAmount)),
			f + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	GLfloat g = -.6f; GLfloat h = .77f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(230, 255, 255);
	glVertex2f(g, h); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			g + (radius * cos(i * twicePi / triangleAmount)),
			h + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();


}


void bird()
{
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex2f(0.2f, 0.8f);
	glVertex2f(0.18f, 0.77f);

	glColor3ub(255, 255, 255);
	glVertex2f(0.18f, 0.77f);
	glVertex2f(0.15f, 0.79f);

	glColor3ub(255, 255, 255);
	glVertex2f(0.13f, 0.8f);
	glVertex2f(0.11f, 0.77f);

	glColor3ub(255, 255, 255);
	glVertex2f(0.11f, 0.77f);
	glVertex2f(0.08f, 0.79f);

	glEnd();

}

void water()
{
	glBegin(GL_QUADS);
	glColor3f(0.000, 0.749, 1.000);
	glVertex2f(-1.0f, -0.1f);
	glVertex2f(-1.0f, -.7f);
	glVertex2f(1.0f, -.7f);
	glVertex2f(1.0f, -.1f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.529, 0.808, 0.980);
	glVertex2f(-1.0f, -0.4f);
	glVertex2f(-1.0f, -.9f);
	glVertex2f(1.0f, -.9f);
	glVertex2f(1.0f, -.4f);
	glEnd();

}

void glacier1()
{

	glPushMatrix();
	glColor4f(0.118, 0.565, 1.000, 0.9);
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(1, -0.9, 0);
	glRotatef(angle, 1, 0, 0);
	glutSolidSphere(0.45, 15, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.000, 1.000, 1.000, 0.2);
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(1, -0.9, 0);
	glRotatef(angle, 1, 0, 0);
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();

}

void glacier2()
{

	glPushMatrix();
	glColor4f(0.118, 0.565, 1.000, 0.9);
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(-1, -0.3, 0);
	glRotatef(angle, 1, 0, 0);
	glutSolidSphere(0.6, 20, 50);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.000, 1.000, 1.000, 0.3);
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(-1, -0.3, 0);
	glRotatef(angle, 1, 0, 0);
	glutSolidSphere(0.5, 30, 50);
	glPopMatrix();


}
bool eaten = false;
void fish1()
{

	if (!eaten) {

		setMaterial(0.0, 0.5, 0, 0.0, 0.5, 0, 0, 0, 0, 15);
		glColor3f(0.2, 0.2, 0.2);
		//left fish
		//body
		glColor3f(1.0, 0.0, 0.0);  // Red color
		glPushMatrix();
		glTranslatef(-0.85, -0.35, -1.3);
		glutSolidSphere(0.09, 100, 100);
		glPopMatrix();

		// Tail of the fish (triangle)
		glColor3f(1.0, 0.0, 0.0);  // Red color
		glPushMatrix();
		glTranslatef(-0.9, -0.35, -1.3);
		glBegin(GL_TRIANGLES);
		glVertex2f(0.0, 0.0);
		glVertex2f(-0.1, 0.05);
		glVertex2f(-0.1, -0.05);
		glEnd();
		glPopMatrix();
	}


	//right fish
	//body
	glColor3f(1.0, 0.0, 0.0);  // Red color
	glPushMatrix();
	glTranslatef(0.85, -0.45, -1.3);
	glutSolidSphere(0.09, 100, 100);
	glPopMatrix();

	// Tail of the fish (triangle)
	glColor3f(1.0, 0.0, 0.0);  // Red color
	glPushMatrix();
	glTranslatef(0.9, -0.45, -1.3);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.1, 0.05);
	glVertex2f(0.1, -0.05);
	glEnd();
	glPopMatrix();

}


void glacier3()
{
	glPushMatrix();
	glColor4f(0.118, 0.565, 1.000, 0.9);
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(-0.19, -0.6, 0);
	glRotatef(angle, 1, 0, 0);
	glutSolidSphere(0.45, 17, 40);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.118, 0.565, 1.000, 0.9);
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(0.09, -0.64, 0);
	glRotatef(angle, 1, 0, 0);
	glutSolidSphere(0.30, 16, 40);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.000, 1.000, 1.000, 0.3);
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(-0.19, -0.6, 0);
	glRotatef(angle, 1, 0, 0);
	glutSolidSphere(0.35, 30, 40);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.000, 1.000, 1.000, 0);
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
	glTranslatef(0.09, -0.64, 0);
	glRotatef(angle, 1, 0, 0);
	glutSolidSphere(0.25, 30, 40);
	glPopMatrix();
}

void initLight()
{
	/* set up lights */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat lightpos[] = { 0.0, 0.0, 15.0 };
	GLfloat lightcolor[] = { 0.5, 0.5, 0.5 };
	GLfloat ambcolor[] = { 0.2, 0.2, 0.2 };
	GLfloat specular[] = { 1.0, 1.0, 1.0 };

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambcolor);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightcolor);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	glEnable(GL_COLOR_MATERIAL); // tells opengl to maintain the original color of the object
}

float waveOffset = 0;

void drawCuboid() {
	// Define the vertices of the cuboid
	GLfloat vertices[] = {
		-0.5, -0.5, -0.5,  // Vertex 0
		 0.5, -0.5, -0.5,  // Vertex 1
		 0.5,  0.5, -0.5,  // Vertex 2
		-0.5,  0.5, -0.5,  // Vertex 3
		-0.5, -0.5,  0.5,  // Vertex 4
		 0.5, -0.5,  0.5,  // Vertex 5
		 0.5,  0.5,  0.5,  // Vertex 6
		-0.5,  0.5,  0.5   // Vertex 7
	};

	// Define the faces of the cuboid using vertex indices
	int faces[][4] = {
		{0, 1, 2, 3}, // Front face
		{4, 5, 6, 7}, // Back face
		{0, 3, 7, 4}, // Left face
		{1, 2, 6, 5}, // Right face
		{0, 1, 5, 4}, // Bottom face
		{2, 3, 7, 6}  // Top face
	};

	for (int i = 0; i < 6; i++) {
		glBegin(GL_QUADS);
		for (int j = 0; j < 4; j++) {
			int vertexIndex = faces[i][j];
			glVertex3fv(&vertices[vertexIndex * 3]);
		}
		glEnd();
	}
}

bool leftUp = true;
void flipLeg(int x) {
	leftUp = !leftUp;
	glutTimerFunc(700, flipLeg, 9);
	glutPostRedisplay();
}

void drawCone() {
	const float radius = 0.1;
	const float height = 0.4;
	const int segments = 16;

	glBegin(GL_TRIANGLE_FAN);

	// Center of the base
	glVertex3f(0.0, 0.0, 0.0);

	for (int i = 0; i <= segments; i++) {
		float theta = 2.0 * M_PI * float(i) / float(segments);
		float x = radius * cos(theta);
		float y = radius * sin(theta);
		glVertex3f(x, y, 0.0);
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);

	// Apex of the cone
	glVertex3f(0.0, 0.0, height);

	for (int i = 0; i <= segments; i++) {
		float theta = 2.0 * M_PI * float(i) / float(segments);
		float x = radius * cos(theta);
		float y = radius * sin(theta);
		glVertex3f(x, y, 0.0);
	}

	glEnd();

	glBegin(GL_QUAD_STRIP);

	for (int i = 0; i <= segments; i++) {
		float theta = 2.0 * M_PI * float(i) / float(segments);
		float x = radius * cos(theta);
		float y = radius * sin(theta);
		glVertex3f(x, y, 0.0);
		glVertex3f(0.0, 0.0, height);
	}

	glEnd();
}


bool waving = false;

void drawAll() {



	//head
	setMaterial(0.0, 0.5, 0, 0.0, 0.5, 0, 0, 0, 0, 15);
	glColor3f(0.2, 0.2, 0.2);
	glutSolidSphere(0.7, 40, 40);

	//eyes
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 10);
	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0.25, 0.3, 0.44);
	glutSolidSphere(0.1, 10, 10);
	setMaterial(0.0, 0.5, 0, 0.0, 0.5, 0, 0, 0, 0, 15);
	glColor3f(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslatef(0, 0.1, 0);
	glutSolidSphere(0.05, 10, 10);
	glPopMatrix();
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 10);
	glColor3f(1, 1, 1);

	glTranslatef(-0.5, 0, 0);
	glutSolidSphere(0.1, 10, 10);
	setMaterial(0.0, 0.5, 0, 0.0, 0.5, 0, 0, 0, 0, 15);
	glColor3f(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslatef(0, 0.1, 0);
	glutSolidSphere(0.05, 10, 10);
	glPopMatrix();
	glPopMatrix();

	//beak
	glColor3f(1, 1, 0);
	setMaterial(0.0, 0.5, 0, 0.0, 0.5, 0, 1, 1, 0, 15);
	glPushMatrix();
	glTranslatef(0, 0.7, 0.15);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1.4, 1);
	drawCone();
	if (waving) {

		setMaterial(0.0, 0.5, 0, 0.0, 0.5, 0, 1, 0, 0, 15);
		glColor3f(1, 0, 0);
		glPushMatrix();
		glScalef(1, 1.4, 1);
		glutSolidSphere(0.2, 40, 40);
		glPopMatrix();

	}
	glPopMatrix();

	////stomach

	glPushMatrix();
	glScalef(0.9, 1, 1.5);
	glTranslatef(0, 0, -1.2);
	setMaterial(0.0, 0.5, 0, 0.0, 0.5, 0, 0, 0, 0, 15);
	glColor3f(0.2, 0.2, 0.2);
	glutSolidSphere(0.9, 40, 40);
	setMaterial(1, 1, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 10);
	glColor3f(1, 1, 1);
	glScalef(1, 1, 1);
	glutSolidSphere(0.65, 40, 40);
	glPopMatrix();

	//arms
	setMaterial(0.0, 0.5, 0, 0.0, 0.5, 0, 0, 0, 0, 15);
	glColor3f(0.2, 0.2, 0.2);

	glPushMatrix();
	glTranslatef(-1, 0, -1.3);
	glRotatef(30, 0, 1, 0);
	glScalef(1, 0.2, 4);
	glutSolidSphere(0.3f, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glRotatef(waveOffset, 0, 0, 1);
	glTranslatef(1, 0, -1.3);
	glRotatef(-30, 0, 1, 0);
	glScalef(1, 0.2, 4);
	glutSolidSphere(0.3f, 40, 40);
	glPopMatrix();


	//legs
	setMaterial(0.0, 0.5, 0, 0.0, 0.5, 0, 0, 0, 0, 15);
	glColor3f(0.2, 0.2, 0.2);
	glPushMatrix();
	if (!leftUp) {
		glRotatef(25, 1, 0, 0);
	}
	glScalef(0.4, 1.5, 0.3);
	glTranslatef(-1, 0.8, -8);
	drawCuboid();
	glPopMatrix();

	glPushMatrix();
	if (leftUp) {
		glRotatef(25, 1, 0, 0);
	}
	glScalef(0.4, 1.5, 0.3);
	glTranslatef(1, 0.8, -8);
	drawCuboid();
	glPopMatrix();

}

float xpos = -4, ypos = 0, zpos;


float tiltAngle = 0;
float heightOffset = 0;

bool facingRight = true;

GLfloat yOffset = 0, xOffset = 0;
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glLineWidth(2);
	sky();
	sun();
	glutSwapBuffers();
	glPushMatrix();
	glTranslatef(position, 0.0f, 0.0f);

	cloud1();
	cloud2();
	bird();
	glPopMatrix();
	mainshape();

	glacier2();
	water();
	glacier1();
	glacier3();
	fish1();
	glPushMatrix();


	glTranslatef(xpos + xOffset / 3, ypos + yOffset / 3 + heightOffset / 2, zpos);
	glTranslatef(0, 0, -2.5);
	glTranslatef(5.4, -1.8, -4);
	if (!facingRight) {
		//glScalef(1, -1, 1); 
		glRotatef(35, 0, 1, 0);
	}

	glRotatef((tiltAngle - 10) / 2, 0, 1, 0);
	glRotatef(290, 1, 0, 0);
	glRotatef(-20, 0, 0, 1);
	glScalef(-0.4, -0.4, 0.4);

	glTranslatef(0, 0, 2.5);
	drawAll();
	glPopMatrix();

	glFlush();
}

bool flying = false;
void stopFly(int a) {
	flying = false;
}

void stopWaving(int a) {
	waving = false;
}
void animate() {

	if (keyStates['k']) {

		eaten = true;

		waving = true;
		glutTimerFunc(100, stopWaving, 1);

	}

	if (keyStates[' ']) {
		flying = true;
		glutTimerFunc(100, stopFly, 1);

	}if (keyStates['w']) {
		yOffset += 0.01f;
	}
	if (keyStates['s']) {
		yOffset -= 0.01f;
	}
	if (keyStates['a']) {
		xOffset -= 0.01f;
		facingRight = true;
	}
	if (keyStates['d']) {
		xOffset += 0.01f;
		facingRight = false;
	}



	if (waveOffset > 0 && !waving) {
		waveOffset -= 0.58;
	}
	else if (waving && waveOffset < 90) {
		waveOffset += 0.88;
	}


	if (heightOffset > 0 && !flying) {
		heightOffset -= 0.01f;
	}
	else if (flying) {
		heightOffset += 0.03f;
	}

	if (leftUp) {
		tiltAngle -= 0.05;
	}
	else {
		tiltAngle += 0.05;

	}
	glutPostRedisplay();

}


void keyboardDown(unsigned char key, int x, int y) {
	keyStates[key] = true;
}

void keyboardUp(unsigned char key, int x, int y) {
	keyStates[key] = false;
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(900, 500);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Hungry penguin!");
	glutDisplayFunc(display);
	glutTimerFunc(10, update, 0);
	//glEnable(GL_DEPTH_TEST);
	//initLight();
	//glClearColor(0.53, 0.807, 0.9215,1);

	/* define the projection transformation */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25, 1, 2, 100);

	/* define the viewing transformation */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0.0, 4.1, 0.0, 0.0, 0.0, 0, 1, 0);

	glutIdleFunc(animate);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	flipLeg(9);
	glutMainLoop();
	return 0;
}