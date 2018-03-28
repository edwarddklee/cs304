/*  Edward Lee (930916087)
	CSCI 304-03
	Davis
	Project Description: To write a program in C that implements a ray casting renderer taht is a 2D image of the spheres. (1000x1000 PPM image created)
	File Description: vec.c: creates c class file that has two functions VEC_T and dot which computes and returns 
					  a normalized vector for VEC_T and dot product of v1 & v2 for dot. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vec.h"

VEC_T normalize (VEC_T v){
	double square = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	v.x = v.x/square;
	v.y = v.y/square;
	v.z = v.z/square;
	return v;	
}

double dot (VEC_T v1, VEC_T v2)
{
	double point;
	point = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
return point;
}