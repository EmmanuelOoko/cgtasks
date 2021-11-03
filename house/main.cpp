#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <vector>

const int SW = 700;
const int SH = 700;

void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides, bool cover);

const int  HW = 16;
const int HY_TOP = 4;

const int WIN_W = 4; //window width
const int D_H = 9; //door height

void init(void) {
    //Defining world coordinate frame
    glMatrixMode(GL_PROJECTION); //which matrix is for the what?
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); // model in real word units
    // (left, right, bottom, top, near, far)
}
void drawWindowBar(float x, float y, int side) {
    glColor3f(0.0, 0.0, 1.0);//Window Colour
    glBegin(GL_LINES);
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
    glVertex2f(x + side, y);
    
    glVertex2f(x + side, y - side);
    glVertex2f(x, y - side);//vertices

    glEnd();
    glFlush();//ending command

    drawWindowBar(x, y, side);
}

void drawDoor(float x, float y, int width, int height) {
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + width, y);

    
    glVertex2f(x + width, y - height);
    glVertex2f(x, y - height);

    glEnd();
    glFlush();
}

void drawHouseOutline() {

    glBegin(GL_LINE_LOOP); //command to begin

    //Hey I'm starting from TOP, pls look at the logic, ignore the comments -^
    //It worked, never touched it again, time 5:02am.

    glVertex2d(9, 4); // top right vertex
    glVertex2d(-9, 4);

    glVertex2d(-9, 1);
    glVertex2d(-8, 1);

    glVertex2d(-8, -9);
    glVertex2d(8, -9);

    glVertex2d(8, 1);
    glVertex2d(9, 1);

    glEnd(); //Ending a command
    glFlush(); // Forces execution before the gathering is complete. Execute the command in finite time?
}

void drawCircle(bool isNub)  // the empty one
{
    
    float radius = 0.4 * HW;
    float PI = 3.14;
    float twoPI = 2 * PI;
    float loopTill = twoPI / 2;
    if (isNub) {
        radius = 0.01 * HW;
        loopTill = twoPI;
    }
    glBegin(GL_LINE_STRIP);

    for (float i = 0.0; i <= loopTill; i += 0.001)
    {
        if (isNub) {
            glVertex2f((cos(i) * radius) + 1.5, (sin(i) * radius) -5 );
            continue;
        }
        glVertex2f((cos(i) * radius), (sin(i) * radius) + HY_TOP);
    }
        
    glEnd();
    glFlush();
}

void display(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawHouseOutline();
    drawCircle(false);
    drawWindow(-7, 0, WIN_W);
    drawDoor(-2, 0, WIN_W, D_H);
    drawWindow(7 - WIN_W, 0, WIN_W);
    drawCircle(12, 17, 0, 4, 360, false);
    drawCircle(14, 16, 0, 4, 360, true);
    glColor3f(0.0, 0.0, 1.0);
    drawCircle(true);
}

int main(void)
{
    GLFWwindow* window;
    

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(SW, SH, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    gladLoadGL();

    glViewport(0, 0, SW, SH);// specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho(-20, 20, -20, 20, 20, -20);// essentially set coordinate system
    glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity(); // same as above comment
    
    glClearColor(1, 1, 1, 1);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        display();
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides, bool cover = false) {
    int numberOfVertices = numberOfSides + 2;

    GLfloat twoPi = 4.0f * acos(0.0);
    std::vector<GLfloat> verticesX;
    std::vector<GLfloat> verticesY;
    std::vector<GLfloat> verticesZ;

    verticesX.push_back(x);
    verticesY.push_back(y);
    verticesZ.push_back(z);

    for (int i = 1; i < numberOfVertices; i++) {
        verticesX.push_back(x + (radius * cos(i * twoPi / numberOfSides)));
        verticesY.push_back(x + (radius * sin(i * twoPi / numberOfSides)));
        verticesZ.push_back(z);
    }

    std::vector<GLfloat> allCircleVertices;
    std::vector<GLubyte> allVertexColors;

    for (int i = 0; i < numberOfVertices; i++) {
        allCircleVertices.push_back(verticesX[i]);
        allCircleVertices.push_back(verticesY[i]);
        allCircleVertices.push_back(verticesZ[i]);

        if (cover) {
            allVertexColors.push_back(255);
            allVertexColors.push_back(255);
            allVertexColors.push_back(255);
            continue;
        }

        if (i == 0 ) {
            
            allVertexColors.push_back(218);
            allVertexColors.push_back(165);
            allVertexColors.push_back(32);
        }
        else {
            allVertexColors.push_back(255);
            allVertexColors.push_back(255);
            allVertexColors.push_back(0);
        }
    }

    GLfloat* arr = &allCircleVertices[0];
    GLubyte* clrs = &allVertexColors[0];

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_UNSIGNED_BYTE, 0, clrs);
    glVertexPointer(3, GL_FLOAT, 0, arr);
    //glColor3ubv(clrs);
    glColor3ub(255, 255, 0);
    glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}