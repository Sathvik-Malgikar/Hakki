#include <GL/glut.h>
#include <GL/GL.h>
#include <cmath>
#include <iostream>

using namespace std;

float angle = 0;
float frag = 0.01;

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

    


    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    cout << 5 * cos(angle) << endl;
    gluLookAt(10 * sin(angle), 10 * cos(angle),0 , 0.0, 0.0, 0.0, 0, 0, 1);


    glPushMatrix();
        glColor3f(0.957, 0.643, 0.376);
        setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
        //glTranslatef(0, 0, 0);
        //glRotatef(angle, 1, 0, 0);
        glutSolidTeapot(2);
    glPopMatrix();

    /*
    
    glPushMatrix();
    glColor3f(0.957, 0.643, 0.376);
    setMaterial(0.0, 0.5, 1.0, 0.0, 0.5, 1.0, 1.0, 1.0, 1.0, 50);
    glTranslatef(-2, 0, 0);
    glRotatef(-angle, 1, 0, 0);
    glutSolidTeapot(2);
    glPopMatrix();
    */

  

    /* flush drawing routines to the window */
    glFlush();
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

   angle = angle + frag;
   if (angle >= 2) {
       frag = -0.01;
   }
   
   if (angle <= 0) {
       frag = 0.01;
   }

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
   
    //cout << 10 * cos(angle) << endl;
    gluLookAt(0 ,10  ,   0, 0.0, 0.0, 0.0, 0, 0, 1);

    //register the IdleFunction
    glutIdleFunc(animate);

    /* tell GLUT to wait for events */
    glutMainLoop();
}