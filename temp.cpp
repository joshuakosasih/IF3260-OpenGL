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
    for (int i = anglestart;i < anglestop ;i++) {
        float degInRad = i*3.14159/180;
        glColor3f(1, 1, 1);
        glVertex2f(cos(degInRad)*r + x, sin(degInRad)*r + y);
    }
}

void InverseCircle(float x, float y, float r, int anglestart, int anglestop) {
    for (int i = anglestart-1;i >= anglestop ;i--) {
        float degInRad = i*3.14159/180;
        glColor3f(1, 1, 1);
        glVertex2f(cos(degInRad)*r + x, sin(degInRad)*r + y);
    }
}

void drawDragonTail() {
    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-0.18, -0.22);
        glVertex2f(0, -0.7);
    glEnd();
    glBegin(GL_LINE_STRIP);
        circle(-0.18, -0.7, 0.18, 90, 360);
    glEnd();
    glBegin(GL_LINE_STRIP);
        circle(-0.14, -0.7, 0.25, 180, 360);
    glEnd();
    glBegin(GL_LINE_STRIP);
        circle(-0.19, -0.71, 0.2, 90, 180);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.11, -0.7);
        glVertex2f(0.05, -0.22);
    glEnd();
}

void drawDragonHead() {
    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(0.2, 0.5);
        glVertex2f(0.15, 0.47);

        glVertex2f(0.15, 0.47);
        glVertex2f(0.05, 0.55);

        glVertex2f(0.05, 0.55);
        glVertex2f(0.05, 0.57);

        glVertex2f(0.2, 0.5);
        glVertex2f(0.1, 0.7);

        glVertex2f(0.1, 0.7);
        glVertex2f(0.05, 0.7);

        //Right Ear
        glVertex2f(0.05, 0.7);
        glVertex2f(0.1, 0.75);

        glVertex2f(0.1, 0.75);
        glVertex2f(0.07, 0.9);

        glVertex2f(0.07, 0.9);
        glVertex2f(0.08, 0.77);

        glVertex2f(0.08, 0.77);
        glVertex2f(0.04, 0.7);

        glVertex2f(0.04, 0.7);
        glVertex2f(0.01, 0.7);

        //Left Ear
        glVertex2f(0.01, 0.7);
        glVertex2f(0.04, 0.75);

        glVertex2f(0.04, 0.75);
        glVertex2f(0.02, 0.9);

        glVertex2f(0.02, 0.9);
        glVertex2f(0.018, 0.75);

        glVertex2f(0.018, 0.75);
        glVertex2f(0, 0.7);
    glEnd();

    //Outer neck
    glBegin(GL_LINE_STRIP);
    circle(0.05, 0.455, 0.25, 90, 200);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.02, 0.47, 0.1, 70, 250);
    glEnd();
}

void drawRightWing() {
    /*glBegin(GL_LINE_STRIP);
    circle(-0.18,0.65,0.28, 140, 270);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.39,0.055,0.78, 90, 180);
    glEnd();*/

    glBegin(GL_LINE_STRIP);
    circle(-0.06,0.65,0.28, 140, 245);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.22,0.055,0.78, 93, 178);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.95,0.055,0.1, 40, 180);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-0.872, 0.12);
        glVertex2f(-0.78, -0.2);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.68,-0.2,0.1, 40, 180);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-0.60, -0.135);
        glVertex2f(-0.38, -0.4);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.42,0.2,1, 190, 215);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.54,-0.176,0.2, 30, 100);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.262,-0.074,0.1, 20, 180);
    glEnd();

    /*glBegin(GL_LINE_STRIP);
    circle(-0.234,-0.070,0.058, 0, 160);
    glEnd();*/
}

void drawLeftWing() {
    glBegin(GL_LINE_STRIP);
    circle(0.0,0.65,0.28, -90, 42);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.20,0.055,0.78, 0, 91);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.89,0.055,0.1, 20, 140);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(0.812, 0.12);
        glVertex2f(0.72, -0.2);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.62,-0.2,0.1, 0, 140);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(0.54, -0.135);
        glVertex2f(0.32, -0.4);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.48,0.2,1, 325, 351);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.48,-0.176,0.2, 80, 150);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.202,-0.074,0.1, 0, 161);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.054,-0.070,0.058, 20, 160);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawDragonHead();
    drawDragonTail();
    drawRightWing();
    drawLeftWing();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(150, 0, w/(1.5), h);
}

void initOpenGL() {
    // color --- r    g    b    alpha
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char **argv) {

    //start up freeglut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("Second OpenGL App");

    initOpenGL();

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
