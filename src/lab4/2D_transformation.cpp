#include "../../include/lib/Point.h"
#include <algorithm>
#include <math.h>

void rotate(double angle_in_rad,Point2DPtr point);
void translate(int tx, int ty, Point2DPtr point);
void scale(int sx, int sy, Point2DPtr point);
void transform(double trans_matx[3][3], Point2DPtr point);
double**  combine_transformation(double** second_trans, double** frist_trans);


double rotation_matrix [3][3];
double scale_matrix[3][3];
double translate_matrix[3][3];

void  get_rotation_matrix(double angle_in_rad){
    rotation_matrix[0][0]=cos(angle_in_rad); /* */ rotation_matrix[0][1]=-(sin(angle_in_rad)); /* */ rotation_matrix[0][2]=0;

    rotation_matrix[1][0]=sin(angle_in_rad); /* */ rotation_matrix[1][1]=cos(angle_in_rad) ; /* */ rotation_matrix[1][2]=0;
     
    rotation_matrix[2][0]=0;                 /* */ rotation_matrix[2][1]=0 ;                /* */ rotation_matrix[2][2]=1;
}

void get_translate_matrix(int tx, int ty){

    translate_matrix[0][0]=1; /* */translate_matrix[0][1]=0; /* */translate_matrix[0][2]=tx;

    translate_matrix[1][0]=0; /* */translate_matrix[1][1]=1; /* */translate_matrix[1][2]=ty;
    
    translate_matrix[2][0]=0; /* */translate_matrix[2][1]=0; /* */translate_matrix[2][2]=1;
}

void get_scale_matrix(int sx, int sy){

    scale_matrix[0][0]=sx; /* */ scale_matrix[0][1]=0; /* */ scale_matrix[0][2]=0;

    scale_matrix[1][0]=0; /* */ scale_matrix[1][1]=sy; /* */ scale_matrix[1][2]=0;
    
    scale_matrix[2][0]=0; /* */ scale_matrix[2][1]=0; /* */ scale_matrix[2][2]=1;
}

void rotate(double angle_in_rad, Point2DPtr point){

    get_rotation_matrix(angle_in_rad);
    transform(rotation_matrix, point);
}

void translate(int tx , int ty, Point2DPtr point){

    get_translate_matrix(tx,ty);
    transform(translate_matrix,point);
}

void scale(int sx, int sy , Point2DPtr point){
    get_scale_matrix(sx,  sy);
    transform(scale_matrix,point);
}

void transform(double trans_matx[3][3], Point2DPtr point){

}

double** combine_transformation(double** second_trans, double** first_trans){

    double** result ;

    return result;
}
