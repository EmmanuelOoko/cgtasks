#include<GL/freeglut.h>


void Gl_LINE_LOOP(){

    glBegin(GL_LINE_LOOP); //command to begin

    //Hey I'm starting from TOP, pls look at the logic, ignore the comments -^
    //It worked, never touched it again, time 5:02am.

    glVertex2d(5, 3); // top right vertex
    glVertex2d(-5, 3);

    glVertex2d(-5, 0);

    glVertex2d(-3, 0);
    glVertex2d(-3, -8); //lower left y

    glVertex2d(3, -8); //lower right y
    glVertex2d(3, 0);

    glVertex2d(5, 0);

    glEnd(); //Ending a command
    glFlush(); // Forces execution before the gathering is complete. Execute the command in finite time?
}

void display(void) {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Background color
    glClear(GL_COLOR_BUFFER_BIT); //Clearing the colors on the back buffer.
    glColor3f(0.0f, 0.0f, 1.0f); //The color of the 2 outer stacked rectangles

    Gl_LINE_LOOP();
    glEnd();
    glFlush();
}
void init(void) {

    //Defining world coordinate frame
    glMatrixMode(GL_PROJECTION); //which matrix is for the what?
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); // model in real word units
    // (left, right, bottom, top, near, far)
}

int main(int argc, char** argv) {
    //Creating and initializing glut windowing system
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Stacked Rectangle...");

    //Opening initializations
    init();

    //Registering Call back methods
    glutDisplayFunc(display);

    //Entering the main loop
    glutMainLoop();
    return 0;
}