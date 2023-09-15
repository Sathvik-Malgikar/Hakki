#include <GL/glut.h>
#include <math.h>

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



double camX = 0, camY = 0, camZ  = 5.0f;
//float leftWing = 0;
//float wheelSpeed = 0.01;
//float wheelRotationAngle = 0.0;


void keyHandle(unsigned char key, int x, int y) {
    switch (key) {
        //case 'w':
        //    posY += incr*0.2f;
        //    break;
        //case 's':
        //    posY -= incr * 0.2f;
        //    break;
   case ' ':
       flying = ! flying;
       //posY += incr * 0.2f;
        break;
    case 'a':
        posX -= incrtrans * 0.2f;
        break;
    case 'd':
        posX += incrtrans * 0.2f;
        break;
    }
    glutPostRedisplay();

}
    
 

void animate() {
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
float xdiff = 0.0f;
float ydiff = 0.0f;

void sphereMouseEvent(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
    }
    else
        mouseDown = false;

    if (mouseDown)
    {
        xdiff = (yrot + x);
        ydiff = -y + xrot;
    }

    if (mouseDown)
    {
        //mouseDown = true;
        xdiff = (yrot + x);
        ydiff = -y + xrot;
    }
}


void sphereMouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = -(x + xdiff);
        xrot = (y + ydiff);
        if (xrot > 89) xrot = 89.0f;
        if (xrot < -89) xrot = -89.0f;

        //printf("(xrot, ytor)=(%f, %f)\n", xrot, yrot);
        camX = valZoom * (cos(xrot * PI / 180) * sin(yrot * PI / 180));
        camY = valZoom * (sin(xrot * PI / 180));
        camZ = valZoom * (cos(xrot * PI / 180) * cos(yrot * PI / 180));
        // printf("%d\n", valZoom);
    }
    glutPostRedisplay();

}

void drawSphere(GLfloat x, GLfloat y ) {
    glPushMatrix();


    glutSolidSphere(0.1, 30, 30);

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glLoadIdentity();
  /*  gluLookAt(
        camX, camY, camZ,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    );
    */
    glTranslatef(posX, posY , 0);
    glRotatef(75, 0, 1, 0);

  


  
    glColor3f(1, 0.84, 0.75);

    drawSphere(0, 0);
 
    glBegin(GL_QUADS);
   /* glVertex2f(-0.1, 0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.1);
    glVertex2f(-0.1, -0.1);*/

    glColor3f(0, 0, 0);

    glVertex2f(-0.1/2, 0.1/2);
    glVertex2f(-0.1 / 2 + 0.01, 0.1/2);
    glVertex2f(-0.1 / 2 + 0.01, 0.1 / 2-0.01);
    glVertex2f(-0.1/2, 0.1 / 2 - 0.01);

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


    glTranslatef(0.0f + xOffset , -0.1f, 0.0f);
    //glRotatef(leftWing, -1.0f, 0.0f, 0.0f);
    glScalef(1.0f, 0.2f, 0.2f);  // Ellipse shape
    glutSolidSphere(0.2, 16, 16);
    glPopMatrix();


    glPopMatrix();

    glFlush();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Haro Hakki");
    glClearColor(0.529, 0.808, 0.922, 1);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutKeyboardFunc(keyHandle);
    glutMouseFunc(sphereMouseEvent);
    glutMotionFunc(sphereMouseMotion);
    glutMainLoop();

    return 0;
}