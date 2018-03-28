/*  Edward Lee (930916087)
	CSCI 304-03
	Davis
	Project Description: To write a program in C that implements a ray casting renderer that is a 2D image of the spheres. (1000x1000 PPM image created)
	File Description: rc.c: the c file that read the spheres from stdin, sees if spheres intersect, colors, casts the rays, and has the main function. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rc.h"
#include "vec.h"

void read_objs (OBJ_T **list)
{
 	 double cx, cy, cz, radius, r, g, b;
	 OBJ_T *new;
	 *list = NULL;

	 while (scanf("%lf %lf %lf %lf %lf %lf %lf", &cx, &cy, &cz, &radius, &r, &g, &b) == 7)
	 {
	 	new = (OBJ_T *)malloc(sizeof(OBJ_T));
	 	new -> sph.ctr.x = cx;
	 	new -> sph.ctr.y = cy;
		new -> sph.ctr.z = cz;
		new -> sph.radius = radius;
	 	new -> color.R = r;
	 	new -> color.G = g;
	 	new -> color.B = b;
	 	new -> next = *list;
		*list = new;
	 }

} 
	
int intersect_sphere (RAY_T ray, SPHERE_T sphere, double *t)
{
	
	double A = 1;
	double B = 2 * ((ray.direction.x * (ray.origin.x - sphere.ctr.x)) +
			 (ray.direction.y * (ray.origin.y - sphere.ctr.y)) +
			 (ray.direction.z * (ray.origin.z - sphere.ctr.z)));
	double C = pow(ray.origin.x - sphere.ctr.x, 2) +
		       pow(ray.origin.y - sphere.ctr.y, 2) +
			   pow(ray.origin.z - sphere.ctr.z, 2) -
		       pow(sphere.radius, 2);

	double discriminant = pow(B, 2) - 4*A*C;

	if (discriminant < 0)
	{
		return 0;
	}
	else{
		double t1 = (-B + sqrt(discriminant)) / (2*A);
		double t2 = (-B - sqrt(discriminant)) / (2*A);
		if (t1 <= 0 || t2 <= 0)
		{
			return 0;
		}
		else{
			double t = fmin(t1, t2);
			return 1;
		}
  }
}

COLOR_T cast (RAY_T ray, OBJ_T *list)
{
	OBJ_T *curr;
	double min_T = 1000;
	double t;
	COLOR_T new_color;
	new_color.R = 1;
	new_color.G = 1;
	new_color.B = 1; //initializes this to the color white for the background
	for (curr = list; curr != NULL; curr = curr->next)
	{
		if(intersect_sphere(ray, curr->sph, &t))
		{
			if(t < min_T)
			{
				new_color = curr->color;
				min_T = t;
			}
		}
	}
	return new_color;
}

int main(int argc, char *argv[]){
	printf("P6\n 1000 1000 \n 255\n");
	OBJ_T *new_list;
	read_objs(&new_list);
	double x, y;
	for (y = 0; y < 1000; y++){
		for (x = 0; x< 1000; x++){
			RAY_T new_ray;
			new_ray.origin.x = 0;
			new_ray.origin.y = 0;
			new_ray.origin.z = 0;
			new_ray.direction.x = -0.5 + x / 1000.0;
			new_ray.direction.y = -0.5 + y / 1000.0;
			new_ray.direction.z = 1;
			new_ray.direction = normalize(new_ray.direction);
			COLOR_T draw;
			draw = cast(new_ray, new_list);
			printf("%c%c%c", (unsigned char)(draw.R*255), (unsigned char)(draw.B*255), (unsigned char)(draw.G*255));
		}
	}
	free(new_list);
	return 0;
}

