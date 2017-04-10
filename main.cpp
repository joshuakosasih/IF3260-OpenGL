/*
    My First OpenGL code
    Author: Joshua Aditya Kosasih
*/
#ifdef __APPLE__

#else
#include <GL/glut.h>
#endif // __APPLE__

#include <stdio.h>
#include <cmath>

float counter = 0.0;

void circle(float x, float y, float r, int anglestart, int anglestop) {
    for (int i = anglestart;i < anglestop;i++) {
        float degInRad = i*3.14159/180;
        glColor3f(0.2, 1, 0.2);
        glVertex2f(cos(degInRad)*r + x, sin(degInRad)*r + y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    counter += 0.1;

    if(counter > 180) {
        counter = -180;
    }

    // line
    glLoadIdentity();

    glRotatef(counter, 0.0, 1.0, 0.0); //movement

    glLineWidth(2.5);
    glBegin(GL_LINES);

        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(0.5, 0.8);
        glVertex2f(-0.5, -0.8);
    glEnd();

    // square
    glLoadIdentity();

    glTranslatef(-counter/100, 0.0, 0.0); //movement

    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0, 0.0);
        glColor3f(0.5, 0.0, 0.5);
        glVertex2f(0.5, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.5, 0.5);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(0.0, 0.5);
    glEnd();

    //octagon
    glLoadIdentity();

    glTranslatef(counter/100, counter/200, 0.0); //movement

    glColor3f(0.0, 0.1, 0.5);
    glBegin(GL_POLYGON);
        for (int i = 0;i < 8;i++) {
            float degInRad = i*6.2832/8;
            glColor3f(cos(degInRad)*50, sin(degInRad)*50, 1.0);
            glVertex2f(cos(degInRad)*0.3, sin(degInRad)*0.3);
        }
    glEnd();

    // circle
    glLoadIdentity();

    //glTranslatef(sin(counter)/80, cos(counter)/80, 0.0); //movement

    glColor3f(0.0, 0.5, 0.1);
    /*
        for (int i = 0;i < 360;i++) {
            float degInRad = i*3.14159/180;
            glColor3f(0.2, cos(degInRad), 0.2);
            glVertex2f(cos(degInRad)*0.2, sin(degInRad)*0.2);
        }
    */
    glBegin(GL_POLYGON);
    circle(0, 0, 0.3, 0, 180);
    circle(0, -0.3, 0.3, 180, 360);
    glEnd();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

void initOpenGL() {
    // color --- r    g    b    alpha
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char **argv) {

    //start up freeglut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("Second OpenGL App");

    initOpenGL();

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
