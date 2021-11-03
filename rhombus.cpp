#include <GL/glut.h>


void initGL() {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);//clears one or more buffers per time....clears colors on back buffer
	glBegin(GL_POLYGON);//POLYGON for boundary of a ploygon
	//glColor3f(1.0f, 0.0f, 0.0f)

	//rhombus coordinates
	glVertex2f(0.0f, -0.5f);//vertices
	glVertex2f(1.0f, 0.0f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(-1.0f, 0.0f);
	glColor3f(0.0, 1.0, 0.0);//color of rhombus
	glEnd();//ending command
	glFlush();//execution before is complete
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Rhombus");
	glutInitWindowSize(700 ,700);
	glutDisplayFunc(display);
	initGL();
	glutMainLoop();
	return 0;
}