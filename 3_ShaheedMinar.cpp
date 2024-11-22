// 7. Shaheed Minar

#include <GL/glut.h>
#include <cmath>

// Initialize OpenGL settings
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800.0, 0.0, 600.0); // Set 2D orthographic projection
}

// Function to draw a rectangle outline with given bottom-left and top-right coordinates
void drawRectangleOutline(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

// Function to draw a filled red circle
void drawCircle(float cx, float cy, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100;
        glVertex2f(cx + cos(angle) * radius, cy + sin(angle) * radius);
    }
    glEnd();
}

// Function to draw vertical lines inside a rectangle for each pillar
void drawVerticalLines(float x1, float y1, float x2, float y2, int numLines) {
    float spacing = (x2 - x1) / (numLines + 1);
    for (int i = 1; i <= numLines; i++) {
        float x = x1 + i * spacing;
        glBegin(GL_LINES);
        glVertex2f(x, y1);
        glVertex2f(x, y2);
        glEnd();
    }
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Draw the red circle in the background
    glColor3f(1.0, 0.0, 0.0); // Red
    drawCircle(400.0, 250.0, 100.0); // Center at (400, 250) with radius 100

    // Draw the base platform of the Shaheed Minar
    glColor3f(0.0, 0.0, 0.0); // Black
    glLineWidth(2.0); // Thicker outline for base
    drawRectangleOutline(250.0, 100.0, 550.0, 130.0);

    // Main middle pillar
    glColor3f(0.0, 0.0, 0.0); // Black
    drawRectangleOutline(375.0, 130.0, 425.0, 300.0); // Middle pillar outline
    drawVerticalLines(375.0, 130.0, 425.0, 300.0, 7); // Vertical lines in main pillar

    // Left pillar
    drawRectangleOutline(320.0, 130.0, 350.0, 250.0); // Left pillar outline
    drawVerticalLines(320.0, 130.0, 350.0, 250.0, 3); // Vertical lines in left pillar

    // Right pillar
    drawRectangleOutline(450.0, 130.0, 480.0, 250.0); // Right pillar outline
    drawVerticalLines(450.0, 130.0, 480.0, 250.0, 3); // Vertical lines in right pillar

    // Left-most smaller pillar
    drawRectangleOutline(285.0, 130.0, 305.0, 220.0); // Left-most small pillar outline
    drawVerticalLines(285.0, 130.0, 305.0, 220.0, 2); // Vertical lines in left-most pillar

    // Right-most smaller pillar
    drawRectangleOutline(495.0, 130.0, 515.0, 220.0); // Right-most small pillar outline
    drawVerticalLines(495.0, 130.0, 515.0, 220.0, 2); // Vertical lines in right-most pillar

    glFlush(); // Render the shapes
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);          // Set the window size
    glutInitWindowPosition(100, 100);      // Set the window position
    glutCreateWindow("Shaheed Minar");     // Create the window with a title
    init();                                // Initialize the drawing settings
    glutDisplayFunc(display);              // Set the display function
    glutMainLoop();                        // Enter the main loop
    return 0;
}
