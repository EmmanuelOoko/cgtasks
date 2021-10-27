#include<GL/freeglut.h>
#include <math.h>


void Gl_LINE_LOOP(){

    glBegin(GL_LINE_LOOP);

    glVertex2d(2, 2);
    glVertex2d(-2, 2);
    glVertex2d(-3, 0);
    glVertex2d(0, -5);
    glVertex2d(3, 0);

    glEnd();
    glFlush();
}
void drawCircle(float cx, float cy, float r, int num_segments) {

    const float PI = 3.14159;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)  {

        float theta = i * (2.0f * PI / num_segments);
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT);

//     drawCircle(0.0, 0.0, 0.5, 36);
    Gl_LINE_LOOP();

    glEnd();
    glFlush();
}

//

void init(void) {

    // Define world coordinate frame
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); // model in real word units
    // (left, right, bottom, top, near, far)
}

int main(int argc, char** argv) {
    //Step#1 Create and initialize glut windowing system
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Simple Diamond");
    //Step#2 Do Open GL related initializations
    init();
    //Step#3 Register Call back methods or Event Handler methods

    glutDisplayFunc(display);
    //Step#4 Enter in  main loop (an infinite loop listening to registered events and then call their registered methods if any)
    glutMainLoop();
    return 0;
}