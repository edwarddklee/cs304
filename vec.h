/*  Edward Lee (930916087)
	CSCI 304-03
	Davis
	Project Description: To write a program in C that implements a ray casting renderer taht is a 2D image of the spheres. (1000x1000 PPM image created)
	File Description: vec.h: Header file for vec.c, has the full VEC_T with x,y, and z fields. */

#ifndef VEC_H
#define VEC_H

typedef struct 
{
	double x;
	double y;
	double z;
} VEC_T;

VEC_T normalize (VEC_T v);

#endif
