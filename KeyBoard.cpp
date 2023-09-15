#include <GL/glut.h>

#include <iostream>

using namespace std;

float angle = 0;

float xOffset = 0;
float yOffset = 0;
float zoom = 0;

float incr = 0.1f;


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

void display() {
    int a = rand();
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);

    cout << xOffset << yOffset<<"\n";

    glPushMatrix();
    glColor3f(0.957, 0.643, 0.376);
    setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
    glTranslatef(2+xOffset, zoom, yOffset);
    glRotatef(angle, 1, 0, 0);
    glutSolidTeapot(1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.957, 0.643, 0.376);
    setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
    glTranslatef(-2+xOffset, zoom, yOffset);
    glRotatef(-angle, 1, 0, 0);
    glutSolidTeapot(1);
    glPopMatrix();


    /* flush drawing routines to the window */
    glFlush();
}

void arrow(int key, int x, int y) {

    switch (key) {

    case GLUT_KEY_DOWN:
        zoom -= incr;
        break;
    case GLUT_KEY_UP:
        zoom += incr;
        break;

    }
}

void keyboard(unsigned char key, int x, int y) {

    switch (key) {

    case 'a':
    case 'A':
        xOffset += incr;
        break;
    case 'D':
    case 'd':
        xOffset -= incr;
        break;
    case 's':
    case 'S':
        yOffset -= incr;
        break;
    case 'w':
    case 'W':
        yOffset += incr;
        break;

    }
    glutPostRedisplay();
}

void reshape(int width, int height) {

    /* define the viewport transformation */
    glViewport(0, 0, width, height);
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

void animate()
{
    angle = angle + 0.1;
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {

    /* initialize GLUT, using any commandline parameters passed to the
       program */
    glutInit(&argc, argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

    /* create and set up a window */
    glutCreateWindow("my first openGL");
    glutDisplayFunc(display);

    /* set up depth-buffering */
    glEnable(GL_DEPTH_TEST);

    initLight();

    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 4, 100);

    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

    //register the IdleFunction
    glutIdleFunc(animate);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrow);

    /* tell GLUT to wait for events */
    glutMainLoop();
}