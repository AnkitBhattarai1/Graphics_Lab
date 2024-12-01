
#include "../../include/lib/Point.h"
#include <GL/gl.h>
#include <cmath>
#include <iostream>

void dda_draw_line(Point2DPtr p1, Point2DPtr p2){

    float dx =  p2->x-p1->x;
    float dy =  p2->y-p1->y;

    int step_size = (abs(dx)>abs(dy)?abs(dx):abs(dy));

    float xInc = dx/step_size;
    float yInc = dy/step_size;

    float x = p1->x;
    float y = p1->y;
    
    glBegin(GL_POINTS);

    for (int i=0; i<=step_size; i++){
        glVertex2f(x,y);
        x+=xInc;
        y+=yInc;
    }
    glEnd();
}
