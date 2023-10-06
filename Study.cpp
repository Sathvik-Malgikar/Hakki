#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<GL/glut.h>

float angle = 0.0f;

float red = 1.0f;
float green = 1.0f;
float blue = 1.0f;

GLfloat x = 0.0f, z = 5.0f; // position
GLfloat lx = 0.0f, lz = -1.0f; // look direction

void changeSize(int w, int h) {
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45, ratio, 1, 10000);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}


void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) exit(0);
}

void displayHEX() {

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);

	glColor3f(1, 00, 00);

	glVertex2f(-0.4, 0);
	glVertex2f(0, 0);
	glVertex2f(-0.3, 0.3);

	glColor3f(00, 1, 0);

	glVertex2f(-0.3, 0.3);
	glVertex2f(0, 0);
	glVertex2f(0, 0.4);

	glColor3f(1, 0, 0);

	glVertex2f(0, 0.4);
	glVertex2f(0, 0);
	glVertex2f(0.3, 0.3);

	glColor3f(00, 1, 0);


	glVertex2f(0.3, 0.3);
	glVertex2f(0, 0);
	glVertex2f(0.4, 0);

	glColor3f(00, 1, 0);


	glVertex2f(0.4, 0);
	glVertex2f(0, 0);
	glVertex2f(0.2, -0.2);

	glColor3f(1, 0, 0);


	glVertex2f(0.2, -0.2);
	glVertex2f(0, 0);
	glVertex2f(0, -0.4);

	glColor3f(00, 1, 0);


	glVertex2f(0, -0.4);
	glVertex2f(0, 0);
	glVertex2f(-0.2, -0.2);


	glEnd();

	glFlush();

}


void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_F1:
		red = 1.0f;
		green = 0.0f;
		blue = 0.0f;
		break;
	case GLUT_KEY_F2:
		red = 0.0f;
		green = 1.0f;
		blue = 0.0f;
		break;
	case GLUT_KEY_F3:
		red = 0.0f;
		green = 0.0f;
		blue = 1.0f;
		break;
	}
}

void DrawCircle() {
	float PI = 3.14159;
	float theta;
	glColor3f(red, green, blue);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++) {
		theta = (i * PI) / 180;
		glVertex2f(0.25 * cos(theta), 0.25 * sin(theta));
	}
	float line_angle = 0;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	for (int i = 0; i <= 14; i++) {
		glVertex2f(0.25f * cos(line_angle), 0.25f * sin(line_angle));
		glVertex2f(-0.25f * cos(line_angle), -0.25f * sin(line_angle));
		std::cout << line_angle << " " << i << " " << i * (180 / 12) << std::endl;
		line_angle = (i * (180 / 12)) * PI / 180;
	}
	glEnd();
	glEnd();


}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(x, 0, 0);
	glRotatef(angle, 0.0, 0.0f, 1.0);
	DrawCircle();
	angle += 1.0f;
	x += 0.005f;

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("First One");

	glutDisplayFunc(displayHEX);
	//glutReshapeFunc(changeSize);

	//glutIdleFunc(renderScene);

	//glutKeyboardFunc(processNormalKeys);
	//glutSpecialFunc(processSpecialKeys);

	glutMainLoop();

	return 1;
}