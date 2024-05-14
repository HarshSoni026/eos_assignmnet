#include<stdio.h>
#include"circle.h"
#include"square.h"
#include"rectangle.h"

int main()
{
	int r = 12;
	int a = 6;
	float le = 12.08;
	float br = 4.6;

	//area of circle
	printf("area of circle : %d\n",area_of_circle(r));

	//area of square
	printf("area of square : %d\n", area_of_square(a));

	//area of rectangle
	printf("area of rectangle : %.2f\n", area_of_rec(le,br));

	return 0;
}
