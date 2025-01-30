
#include <GLFW/glfw3.h>
#include <cmath>
#include "../../src/lab4/2D_transformation.cpp"
#include "../../src/lab2/dda.cpp"

void drawWindMill(Point2DPtr center, Point2DPtr bladeTip, double angleInRad) {
    glColor3f(0.5f, 0.5f, 0.5f); // Gray color for the pole



    // Draw each blade
    for (int i = 0; i < 4; ++i) {
        Point2DPtr currentBladeTip = new Point2D{bladeTip->x, bladeTip->y};
        Point2DPtr n1 = new Point2D{bladeTip->x - 10, bladeTip->y}; // Left corner of the blade
        Point2DPtr n2 = new Point2D{bladeTip->x + 10, bladeTip->y}; // Right corner of the blade

        translate(-center->x, -center->y, currentBladeTip);
        translate(-center->x, -center->y, n1);
        translate(-center->x, -center->y, n2);

        rotate(angleInRad + i * (M_PI / 2), currentBladeTip);
        rotate(angleInRad + i * (M_PI / 2), n1);
        rotate(angleInRad + i * (M_PI / 2), n2);

        translate(center->x, center->y, currentBladeTip);
        translate(center->x, center->y, n1);
        translate(center->x, center->y, n2);

        glColor3f(1.0f, 0.0f, 0.0f); 
        dda_draw_line(center, n1);
        dda_draw_line(center, n2);
        dda_draw_line(n1, n2);

        delete currentBladeTip;
        delete n1;
        delete n2;
    }


}

void simulateWindmill(Point2DPtr center, int bladeLength, double& angle, double speed) {
    angle += speed; // Increment the angle based on the speed

    // Reset angle after a full rotation
    if (angle >= 2 * M_PI) angle -= 2 * M_PI;

    // Define the initial blade tip position
    Point2DPtr bladeTip = new Point2D{center->x, center->y + bladeLength};

    // Draw the windmill with the current angle
    drawWindMill(center, bladeTip, angle);

    delete bladeTip;
}
