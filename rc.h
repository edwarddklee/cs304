/*  Edward Lee (930916087)
	CSCI 304-03
	Davis
	Project Description: To write a program in C that implements a ray casting renderer taht is a 2D image of the spheres. (1000x1000 PPM image created)
	File Description: rc.h: header file that initializes variables, RAY_T, COLOR_T, SPHERE_T, & OBJ_T. */

#include "vec.h"



typedef struct{
	VEC_T origin;
	VEC_T direction;
}  RAY_T; //typedef for RAY_T, initializing origin and direction.


typedef struct{
	double R;
	double G;
	double B;
} COLOR_T; //typedef for COLOR_T, initialized red, green, and blue as a double declaration.


typedef struct{
	VEC_T ctr;
	double radius;
} SPHERE_T; //typedef for SPHERE_T, intializing center and radius



typedef struct NODE{
	SPHERE_T sphere;
	COLOR_T color;
	struct NODE *next;
} OBJ_T; //typedef for OBJ_T, which uses the sphere, color, and next fields. 


