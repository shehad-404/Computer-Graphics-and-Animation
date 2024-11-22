// 6. Car Drawing

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

// Function to draw the car
void drawCar() {
    // Set car body color
    glColor3f(0.2f, 0.6f, 0.8f); // Blue body color

    // Draw car body (rectangle)
    glBegin(GL_QUADS);
    glVertex2f(-0.6f, 0.0f);  // Bottom-left corner
    glVertex2f(0.6f, 0.0f);   // Bottom-right corner
    glVertex2f(0.5f, 0.3f);   // Top-right corner
    glVertex2f(-0.5f, 0.3f);  // Top-left corner
    glEnd();

    // Draw car roof (rectangle)
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, 0.3f);
    glVertex2f(0.4f, 0.3f);
    glVertex2f(0.3f, 0.5f);
    glVertex2f(-0.3f, 0.5f);
    glEnd();

    // Set wheel color
    glColor3f(0.1f, 0.1f, 0.1f); // Black wheels

    // Draw left wheel
    drawCircle(-0.4f, -0.1f, 0.15f);

    // Draw right wheel
    drawCircle(0.4f, -0.1f, 0.15f);
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glLoadIdentity();             // Reset transformations

    drawCar(); // Call the car drawing function

    glFlush(); // Render to screen
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple 2D Car with OpenGL");

    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Set coordinate system

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
