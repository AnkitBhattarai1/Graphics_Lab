
#include "../../include/lib/Point.h"
#include <GL/gl.h>
#include <cmath>
#include <iostream>


void draw_line_x(Point2DPtr p1, Point2DPtr p2);
void draw_line_y(Point2DPtr p1, Point2DPtr p2);
void bresenham_draw_line(Point2DPtr p1,Point2DPtr p2){

    int dx = p2->x-p1->x;
    int dy= p2->y-p1->y;

   if(std::abs(dy)>std::abs(dx)) draw_line_y(p1,p2);
    
   else draw_line_x(p1,p2);
}


void draw_line_x(Point2DPtr p1, Point2DPtr p2){
    int dx = abs(p2->x-p1->x);
    int dy = abs(p2->y-p1->y);

    int pk = 2*dy-dx;
    int x=p1->x,y=p1->y;
    
    int sx= (p2->x>p1->x)?1:-1;
    int sy= (p2->y>p1->y)?1:-1;
    glBegin(GL_POINTS);
    while(x!=(p2->x)){
        glVertex2f(x,y);
        if(pk<0){
            pk+=dy*2;
            x+=sx;
        }
        else{
            pk+=(2*dy-2*dx);
            x+=sx;
            y+=sy;
        }
    }
    glEnd();
}

void draw_line_y(Point2DPtr p1, Point2DPtr p2){
    int dx = abs(p2->x-p1->x);
    int dy= abs(p2->y-p1->y);
     
    int pk =2*dx-dy;
    int x=p1->x,y=p1->y;

    int sx =(p2->x>p1->x) ? 1: -1;
    int sy =(p2->y>p1->y)?1:-1;

    glBegin(GL_POINTS);

    while(y!=p2->y){
        glVertex2f(x,y);
        if(pk<0){
            pk+=dx*2;
            y+=sy;
        }
        else {
            pk+=(2*dx-2*dy);
            x+=sx;
            y+=sy;
        }

    }
    glEnd();
}
