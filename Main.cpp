#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;


void initGL() {

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);//clears one or more buffers per time....clears colors on back buffer

	glBegin(GL_POLYGON);//POLYGON for boundary of a ploygon
	//glColor3f(1.0f, 1.0f, 1.0f);
	

	//Window
	glVertex2f(-0.5f, 0.1f);//vertices
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(-0.5f, -0.1f);
	glVertex2f(-0.4f, -0.1f);
	glVertex2f(-0.3f, -0.1f);
	glVertex2f(-0.3f, 0.0f);
	glVertex2f(-0.3f, 0.1f);
	glVertex2f(-0.4f, 0.1f);
	//glTranslatef(2.0, 3.0, 0.0);
   //glRotatef(30, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);//Window Colour
	glEnd();
	glFlush();//ending command
	

	//Window Pane
	glBegin(GL_POLYGON);//POLYGON for boundary of a ploygon
	glVertex2f(-0.5f, 0.1f);//vertices
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(-0.4f, 0.0f);
	glVertex2f(-0.4f, 0.1f);
	//glTranslatef(2.0, 3.0, 0.0);
    //glRotatef(30, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 1.0f);//Window Colour
	glEnd();
	glFlush();//ending command

	//Window Pane
	glBegin(GL_POLYGON);//POLYGON for boundary of a ploygon
	glVertex2f(-0.5f, 0.0f);//vertices
	glVertex2f(-0.5f, -0.1f);
	glVertex2f(-0.4f, -0.1f);
	glVertex2f(-0.4f, 0.0f);
	//glTranslatef(2.0, 3.0, 0.0);
	//glRotatef(30, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.647, 0.0);//Window Colour
	glEnd();
	glFlush();//ending command

	//Window Pane
	glBegin(GL_POLYGON);//POLYGON for boundary of a ploygon
	glVertex2f(-0.4f, 0.0f);//vertices
	glVertex2f(-0.4f, -0.1f);
	glVertex2f(-0.3f, -0.1f);
	glVertex2f(-0.3f, 0.0f);
	//glTranslatef(2.0, 3.0, 0.0);
	//glRotatef(30, 0.0, 0.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);//Window Colour
	glEnd();
	glFlush();//ending command

	//Window Pane
	glBegin(GL_POLYGON);//POLYGON for boundary of a ploygon
	glVertex2f(-0.4f, 0.0f);//vertices
	glVertex2f(-0.4f, 0.1f);
	glVertex2f(-0.3f, 0.1f);
	glVertex2f(-0.3f, 0.0f);
	//glTranslatef(2.0, 3.0, 0.0);
	//glRotatef(30, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 0.647f, 0.0f);//Window Colour
	glEnd();
	glFlush();//ending command






	//Window
	glBegin(GL_POLYGON);//POLYGON for boundary of a ploygon
	//glColor3f(1.0f, 0.0f, 0.0f)

	glVertex2f(0.5f, 0.1f);//vertices
	glVertex2f(0.5f, 0.0f);
	glVertex2f(0.5f, -0.1f);
	glVertex2f(0.4f, -0.1f);
	glVertex2f(0.3f, -0.1f);
	glVertex2f(0.3f, 0.0f);
	glVertex2f(0.3f, 0.1f);
	glVertex2f(0.4f, 0.1f);
	glColor3f(0.0, 1.0, 0.0);//Window Colour
	glEnd();//ending command
	glFlush();//execution before is complete


	//Window Pane
	glBegin(GL_POLYGON);//POLYGON for boundary of a ploygon
	glVertex2f(0.5f, 0.1f);//vertices
	glVertex2f(0.5f, 0.0f);
	glVertex2f(0.4f, 0.0f);
	glVertex2f(0.4f, 0.1f);
	//glTranslatef(2.0, 3.0, 0.0);
	//glRotatef(30, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.8, 0.0);//Window Colour
	glEnd();
	glFlush();//ending command

	//Window Pane
	glBegin(GL_POLYGON);//POLYGON for boundary of a ploygon
	glVertex2f(0.5f, 0.0f);//vertices
	glVertex2f(0.5f, -0.1f);
	glVertex2f(0.4f, -0.1f);
	glVertex2f(0.4f, 0.0f);
	//glTranslatef(2.0, 3.0, 0.0);
	//glRotatef(30, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);//Window Colour
	glEnd();
	glFlush();//ending command

	//Window Pane
	glBegin(GL_POLYGON);//POLYGON for boundary of a ploygon
	glVertex2f(0.4f, 0.0f);//vertices
	glVertex2f(0.4f, -0.1f);
	glVertex2f(0.3f, -0.1f);
	glVertex2f(0.3f, 0.0f);
	//glTranslatef(2.0, 3.0, 0.0);
	//glRotatef(30, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);//Window Colour
	glEnd();
	glFlush();//ending command

	//Window Pane
	glBegin(GL_POLYGON);//POLYGON for boundary of a ploygon
	glVertex2f(0.4f, 0.0f);//vertices
	glVertex2f(0.4f, 0.1f);
	glVertex2f(0.3f, 0.1f);
	glVertex2f(0.3f, 0.0f);
	//glTranslatef(2.0, 3.0, 0.0);
	//glRotatef(30, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.1, 0.0);//Window Colour
	glEnd();
	glFlush();//ending command

	




	//Door
	glBegin(GL_POLYGON);//POLYGON for boundary of a ploygon
	//glColor3f(1.0f, 0.0f, 0.0f)

	glVertex2f(0.1f, 0.1f);//vertices
	glVertex2f(0.0f, 0.1f);
	glVertex2f(-0.1f, 0.1f);
	glVertex2f(-0.1f, -0.3f);
	glVertex2f(0.1f, -0.3f);
	//glColor3f(0.0, 1.0, 0.0);//Door Colour
	glEnd();//ending command
	glFlush();//execution before is complete

	//Knob
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);//Yellow

	glVertex2f(0.07f, -0.1f);
	glVertex2f(0.083f, -0.1f);
	glVertex2f(0.083f, -0.12f);
	glVertex2f(0.07f, -0.12f);
	glEnd();//ending command
	glFlush();//execution before is complete

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Window and Door");
	glutInitWindowSize(10000, 2000);
	glutDisplayFunc(display);
	initGL();
	glutMainLoop();
	return 0;
}

/*void Draw() {
	GLfloat x1 = 500, y1 = 1100, x2 = 600, y2 = 1100;
	glClear(GL_COLOR_BUFFER_BIT);

	if ((x2 - x1) == 0)
		float M = (y2 - y1) / (x2 - x1);
	else
		float M = (y2 - y1) / (x2 - x1);

	float dx = x2 - x1;
	float dy = y2 - y1;

	float p = 2 * dy - dx;

	float x = x1;
	float y = y1;

	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);

	while (x <= x2) {
		glVertex2f(x, y);
		x = x + 1;

		if (p >= 1) {
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else {
			y = y;
			p = p + 2 * dy;
		}
		
	}
	glEnd();
	glFlush();
}
void MyInit() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argC, char *argV[]) {
	glutInit(&argC, argV);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(2000, 2000);
	glutCreateWindow("Windows and Door");
	MyInit();
	glutDisplayFunc(Draw);
	glutMainLoop();
}*/