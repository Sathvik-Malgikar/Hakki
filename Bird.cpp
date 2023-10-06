#include <math.h>
#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <fstream>


using namespace std;

//Body Measurments found to work
#define STEP 0.1
#define TORSO_HEIGHT 6.0
#define TORSO_RADIUS 2.0
#define UPPER_ARM_HEIGHT 3.0
#define UPPER_ARM_RADIUS  0.5
#define LOWER_ARM_HEIGHT 2.5
#define LOWER_ARM_RADIUS  0.5
#define UPPER_LEG_HEIGHT 4.0
#define UPPER_LEG_RADIUS  0.6
#define LOWER_LEG_HEIGHT 3.5
#define LOWER_LEG_RADIUS  0.6
#define ELBOW_RADIUS 0.6
#define KNEE_RADIUS 0.7
#define HAND_RADIUS 0.6
#define FOOT_RADIUS 0.7
#define SHOULDER_RADIUS 0.8
#define HEAD_HEIGHT 1.5
#define HEAD_RADIUS 1.0
#define NECK_HEIGHT 1.0
#define NECK_RADIUS 0.4

//null refrance for linking
#define zzero 0

//gloabal variables needed
int option = -1;
int animation = -3;
int done = 0;
double rotate1 = 0;
double horizontal = 0;
bool inAir = false;


#define PI 3.14159265358979323846

float leftWing = 3;
float incr = 0.1;
float incrtrans = 0.1;
float posX = 0;
float posY = 0;
bool flying = false;


float xrot = 0.0f;
float yrot = 0.0f;

bool mouseDown = false;



double valZoom = 10.0;



double camX = 0, camY = 0, camZ = 5.0f;


typedef float point[3];



double size = 1.0;


bool leftFront = true;

void flipLegs(int a) {
	leftFront = !leftFront;
	glutTimerFunc(700, flipLegs, 0);
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

	glEnable(GL_COLOR_MATERIAL); // tells opengl to maintain the original color of the object
}






void drawSphere(GLfloat x, GLfloat y) {
	glPushMatrix();


	glutSolidSphere(0.1, 30, 30);

	glPopMatrix();

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


void bird()
{

	//glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	//glPushMatrix();

	//glLoadIdentity();
	/*  gluLookAt(
		  camX, camY, camZ,
		  0.0f, 0.0f, 0.0f,
		  0.0f, 1.0f, 0.0f
	  );
	  */
	glPushMatrix();

	//glRotatef(leftWing, 0, 0, 1);

	//float xOffset = 0.35f;
	


	glTranslatef(0.0f, -0.3f, 0.0f);
	//glRotatef(leftWing, -1.0f, 0.0f, 0.0f);
	glScalef(0.4f, 1.2f, 0.2f);  // Ellipse shape
	// Set material properties (for coloring)
	//GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 }; // Red color
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glColor3f(0.957f, 0.643f, 0.376f);
	setMaterial(0.0, 0.5, 1, 0.0, 0.5, 1.0, 1, 1, 1, 50);
	
	glutSolidSphere(0.2, 16, 16); 
	glPopMatrix();

	//stomach front
	glPushMatrix();

	//glRotatef(leftWing, 0, 0, 1);

	//float xOffset = 0.35f;



	glTranslatef(0.0f, -0.3f, -2.0f);
	//glRotatef(leftWing, -1.0f, 0.0f, 0.0f);
	glScalef(0.4f, 1.2f, 0.2f);  // Ellipse shape
	// Set material properties (for coloring)
	//GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 }; // Red color
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glColor3f(1,1,1);
	setMaterial(0.0, 0.5, 1, 1, 1, 1.0, 1, 1, 1, 50);

	glutSolidSphere(0.2, 16, 16);
	glPopMatrix();


	glPushMatrix();

	//glRotatef(-leftWing, 0, 0, 1);

	//xOffset = 0.35f;
	glColor3f(0.1, 1, 0.1);


	glTranslatef(0.0f + 0.1f , -0.5f, 0);
	glRotatef(-70, 0, 0.0f, 1);
	//glRotatef(2*leftWing, 0, 1, 0);
	if (leftFront) {

		glScalef(0.6f, 0.2f, 0.2f);  // Ellipse shape
	}
	else {

		glScalef(0.4f, 0.2f, 0.2f);  // Ellipse shape
	}  // Ellipse shape

	glColor3f(1, 0.647f, 0);
	setMaterial(0.0, 0.5, 1, 0.0, 0.5, 1.0, 1, 1, 1, 50);
	glutSolidSphere(0.2, 16, 16);
	glPopMatrix();
	glPushMatrix();

	//glRotatef(-leftWing, 0, 0, 1);

	//xOffset = 0.35f;
	glColor3f(0.1, 1, 0.1);


	glTranslatef(0.0f - 0.1f, -0.5f, 0);
	glRotatef(70, 0, 0.0f, 1);
	//glRotatef(-2*leftWing, 0, -1, 0);
	//glRotatef(70, 0, 0.0f, 1);
	if (leftFront) {

	glScalef(0.4f, 0.2f, 0.2f);  // Ellipse shape
	}
	else {

	glScalef(0.6f, 0.2f, 0.2f);  // Ellipse shape
	}
	glColor3f(1, 0.647f, 0);
	setMaterial(0.0, 0.5, 1, 0.0, 0.5, 1.0, 1, 1, 1, 50);

	glutSolidSphere(0.2, 16, 16);
	glPopMatrix();



	//glTranslatef(posX, posY, 0);
	glRotatef(75, 0, 1, 0);





	glColor3f(1, 0.84, 0.75);
	//head
	drawSphere(0, 0); 

	glBegin(GL_QUADS);
	/* glVertex2f(-0.1, 0.1);
	 glVertex2f(0.1, 0.1);
	 glVertex2f(0.1, -0.1);
	 glVertex2f(-0.1, -0.1);*/

	glColor3f(0, 0, 0);

	glVertex2f(-0.1 / 2, 0.1 / 2);
	glVertex2f(-0.1 / 2 + 0.01, 0.1 / 2);
	glVertex2f(-0.1 / 2 + 0.01, 0.1 / 2 - 0.01);
	glVertex2f(-0.1 / 2, 0.1 / 2 - 0.01);

	glVertex2f(0.1 / 2, 0.1 / 2);
	glVertex2f(0.1 / 2 + 0.01, 0.1 / 2);
	glVertex2f(0.1 / 2 + 0.01, 0.1 / 2 - 0.01);
	glVertex2f(0.1 / 2, 0.1 / 2 - 0.01);




	glEnd();

	glBegin(GL_TRIANGLES);

	glVertex2f(-0.03, 0);
	glVertex2f(0.03, 0);
	glVertex2f(0, -0.07);
	glEnd();




	glPushMatrix();

	glRotatef(leftWing, 0, 0, 1);

	float xOffset = 0.35f;
	glColor3f(0.1, 1, 0.1);


	glTranslatef(0.0f - xOffset, -0.1f, 0.0f);
	//glRotatef(leftWing, -1.0f, 0.0f, 0.0f);
	glScalef(2.0f, 0.2f, 0.2f);  // Ellipse shape

	glColor3f(0.529, 0.808, 0.922);
	setMaterial(0.0, 0.5, 1, 0.0, 0.5, 1.0, 1, 1, 1, 50);

	glutSolidSphere(0.2, 16, 16);
	glPopMatrix();


	glPushMatrix();

	glRotatef(-leftWing, 0, 0, 1);

	xOffset = 0.35f;
	glColor3f(0.1, 1, 0.1);


	glTranslatef(0.0f + xOffset, -0.1f, 0.0f);
	//glRotatef(leftWing, -1.0f, 0.0f, 0.0f);
	glScalef(2.0f, 0.2f, 0.2f);  // Ellipse shape
	glColor3f(0.529, 0.808, 0.922);
	setMaterial(0.0, 0.5, 1, 0.0, 0.5, 1.0, 1, 1, 1, 50);
	//wings
	glutSolidSphere(0.2, 16, 16);
	glPopMatrix();
	//glLoadIdentity();



	//glPopMatrix();

	//glFlush();



}

void sky()
{
	glBegin(GL_QUADS);
	glColor3ub(38, 154, 214);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glEnd();
}



////////end of creation section//////////
void display(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-15, 15, -15, 15, -15, 15);
	glRotatef(rotate1, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	sky();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.4, 0.4, 0.4);
	//traverse(&torso_node);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(posX, posY, 10);
	glScalef(15, 15, 15);

	bird();


	glPopMatrix();
	glutSwapBuffers();
}



void idle()
{

	if (!flying)
		return;

	leftWing += incr;
	posY += incr * 0.0023f;

	if (leftWing > 70) {
		incr = -0.1;
		leftWing = 70;
	}

	if (leftWing < 0) {
		incr = 0.1;
		leftWing = 0;
	}


	glutPostRedisplay();
}





void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-10.0, 10.0, -10.0 * (GLfloat)h / (GLfloat)w,
			10.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-10.0 * (GLfloat)w / (GLfloat)h,
			10.0 * (GLfloat)w / (GLfloat)h, 0.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void kbFunc(unsigned char key, int x, int y) {
	switch (key) {

		//case 'w':
	 //    posY += incr*0.2f;
	 //    break;
	 //case 's':
	 //    posY -= incr * 0.2f;
	 //    break;
	case ' ':
		flying = !flying;
		//posY += incr * 0.2f;
		break;
	case 'a':
		posX -= incrtrans * 1;
		break;
	case 'd':
		posX += incrtrans * 1;
		break;
	default:
		break;
	}
	glutPostRedisplay(); // Request a redraw
}

int main(int argc, char** argv)
{
	flipLegs(9);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Dancing Robot");

	glutReshapeFunc(myReshape);
	glutIdleFunc(idle);
	glEnable(GL_DEPTH_TEST);
	initLight();
	glutDisplayFunc(display);
	glutKeyboardFunc(kbFunc);

	glutMainLoop();
	return 0;
}