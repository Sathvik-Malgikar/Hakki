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


void head();
void torso();
void left_upper_arm();
void right_upper_arm();
void left_upper_leg();
void right_upper_leg();

typedef float point[3];

//the node that links the shapes
typedef struct treenode
{
	GLfloat m[16];
	void(*f)();
	struct treenode* sibling;
	struct treenode* child;
}treenode;

typedef treenode* t_ptr;

//initial joint angles
/*
0:
1: 	neck
2:
3:	Left Upper Arm
4:	Left Lower Arm
5: 	Right Upper Arm
6:	Right Lower Arm
7:	Left Upper Leg
8:	Left Lower Leg
9:  Right Upper leg
10: Right Lower Leg
*/
static GLfloat theta[11] = { 0.0,0.0,0.0,180.0,0.0,180.0,0.0,
180.0,0.0,180.0,0.0 };

//points of cinlders
GLUquadricObj* t, * h, * lua, * lla, * rua, * rla, * lll, * rll, * rul, * lul;

//points of circles
GLUquadricObj* relb, * lelb, * rknee, * lknee, * nk, * lhand, * rhand, * lfoot, * rfoot, * rsh, * lsh;

double size = 1.0;

//creation of body part tree noes
treenode torso_node, head_node, lua_node, rua_node, lll_node, rll_node,
lla_node, rla_node, rul_node, lul_node,
relb_node, lelb_node, rknee_node, lknee_node, nk_node, lhand_node, rhand_node, lfoot_node, rfoot_node,
rsh_node, lsh_node;


void traverse(treenode* root)
{
	if (root == zzero) return;
	glPushMatrix();
	glMultMatrixf(root->m);
	root->f();
	if (root->child != zzero) traverse(root->child);
	glPopMatrix();
	if (root->sibling != zzero) traverse(root->sibling);
}

///////////////creation section///////////////////////
void torso()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(t, TORSO_RADIUS / 1.2, TORSO_RADIUS, TORSO_HEIGHT, 10, 10);
	glPopMatrix();
}

void head()
{
	glPushMatrix();
	glTranslatef(0.0, HEAD_HEIGHT, 0.0);
	glScalef(HEAD_RADIUS, HEAD_HEIGHT, HEAD_RADIUS);
	gluSphere(h, HEAD_RADIUS, 10, 10);
	glPopMatrix();
}

void neck()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(nk, NECK_RADIUS, NECK_RADIUS, NECK_HEIGHT, 10, 10);
	glPopMatrix();
}

void rightShoulder()
{
	glPushMatrix();
	gluSphere(relb, SHOULDER_RADIUS, 10, 10);
	glPopMatrix();
}

void leftShoulder()
{
	glPushMatrix();
	gluSphere(lelb, SHOULDER_RADIUS, 10, 10);
	glPopMatrix();
}

void rightElbow()
{
	glPushMatrix();
	gluSphere(relb, ELBOW_RADIUS, 10, 10);
	glPopMatrix();
}

void leftElbow()
{
	glPushMatrix();
	gluSphere(lelb, ELBOW_RADIUS, 10, 10);
	glPopMatrix();
}

void rightKnee()
{
	glPushMatrix();
	gluSphere(rknee, KNEE_RADIUS, 10, 10);
	glPopMatrix();
}

void leftKnee()
{
	glPushMatrix();
	gluSphere(lknee, KNEE_RADIUS, 10, 10);
	glPopMatrix();
}

void leftFoot()
{
	glPushMatrix();
	gluSphere(lknee, FOOT_RADIUS, 10, 10);
	glPopMatrix();
}

void rightFoot()
{
	glPushMatrix();
	gluSphere(lknee, FOOT_RADIUS, 10, 10);
	glPopMatrix();
}

void rightHand()
{
	glPushMatrix();
	gluSphere(lknee, HAND_RADIUS, 10, 10);
	glPopMatrix();
}

void leftHand()
{
	glPushMatrix();
	gluSphere(lknee, HAND_RADIUS, 10, 10);
	glPopMatrix();

}

void left_upper_arm()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(lua, UPPER_ARM_RADIUS, UPPER_ARM_RADIUS - 0.1, UPPER_ARM_HEIGHT, 10, 10);
	glPopMatrix();
}

void left_lower_arm()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(lla, LOWER_ARM_RADIUS - 0.1, LOWER_ARM_RADIUS - 0.15, LOWER_ARM_HEIGHT, 10, 10);
	glPopMatrix();
}

void right_upper_arm()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(rua, UPPER_ARM_RADIUS, UPPER_ARM_RADIUS - 0.1, UPPER_ARM_HEIGHT, 10, 10);
	glPopMatrix();
}

void right_lower_arm()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(rla, LOWER_ARM_RADIUS - 0.1, LOWER_ARM_RADIUS - 0.15, LOWER_ARM_HEIGHT, 10, 10);
	glPopMatrix();
}

void left_upper_leg()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(lul, UPPER_LEG_RADIUS, UPPER_LEG_RADIUS - 0.1, UPPER_LEG_HEIGHT, 10, 10);
	glPopMatrix();
}

void left_lower_leg()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(lll, LOWER_LEG_RADIUS - 0.1, LOWER_LEG_RADIUS - 0.2, LOWER_LEG_HEIGHT, 10, 10);
	glPopMatrix();
}

void right_upper_leg()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(rul, UPPER_LEG_RADIUS, UPPER_LEG_RADIUS - 0.1, UPPER_LEG_HEIGHT, 10, 10);
	glPopMatrix();
}

void right_lower_leg()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(rll, LOWER_LEG_RADIUS - 0.1, LOWER_LEG_RADIUS - 0.2, LOWER_LEG_HEIGHT, 10, 10);
	glPopMatrix();
}

 
void drawSphere(GLfloat x, GLfloat y) {
	glPushMatrix();


	glutSolidSphere(0.1, 30, 30);

	glPopMatrix();

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
		glTranslatef(posX, posY, 0);
		glRotatef(75, 0, 1, 0);





		glColor3f(1, 0.84, 0.75);

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
		glScalef(1.0f, 0.2f, 0.2f);  // Ellipse shape
		glutSolidSphere(0.2, 16, 16);
		glPopMatrix();


		glPushMatrix();

		glRotatef(-leftWing, 0, 0, 1);

		xOffset = 0.35f;
		glColor3f(0.1, 1, 0.1);


		glTranslatef(0.0f + xOffset, -0.1f, 0.0f);
		//glRotatef(leftWing, -1.0f, 0.0f, 0.0f);
		glScalef(1.0f, 0.2f, 0.2f);  // Ellipse shape
		glutSolidSphere(0.2, 16, 16);
		glPopMatrix();


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
	traverse(&torso_node);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(10, 0.4f, 10);
	glScalef(5, 5, 5);

	bird();
	
	glPopMatrix();
	glutSwapBuffers();
}

/////////////Animation/////////////////////

void inverseKinematics()
{
	switch (animation)
	{
	case 0: //raise arms / lower neck
		if (theta[5] < 180.0)
		{
			theta[5] += STEP;
			theta[3] += STEP;
			theta[1] -= 0.2 * STEP;
		}
		else animation = option;

		glPushMatrix();

		glLoadIdentity();
		glTranslatef(0, 0, 0.0);
		glRotatef(theta[5], 1.0, 0.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, rua_node.m);

		glLoadIdentity();
		glTranslatef(0, 0, 0.0);
		glRotatef(theta[3], 1.0, 0.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, lua_node.m);

		glLoadIdentity();
		glTranslatef(0.0, TORSO_HEIGHT - 0.25 * NECK_HEIGHT, 0.0);
		glRotatef(theta[1], 1.0, 0.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, nk_node.m);

		glPopMatrix();
		break;
	case 1://raise leg
		if (theta[9] < 180.0)
		{
			theta[9] += STEP;
			theta[10] -= STEP;
		}
		else animation = option;

		glPushMatrix();

		glLoadIdentity();
		glTranslatef(TORSO_RADIUS / 2, 0.1 * UPPER_LEG_HEIGHT, 0.0);
		glRotatef(theta[9], 1.0, 0.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, rul_node.m);

		glLoadIdentity();
		glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, rknee_node.m);

		glLoadIdentity();
		glTranslatef(0.0, KNEE_RADIUS / 2, 0.0);
		glRotatef(theta[10], 1.0, 0.0, 0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, rll_node.m);

		glPopMatrix();
		break;



	case 7: case -2: //Jump animaiton to be continus
		if (horizontal < 1.4)
		{
			horizontal += 0.03 * STEP;
			cout << horizontal << endl;
			theta[9] += STEP;
			theta[10] -= STEP;
			theta[7] += STEP;
			theta[8] -= STEP;

			if (theta[9] > 180.0)
			{
				theta[9] = 180;
				theta[10] = 0;
				theta[7] = 180;
				theta[8] = 0;
			}

		}
		else animation = option;

		if (theta[9] < 180)
		{

			glPushMatrix();


			glLoadIdentity();
			glTranslatef(TORSO_RADIUS / 2, 0.1 * UPPER_LEG_HEIGHT, 0.0);
			glRotatef(theta[9], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, rul_node.m);

			glLoadIdentity();
			glTranslatef(0.0, KNEE_RADIUS / 2, 0.0);
			glRotatef(theta[10], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, rll_node.m);

			glLoadIdentity();
			glTranslatef(-TORSO_RADIUS / 2, 0.1 * UPPER_LEG_HEIGHT, 0.0);
			glRotatef(theta[7], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, lul_node.m);

			glLoadIdentity();
			glTranslatef(0.0, KNEE_RADIUS / 2, 0.0);
			glRotatef(theta[8], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, lll_node.m);

			glLoadIdentity();
			glTranslatef(0, horizontal, 0);
			glGetFloatv(GL_MODELVIEW_MATRIX, torso_node.m);

			glPopMatrix();
		}
		else
		{

			glPushMatrix();
			glLoadIdentity();
			glTranslatef(0, horizontal, 0);
			glGetFloatv(GL_MODELVIEW_MATRIX, torso_node.m);

			glPopMatrix();
		}


		break;

	default: animation = option;
	}
}

void idle()
{
	switch (option)
	{
	case 0:
		if (animation != option) inverseKinematics();
		else if (!done)
		{
			if (theta[5] > 30.0)
			{
				theta[5] -= STEP;
				theta[3] -= STEP;
				theta[1] += 0.2 * STEP;
			}
			else done = 1;

			glPushMatrix();

			glLoadIdentity();
			glTranslatef(0, 0, 0.0);
			glRotatef(theta[5], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, rua_node.m);

			glLoadIdentity();
			glTranslatef(0, 0, 0.0);
			glRotatef(theta[3], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, lua_node.m);

			glLoadIdentity();
			glTranslatef(0.0, TORSO_HEIGHT - 0.25 * NECK_HEIGHT, 0.0);
			glRotatef(theta[1], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, nk_node.m);

			glPopMatrix();
		}
		break;
	case 1:
		if (animation != option) inverseKinematics();
		else if (!done)
		{
			if (theta[9] > 110.0)
			{
				theta[9] -= STEP;
				theta[10] += STEP;
			}
			else done = 1;

			glPushMatrix();

			glLoadIdentity();
			glTranslatef(TORSO_RADIUS / 2, 0.1 * UPPER_LEG_HEIGHT, 0.0);
			glRotatef(theta[9], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, rul_node.m);

			glLoadIdentity();
			glTranslatef(0.0, KNEE_RADIUS / 2, 0.0);
			glRotatef(theta[10], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, rll_node.m);

			glLoadIdentity();
			glTranslatef(0, -horizontal, -horizontal);
			glGetFloatv(GL_MODELVIEW_MATRIX, torso_node.m);

			glPopMatrix();
		}
		break;
	case 2:
		inverseKinematics();
		break;

	case 6:
		if (animation != option) inverseKinematics();
		else
		{
			if (theta[9] > 130.0)
			{
				theta[9] -= STEP;
				theta[10] += STEP;
				theta[7] -= STEP;
				theta[8] += STEP;
				theta[5] += STEP;
				theta[6] -= STEP;
				theta[3] -= STEP;
				theta[4] += STEP;
				horizontal += 0.03 * STEP;
			}
			else animation = -1;//this just sets up the reset value

			glPushMatrix();

			glLoadIdentity();
			glTranslatef(0, 0, 0.0);
			glRotatef(theta[5], 0.0, 0.0, 1.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, rua_node.m);

			glLoadIdentity();
			glTranslatef(0, 0, 0.0);
			glRotatef(theta[6], 0.0, 0.0, 1.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, rla_node.m);

			glLoadIdentity();
			glTranslatef(0, 0, 0.0);
			glRotatef(theta[3], 0.0, 0.0, 1.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, lua_node.m);

			glLoadIdentity();
			glTranslatef(0, 0, 0.0);
			glRotatef(theta[4], 0.0, 0.0, 1.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, lla_node.m);

			glLoadIdentity();
			glTranslatef(TORSO_RADIUS / 2, 0.1 * UPPER_LEG_HEIGHT, 0.0);
			glRotatef(theta[9], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, rul_node.m);

			glLoadIdentity();
			glTranslatef(0.0, KNEE_RADIUS / 2, 0.0);
			glRotatef(theta[10], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, rll_node.m);

			glLoadIdentity();
			glTranslatef(-TORSO_RADIUS / 2, 0.1 * UPPER_LEG_HEIGHT, 0.0);
			glRotatef(theta[7], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, lul_node.m);

			glLoadIdentity();
			glTranslatef(0.0, KNEE_RADIUS / 2, 0.0);
			glRotatef(theta[8], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, lll_node.m);

			glLoadIdentity();
			glTranslatef(0, -horizontal, -horizontal);
			glGetFloatv(GL_MODELVIEW_MATRIX, torso_node.m);

			glPopMatrix();
		}
		break;
	case 7: //goes down
		if (animation != option) inverseKinematics();
		else
		{
			if (theta[9] > 130.0)
			{
				horizontal -= 0.03 * STEP;
				theta[9] -= STEP;
				theta[10] += STEP;
				theta[7] -= STEP;
				theta[8] += STEP;
			}
			else animation = -2;

			glPushMatrix();


			glLoadIdentity();
			glTranslatef(TORSO_RADIUS / 2, 0.1 * UPPER_LEG_HEIGHT, 0.0);
			glRotatef(theta[9], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, rul_node.m);

			glLoadIdentity();
			glTranslatef(0.0, KNEE_RADIUS / 2, 0.0);
			glRotatef(theta[10], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, rll_node.m);

			glLoadIdentity();
			glTranslatef(-TORSO_RADIUS / 2, 0.1 * UPPER_LEG_HEIGHT, 0.0);
			glRotatef(theta[7], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, lul_node.m);

			glLoadIdentity();
			glTranslatef(0.0, KNEE_RADIUS / 2, 0.0);
			glRotatef(theta[8], 1.0, 0.0, 0.0);
			glGetFloatv(GL_MODELVIEW_MATRIX, lll_node.m);

			glLoadIdentity();
			glTranslatef(0, horizontal, 0);
			glGetFloatv(GL_MODELVIEW_MATRIX, torso_node.m);

			glPopMatrix();

		}
		break;
	}


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




void menu(int id)
{
	option = id;
	done = 0;

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

//Containts the actuall building up
void myinit()
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess = { 100.0 };
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 10.0, 10.0, 10.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	glEnable(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);

	/* allocate quadrics with filled drawing style */

	h = gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	t = gluNewQuadric();
	gluQuadricDrawStyle(t, GLU_FILL);
	lua = gluNewQuadric();
	gluQuadricDrawStyle(lua, GLU_FILL);
	///////////////////////////////
	lelb = gluNewQuadric();
	gluQuadricDrawStyle(lelb, GLU_FILL);
	lla = gluNewQuadric();
	gluQuadricDrawStyle(lla, GLU_FILL);
	rua = gluNewQuadric();
	gluQuadricDrawStyle(rua, GLU_FILL);
	rla = gluNewQuadric();
	gluQuadricDrawStyle(rla, GLU_FILL);
	lul = gluNewQuadric();
	gluQuadricDrawStyle(lul, GLU_FILL);
	lll = gluNewQuadric();
	gluQuadricDrawStyle(lll, GLU_FILL);
	rul = gluNewQuadric();
	gluQuadricDrawStyle(rul, GLU_FILL);
	rll = gluNewQuadric();
	gluQuadricDrawStyle(rll, GLU_FILL);
	rknee = gluNewQuadric();
	gluQuadricDrawStyle(rknee, GLU_FILL);
	lknee = gluNewQuadric();
	gluQuadricDrawStyle(lknee, GLU_FILL);
	relb = gluNewQuadric();
	gluQuadricDrawStyle(relb, GLU_FILL);
	nk = gluNewQuadric();
	gluQuadricDrawStyle(nk, GLU_FILL);
	rhand = gluNewQuadric();
	gluQuadricDrawStyle(rhand, GLU_FILL);
	lhand = gluNewQuadric();
	gluQuadricDrawStyle(lhand, GLU_FILL);
	lfoot = gluNewQuadric();
	gluQuadricDrawStyle(lfoot, GLU_FILL);
	rfoot = gluNewQuadric();
	gluQuadricDrawStyle(rfoot, GLU_FILL);
	rsh = gluNewQuadric();
	gluQuadricDrawStyle(rsh, GLU_FILL);
	lsh = gluNewQuadric();
	gluQuadricDrawStyle(lsh, GLU_FILL);

	/* Set up tree */

	glLoadIdentity();
	glRotatef(theta[0], 0.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, torso_node.m);
	torso_node.f = torso;
	torso_node.sibling = zzero;
	torso_node.child = &nk_node;

	glLoadIdentity();
	glTranslatef(0.0, TORSO_HEIGHT - 0.25 * NECK_HEIGHT, 0.0);
	glRotatef(theta[1], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, nk_node.m);
	nk_node.f = neck;
	nk_node.sibling = &lsh_node;
	nk_node.child = &head_node;

	glLoadIdentity();
	glTranslatef(-(TORSO_RADIUS + UPPER_ARM_RADIUS), 0.9 * TORSO_HEIGHT, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, lsh_node.m);
	lsh_node.f = leftShoulder;
	lsh_node.sibling = &rsh_node;
	lsh_node.child = &lua_node;

	glLoadIdentity();
	glTranslatef(TORSO_RADIUS + UPPER_ARM_RADIUS, 0.9 * TORSO_HEIGHT, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, rsh_node.m);
	rsh_node.f = rightShoulder;
	rsh_node.sibling = &lul_node;
	rsh_node.child = &rua_node;

	glLoadIdentity();
	glTranslatef(0.0, 0.75 * NECK_HEIGHT, 0.0);
	glRotatef(theta[2], 0.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, head_node.m);
	head_node.f = head;
	head_node.sibling = zzero;
	head_node.child = zzero;

	glLoadIdentity();
	glTranslatef(0, 0, 0.0);
	glRotatef(theta[3], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, lua_node.m);
	lua_node.f = left_upper_arm;
	lua_node.sibling = zzero;
	lua_node.child = &lelb_node;

	glLoadIdentity();
	glTranslatef(0.0, UPPER_ARM_HEIGHT, 0.0);
	glRotatef(theta[4], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, lelb_node.m);
	lelb_node.f = leftElbow;
	lelb_node.sibling = zzero;
	lelb_node.child = &lla_node;

	glLoadIdentity();
	glTranslatef(0, 0, 0.0);
	glRotatef(theta[5], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, rua_node.m);
	rua_node.f = right_upper_arm;
	rua_node.sibling = zzero;
	rua_node.child = &relb_node;

	glLoadIdentity();
	glTranslatef(0.0, UPPER_ARM_HEIGHT, 0.0);
	glRotatef(theta[4], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, relb_node.m);
	relb_node.f = rightElbow;
	relb_node.sibling = zzero;
	relb_node.child = &rla_node;

	glLoadIdentity();
	glTranslatef(-TORSO_RADIUS / 2, 0.1 * UPPER_LEG_HEIGHT, 0.0);
	glRotatef(theta[7], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, lul_node.m);
	lul_node.f = left_upper_leg;
	lul_node.sibling = &rul_node;
	lul_node.child = &lknee_node;

	glLoadIdentity();
	glTranslatef(TORSO_RADIUS / 2, 0.1 * UPPER_LEG_HEIGHT, 0.0);
	glRotatef(theta[9], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, rul_node.m);
	rul_node.f = right_upper_leg;
	rul_node.sibling = zzero;
	rul_node.child = &rknee_node;

	glLoadIdentity();
	glTranslatef(0.0, ELBOW_RADIUS / 2, 0.0);
	glRotatef(theta[4], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, lla_node.m);
	lla_node.f = left_lower_arm;
	lla_node.sibling = zzero;
	lla_node.child = &lhand_node;

	glLoadIdentity();
	glTranslatef(0.0, ELBOW_RADIUS / 2, 0.0);
	glRotatef(theta[4], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, rla_node.m);
	rla_node.f = right_lower_arm;
	rla_node.sibling = zzero;
	rla_node.child = &rhand_node;

	glLoadIdentity();
	glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, rhand_node.m);
	rhand_node.f = rightHand;
	rhand_node.sibling = zzero;
	rhand_node.child = zzero;

	glLoadIdentity();
	glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, lhand_node.m);
	lhand_node.f = leftHand;
	lhand_node.sibling = zzero;
	lhand_node.child = zzero;

	glLoadIdentity();
	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
	glRotatef(theta[10], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, lknee_node.m);
	lknee_node.f = leftKnee;
	lknee_node.sibling = zzero;
	lknee_node.child = &lll_node;

	glLoadIdentity();
	glTranslatef(0.0, KNEE_RADIUS / 2, 0.0);
	glRotatef(theta[8], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, lll_node.m);
	lll_node.f = left_lower_leg;
	lll_node.sibling = zzero;
	lll_node.child = &lfoot_node;

	glLoadIdentity();
	glTranslatef(0.0, LOWER_LEG_HEIGHT, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, lfoot_node.m);
	lfoot_node.f = leftFoot;
	lfoot_node.sibling = zzero;
	lfoot_node.child = zzero;

	glLoadIdentity();
	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
	glRotatef(theta[10], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, rknee_node.m);
	rknee_node.f = rightKnee;
	rknee_node.sibling = zzero;
	rknee_node.child = &rll_node;

	glLoadIdentity();
	glTranslatef(0.0, KNEE_RADIUS / 2, 0.0);
	glRotatef(theta[10], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, rll_node.m);
	rll_node.f = right_lower_leg;
	rll_node.sibling = zzero;
	rll_node.child = &rfoot_node;

	glLoadIdentity();
	glTranslatef(0.0, LOWER_LEG_HEIGHT, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, rfoot_node.m);
	rfoot_node.f = rightFoot;
	rfoot_node.sibling = zzero;
	rfoot_node.child = zzero;

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
		posX -= incrtrans * 0.2f;
		break;
	case 'd':
		posX += incrtrans * 0.2f;
		break;
	default:
		break;
	}
	glutPostRedisplay(); // Request a redraw
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Dancing Robot");
	myinit();
	glutReshapeFunc(myReshape);
	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutKeyboardFunc(kbFunc); 
	glutCreateMenu(menu);
	glutAddMenuEntry(" Raise Hands ", 0);
	glutAddMenuEntry(" Raise Leg ", 1);
	glutAddMenuEntry(" JUMP! ", 7);
	glutAddMenuEntry(" Reset ", 2);


	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return 0;
}