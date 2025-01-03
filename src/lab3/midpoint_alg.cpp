#include <iostream>
#include "../../include/lib/Point.h"
#include <GL/gl.h>
#include "../../src/lab2/dda.cpp"
//plot the given point and its 8 symmetric by transforming the center from origin to the given center

void plot_ellipse_points(Point2DPtr point, Point2DPtr center){
    glBegin(GL_POINTS);
    glVertex2i((center->x)+(point->x), (center->y)+(point->y)); //(x,y)
    glVertex2i((center->x)-(point->x), (center->y)-(point->y));//(-x,-y) 
    glVertex2i((center->x)-(point->x), (center->y)+(point->y));//(-x,y) 
    glVertex2i((center->x)+(point->x), (center->y)-(point->y));//(x,-y)
}

void plot_circle_point(Point2DPtr point , Point2DPtr center){

    glBegin(GL_POINTS);
    glVertex2i((center->x)+(point->x), (center->y)+(point->y)); //(x,y)
    glVertex2i((center->x)-(point->x), (center->y)-(point->y));//(-x,-y) 
    glVertex2i((center->x)-(point->x), (center->y)+(point->y));//(-x,y) 
    glVertex2i((center->x)+(point->x), (center->y)-(point->y));//(x,-y)

    glVertex2i((center->x)+(point->y), (center->y)+(point->x));//(y,x)
    glVertex2i((center->x)-(point->y), (center->y)-(point->x));//(-y,-x)
    glVertex2i((center->x)-(point->y), (center->y)+(point->x));//(-y,x)
    glVertex2i((center->x)+(point->y), (center->y)-(point->x));//(y,-x)
}


void draw_midpoint_circle(int r, Point2DPtr center){

    int x=0, y=r;
    int p=1-r;// initial decision paramter...

    while(x<=y){
        plot_circle_point(new Point2D{x,y}, center);//plots the given point and its 8 symmetric points
        x++;  // sampling in x direction
        if(p<0)
            p+=2*x+3;// decision paramter.  

        else{ 
            y--;
            p+=2*x-2*y+5; 
        }
    }
}

void draw_midpoint_ellipse(int a, int b, Point2DPtr center){
 //region1
    int x = 0, y = b;
    int p1 = (b * b) - (a * a * b) + (a * a) / 4;  
    int dx = 2 * b * b * x;
    int dy = 2 * a * a * y;

    // Region 1
    while (dx < dy) {
        plot_ellipse_points(new Point2D{x, y}, center);  

        x++;  
        dx = dx + 2 * b * b;  
        if (p1 < 0) {
            p1 = p1 + dx + b * b;  
        } else {
            y--;  
            dy = dy - 2 * a * a;  
            p1 = p1 + dx - dy + b * b;  
        }
    }

    // Region 2: 
    int p2 = (b * b) * (x + 1) * (x + 1) + (a * a) * (y - 1) * (y - 1) - (a * a * b * b);  // Initial decision parameter for region 2

    while (y > 0) {
        plot_ellipse_points(new Point2D{x, y}, center);  

        y--;  
        dy = dy - 2 * a * a;  
        if (p2 > 0) {
            p2 = p2 - dy + a * a;  
        } else {
            x++;  // 
            dx = dx + 2 * b * b;  
            p2 = p2 + dx - dy + a * a;  
        }
    }
    
}
