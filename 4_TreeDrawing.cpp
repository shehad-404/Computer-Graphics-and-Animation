// 8. Tree Drawing

#include <GL/glut.h> // OpenGL and GLUT library
#include <cmath>

// Function to draw a filled circle
void drawCircle(float x, float y, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

// Function to draw a rectangle (for the trunk)
void drawRectangle(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

// Function to draw a tree
void drawTree() {
    // Set trunk color (brown)
    glColor3f(0.55f, 0.27f, 0.07f);

    // Draw tree trunk
    drawRectangle(-0.05f, -0.5f, 0.1f, 0.4f);

    // Set leaves color (green)
    glColor3f(0.0f, 0.8f, 0.0f);

    // Draw leaves as circles
    drawCircle(0.0f, 0.1f, 0.2f); // Top circle
    drawCircle(-0.15f, -0.1f, 0.2f); // Left circle
    drawCircle(0.15f, -0.1f, 0.2f);  // Right circle
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glLoadIdentity();             // Reset transformations

    drawTree(); // Call the tree drawing function

    glFlush(); // Render to screen
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple 2D Tree - OpenGL");

    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Set coordinate system

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


