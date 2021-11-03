#include<GL/freeglut.h>
#include <math.h>


void init(void) {
    //Defining world coordinate frame
    glMatrixMode(GL_PROJECTION); //which matrix is for the what?
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); // model in real word units
    // (left, right, bottom, top, near, far)
}
void drawWindowBar(float x, float y, int side) {
	glColor3f(0.0, 0.0, 1.0);//Window Colour
	glBegin(GL_LINE);
	glVertex2f(x + side / 2.0, y);//vertices
	glVertex2f(x + side / 2.0, y - side);
	glVertex2f(x, y - side / 2.0);//vertices
	glVertex2f(x + side, y - side / 2.0);

	glEnd();
	glFlush();//ending command
}
void drawWindow(float x, float y, int side) {
	glColor3f(0.0, 1.0, 0.0);//Window Colour
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);//vertices
	glVertex2f(x+side, y);
	glVertex2f(x, y-side);//vertices
	glVertex2f(x + side, y-side);
	
	glEnd();
	glFlush();//ending command
	drawWindowBar(x, y, side);
}
void drawDoor1(float x, float y, int width, int height) {
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + width, y);

	glVertex2f(x, y - height);
	glVertex2f(x + width, y - height);

	glEnd();
	glFlush();
}

void drawHouseOutline() {

    glBegin(GL_LINE_LOOP); //command to begin

    //Hey I'm starting from TOP, pls look at the logic, ignore the comments -^
    //It worked, never touched it again, time 5:02am.

    glVertex2d(6, 3); // top right vertex
    glVertex2d(-6, 3);

    glVertex2d(-6, 0);
    glVertex2d(-5, 0);

    glVertex2d(-5, -8);
    glVertex2d(5, -8);

    glVertex2d(5, 0);
    glVertex2d(6, 0);

    glEnd(); //Ending a command
    glFlush(); // Forces execution before the gathering is complete. Execute the command in finite time?
}

const int  HW=10;
const int HY_TOP = 3;

void drawHalfCircle()  // the empty one
{

    float radius = 0.4*HW;
    float PI = 3.14;
    float twoPI = 2 * PI;
    glBegin(GL_LINE_STRIP);
    
    for (float i = 0.0; i <= twoPI / 2; i += 0.001)
        glVertex2f((cos(i) * radius), (sin(i) * radius)+HY_TOP);
    glEnd();
    glFlush();
}
void display(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    drawHouseOutline();
    drawHalfCircle();
       
}
int main(int argc, char** argv)

{
    glutInit(&argc, argv);  //initialize glut
    glutInitWindowSize(700, 700); //width and height
    glutInitWindowPosition(0, 50); //bottom-left corner
    glutCreateWindow("half circle");
    glutDisplayFunc(display);
    init();
    glutMainLoop(); //loops itself again and again
    return 0;
}
