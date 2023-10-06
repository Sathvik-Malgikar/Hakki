#include<GL/glut.h>
#include<iostream>
#include <cmath>

#define M_PI (3.14159265358979323846)

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
void drawAll() {


	//head
	setMaterial(0.0, 0.5, 0, 0.0, 0.5, 0, 0, 0, 0, 15);
	glColor3f(0.2, 0.2, 0.2);
	glutSolidSphere(0.7, 40, 40);

	//eyes
	setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 10);
	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0.25, 0.7, 0.44);
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
	glPopMatrix();

	////stomach

	glPushMatrix();
	glScalef(0.9, 1, 2.2);
	glTranslatef(0, 0, -1.2);
	setMaterial(0.0, 0.5, 0, 0.0, 0.5, 0, 0, 0, 0, 15);
	glColor3f(0.2, 0.2, 0.2);
	glutSolidSphere(0.9, 40, 40);
	setMaterial(1, 1, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 10);
	glColor3f(1, 1, 1);
	glScalef(1, 2.5, 1);
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
	glTranslatef(1, 0, -1.3);
	glRotatef(-30, 0, 1, 0);
	glScalef(1, 0.2, 4);
	glutSolidSphere(0.3f, 40, 40);
	glPopMatrix();


	//legs
	glColor3f(0, 0, 0);
	setMaterial(0, 0, 0, 00, 0, 0, 0, 0, 0, 0);
	glPushMatrix();
	if (!leftUp) {
		glRotatef(25, 1, 0, 0);
	}
	glScalef(0.4, 1.5, 0.3);
	glTranslatef(-1, 0.8 , -12);
	drawCuboid();
	glPopMatrix();

	glPushMatrix();
	if (leftUp) {
		glRotatef(25, 1, 0, 0);
	}
	glScalef(0.4, 1.5, 0.3);
	glTranslatef(1, 0.8 , -12);
	drawCuboid();
	glPopMatrix();

}

float xpos=-4, ypos=0, zpos;


float tiltAngle = 0;
float heightOffset = 0;
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(xpos, ypos  , zpos + heightOffset);
	glTranslatef(0,0,-2.5);
	glRotatef(-tiltAngle-5, 0, 0, 1);
	glRotatef((tiltAngle -10 )/2, 0, 1, 0);
	glTranslatef(0,0,2.5);
	drawAll();
	glPopMatrix();

	glFlush();
}

bool flying = false ;

void animate() {
	if (heightOffset > 0 && !flying) {
		heightOffset -= 0.01f;
	}
	else if (flying) {
		heightOffset += 0.03f;
	}

	if (leftUp){
		tiltAngle -= 0.02;
	}
	else {
		tiltAngle += 0.02;

	}
	glutPostRedisplay();

}
void stopFly(int a) {
	flying = false;
}
void kbFunc(unsigned char key, int x, int y) {

	switch (key) {
	case ' ' :
		flying = true;
		glutTimerFunc(100, stopFly, 1); 
		break;
	}

}

int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(900, 500);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("I have kids");
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	initLight();
	glClearColor(0.53, 0.807, 0.9215,1);

	/* define the projection transformation */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 4, 100);

	/* define the viewing transformation */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

	glutIdleFunc(animate);
	glutKeyboardFunc(kbFunc);
	flipLeg(9);
	glutMainLoop();
	return 0;
}