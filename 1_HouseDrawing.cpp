// 5. House Making using OpenGL

#include <windows.h>
#include <GL/glut.h>

void init() {

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 640.0);
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.0, 0.5);
    glVertex2i(200, 200);
    glVertex2i(400, 200);
    glVertex2i(400, 400);
    glVertex2i(200, 400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2i(180, 400);
    glVertex2i(420, 400);
    glVertex2i(300, 500);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.0);
    glVertex2i(270, 200);
    glVertex2i(330, 200);
    glVertex2i(330, 300);
    glVertex2i(270, 300);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);
    glVertex2i(220, 320);
    glVertex2i(260, 320);
    glVertex2i(260, 360);
    glVertex2i(220, 360);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(340, 320);
    glVertex2i(380, 320);
    glVertex2i(380, 360);
    glVertex2i(340, 360);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutCreateWindow("Sehad's House");

    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;
}

