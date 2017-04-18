/*
    My First OpenGL code
    Author: Joshua Aditya Kosasih
*/
#ifdef __APPLE__

#else
#include <GL/glut.h>
#endif // __APPLE__

#ifndef CALLBACK
#define CALLBACK
#endif

#include <GL/glut.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

using std::stringstream;
using std::cout;
using std::cerr;
using std::endl;
using std::ends;

float counter = 0.0;
float red = 1, green = 1, blue = 1;

// CALLBACK functions for GLU_TESS ////////////////////////////////////////////
// NOTE: must be declared with CALLBACK directive
void CALLBACK tessBeginCB(GLenum which);
void CALLBACK tessEndCB();
void CALLBACK tessErrorCB(GLenum errorCode);
void CALLBACK tessVertexCB(const GLvoid *data);
void CALLBACK tessVertexCB2(const GLvoid *data);
void CALLBACK tessCombineCB(const GLdouble newVertex[3], const GLdouble *neighborVertex[4],
                            const GLfloat neighborWeight[4], GLdouble **outData);

GLdouble quads[640][6];
GLdouble vertices[64][6];
int vertexIndex = 0;

void circle(float x, float y, float r, int anglestart, int anglestop) {
    for (int i = anglestart;i < anglestop ;i++) {
        float degInRad = i*3.14159/180;
        glColor3f(red, green, blue);
        glVertex2f(cos(degInRad)*r + x, sin(degInRad)*r + y);
    }
}

void InverseCircle(float x, float y, float r, int anglestart, int anglestop) {
    for (int i = anglestart-1;i >= anglestop ;i--) {
        float degInRad = i*3.14159/180;
        glColor3f(red, green, blue);
        glVertex2f(cos(degInRad)*r + x, sin(degInRad)*r + y);
    }
}

void QuadCircle(float x, float y, float r, int anglestart, int anglestop, int idx) {
    for (int i = anglestart;i < anglestop ;i++) {
        float degInRad = i*3.14159/180;
        int index = idx+i-anglestart;
        quads[index][0] = cos(degInRad)*r + x;
        quads[index][1] = sin(degInRad)*r + y;
        quads[index][2] = 0;
        quads[index][3] = red;
        quads[index][4] = green;
        quads[index][5] = blue;
    }
}

void QuadInverseCircle(float x, float y, float r, int anglestart, int anglestop, int idx) {
    for (int i = anglestart-1;i >= anglestop ;i--) {
        float degInRad = i*3.14159/180;
        int index = idx-i+anglestart-1;
        quads[index][0] = cos(degInRad)*r + x;
        quads[index][1] = sin(degInRad)*r + y;
        quads[index][2] = 0;
        quads[index][3] = red;
        quads[index][4] = green;
        quads[index][5] = blue;
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
    circle(-0.18,0.65,0.28, 140, 270);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.39,0.055,0.78, 90, 180);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-1.07,0.055,0.1, 40, 180);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-0.992, 0.12);
        glVertex2f(-0.9, -0.2);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.8,-0.2,0.1, 40, 180);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-0.72, -0.135);
        glVertex2f(-0.5, -0.4);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.3,0.2,1, 190, 215);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.66,-0.176,0.2, 30, 100);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.382,-0.074,0.1, 20, 180);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.234,-0.070,0.058, 0, 160);
    glEnd();
}

void drawLeftWing() {
    glBegin(GL_LINE_STRIP);
    circle(0.06,0.65,0.28, -90, 42);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.27,0.055,0.78, 0, 91);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.95,0.055,0.1, 0, 140);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(0.872, 0.12);
        glVertex2f(0.78, -0.2);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.68,-0.2,0.1, 0, 140);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(0.6, -0.135);
        glVertex2f(0.38, -0.4);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(-0.42,0.2,1, 325, 351);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.54,-0.176,0.2, 80, 150);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.262,-0.074,0.1, 0, 161);
    glEnd();

    glBegin(GL_LINE_STRIP);
    circle(0.114,-0.070,0.058, 20, 180);
    glEnd();
}

void drawRainbow() {
    red = 1;
    green = 0;
    blue = 0;
    QuadCircle(0, -0.5, 0.7, 20, 160, 0);
    red = 0;
    blue = 1;
    QuadInverseCircle(0, -0.5, 0.6, 160, 20, 140);
    red = 1;
    blue = 0;
    QuadCircle(0, -0.5, 0.7, 20, 21, 280);
}

void drawTess() {
    // create tessellator
    GLUtesselator *tess = gluNewTess();

    // register callback functions
    gluTessCallback(tess, GLU_TESS_BEGIN, (void (__stdcall*)(void))tessBeginCB);
    gluTessCallback(tess, GLU_TESS_END, (void (__stdcall*)(void))tessEndCB);
    gluTessCallback(tess, GLU_TESS_ERROR, (void (__stdcall*)(void))tessErrorCB);
    gluTessCallback(tess, GLU_TESS_VERTEX, (void (__stdcall*)(void))tessVertexCB2);
    gluTessCallback(tess, GLU_TESS_COMBINE, (void (__stdcall*)(void))tessCombineCB);

    GLdouble quad1[4][3] = { {-0.2,0.6,0}, {0,0,0}, {0.2,0.6,0}, {0,0.4,0} };

    glColor3f(1, 1, 1);
    red = 1;
    green = 1;
    blue = 1;
    // describe non-convex polygon
    gluTessBeginPolygon(tess, NULL);
        // first contour
        gluTessBeginContour(tess);
            /*
            gluTessVertex(tess, quad1[0], quad1[0]);
            gluTessVertex(tess, quad1[1], quad1[1]);
            gluTessVertex(tess, quad1[2], quad1[2]);
            gluTessVertex(tess, quad1[3], quad1[3]);
            */

            for (int i = 0;i < 280;i++) {
                cout << i << " ";
                gluTessVertex(tess, quads[i], quads[i]);
            }
        gluTessEndContour(tess);

    gluTessEndPolygon(tess);

    // delete tessellator after processing
    gluDeleteTess(tess);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawDragonHead();
    drawDragonTail();
    drawRightWing();
    drawLeftWing();
    drawRainbow();
    drawTess();
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

    drawRainbow();
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}

void CALLBACK tessBeginCB(GLenum which)
{
    glBegin(which);
}
void CALLBACK tessEndCB()
{
    glEnd();
}
void CALLBACK tessVertexCB(const GLvoid *data)
{
    // cast back to double type
    const GLdouble *ptr = (const GLdouble*)data;

    glVertex3dv(ptr);
}
void CALLBACK tessVertexCB2(const GLvoid *data)
{
    // cast back to double type
    const GLdouble *ptr = (const GLdouble*)data;

    glColor3dv(ptr+3);
    glVertex3dv(ptr);

    // DEBUG //
    cout << "  glColor3d(" << *(ptr+3) << ", " << *(ptr+4) << ", " << *(ptr+5) << ");\n";
    cout << "  glVertex3d(" << *ptr << ", " << *(ptr+1) << ", " << *(ptr+2) << ");\n";
}
void CALLBACK tessCombineCB(const GLdouble newVertex[3], const GLdouble *neighborVertex[4],
                            const GLfloat neighborWeight[4], GLdouble **outData)
{
    // copy new intersect vertex to local array
    // Because newVertex is temporal and cannot be hold by tessellator until next
    // vertex callback called, it must be copied to the safe place in the app.
    // Once gluTessEndPolygon() called, then you can safly deallocate the array.
    vertices[vertexIndex][0] = newVertex[0];
    vertices[vertexIndex][1] = newVertex[1];
    vertices[vertexIndex][2] = newVertex[2];

    // compute vertex color with given weights and colors of 4 neighbors
    // the neighborVertex[4] must hold required info, in this case, color.
    // neighborVertex was actually the third param of gluTessVertex() and is
    // passed into here to compute the color of the intersect vertex.
    vertices[vertexIndex][3] = neighborWeight[0] * neighborVertex[0][3] +   // red
                               neighborWeight[1] * neighborVertex[1][3] +
                               neighborWeight[2] * neighborVertex[2][3] +
                               neighborWeight[3] * neighborVertex[3][3];
    vertices[vertexIndex][4] = neighborWeight[0] * neighborVertex[0][4] +   // green
                               neighborWeight[1] * neighborVertex[1][4] +
                               neighborWeight[2] * neighborVertex[2][4] +
                               neighborWeight[3] * neighborVertex[3][4];
    vertices[vertexIndex][5] = neighborWeight[0] * neighborVertex[0][5] +   // blue
                               neighborWeight[1] * neighborVertex[1][5] +
                               neighborWeight[2] * neighborVertex[2][5] +
                               neighborWeight[3] * neighborVertex[3][5];


    // return output data (vertex coords and others)
    *outData = vertices[vertexIndex];   // assign the address of new intersect vertex

    ++vertexIndex;  // increase index for next vertex
}
void CALLBACK tessErrorCB(GLenum errorCode)
{
    const GLubyte *errorStr;

    errorStr = gluErrorString(errorCode);
    cerr << "[ERROR]: " << errorStr << endl;
}
