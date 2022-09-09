#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>

#define pi 3.14159

typedef struct _poi
{
	float xcord;
	float ycord;
}POINT;

typedef struct _cir
{
	POINT centre;
	float radius;
}CIRC;

typedef struct _rec
{
	POINT lower_left;
	POINT upper_right;
}RECT;

int overlaps(CIRC c1,CIRC c2);
void encloserect(CIRC c1,CIRC c2,RECT *prec);
CIRC generate();
float area(CIRC c);
void printc(CIRC c);
void printr(RECT r);

int main()
{
	CIRC *circlist = NULL;

	int n;
	printf("Enter the value of n : \n");
	scanf("%d",&n);

	circlist = (CIRC *)malloc(n*sizeof(CIRC));
	if(circlist == NULL)
	{
		printf("Failed to allocate the space.\n");
		exit(-1);
	}

	//generating random circles
	for(int i=0; i<n; i++)
		*(circlist + i) = generate();

//-----------------------------part (e) -----------------------------------
	float min_center_dist = FLT_MAX,dist = 0;
	CIRC c1,c2;
	float a1,b1,a2,b2,ra,rb;

	for(int i=0; i<n; i++)
	{
		a1 = (circlist + i)->centre.xcord;
		b1 = (circlist + i)->centre.ycord;
		ra = (circlist + i)->radius;

		for(int j=i+1; j<n; j++)
		{
			a2 = (circlist + j)->centre.xcord;
			b2 = (circlist + j)->centre.ycord;
			rb = (circlist + j)->radius;

			dist = sqrt((a1-a2)*(a1-a2) + (b1-b2)*(b1-b2));

			if(dist < min_center_dist)
			{
				c1.centre.xcord = a1;
				c1.centre.ycord = b1;
				c1.radius = ra;

				c2.centre.xcord = a2;
				c2.centre.ycord = b2;
				c2.radius = rb;
			}
		}
	}

	RECT r1;

	encloserect(c1,c2,&r1);

	printc(c1);
	printc(c2);
	printr(r1);

//-----------------------------part (f) -----------------------------------
	float min_area = FLT_MAX, max_area = 0,Area = 0;
	CIRC c3,c4;

	for(int i=0; i<n; i++)
	{
		Area = area(*(circlist+i));

		if(Area < min_area)
		{
			c3.centre.xcord = (circlist + i)->centre.xcord;
			c3.centre.ycord = (circlist + i)->centre.ycord;
			c3.radius = (circlist + i)->radius;
		}
		if(Area > max_area)
		{
			c4.centre.xcord = (circlist + i)->centre.xcord;
			c4.centre.ycord = (circlist + i)->centre.ycord;
			c4.radius = (circlist + i)->radius;
		}
	}

	RECT r2;

	encloserect(c1,c2,&r2);

	printc(c3);
	printc(c4);
	printr(r2);
}

int overlaps(CIRC c1,CIRC c2)
{
	float x1 = c1.centre.xcord;
	float y1 = c1.centre.ycord;
	float x2 = c2.centre.xcord;
	float y2 = c2.centre.ycord;
	float r1 = c1.radius;
	float r2 = c2.radius;

	float distance_between_centers = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

	if(distance_between_centers > (r1 + r2))	//disjoint case
		return 0;
	else
		if((distance_between_centers < (r1 + r2)) && (distance_between_centers > abs(r1-r2)))	//intersecting case
			return 1;
		else if(distance_between_centers < abs(r1-r2))
			if(r1 > r2)		//c1 encloses c2
				return 2;
			else if(r1 < r2)	//c2 encloses c1
				return 3;
}

void encloserect(CIRC c1,CIRC c2,RECT *prec)
{
	int cond = overlaps(c1,c2);

	float x1 = c1.centre.xcord;
	float y1 = c1.centre.ycord;
	float x2 = c2.centre.xcord;
	float y2 = c2.centre.ycord;
	float r1 = c1.radius;
	float r2 = c2.radius;

	if(cond == 0 || cond == 1)	//when both the circles are disjoint or the intersecting both have same cases
	{
		if(x2 > x1)
			if(y2 > y1)
			{
				(*prec).upper_right.xcord = x2+r2;
				(*prec).upper_right.ycord = y2+r2;


				(*prec).lower_left.xcord = x1-r1;
				(*prec).lower_left.ycord = y1-r1;
			}
			else
			{
				(*prec).upper_right.xcord = x2+r2;
				(*prec).upper_right.ycord = y1+r1;


				(*prec).lower_left.xcord = x1-r1;
				(*prec).lower_left.ycord = y2-r2;
			}
		else
			if(y2 > y1)
			{
				(*prec).upper_right.xcord = x1+r1;
				(*prec).upper_right.ycord = y2+r2;


				(*prec).lower_left.xcord = x2-r2;
				(*prec).lower_left.ycord = y1-r1;
			}
			else
			{
				(*prec).upper_right.xcord = x1+r1;
				(*prec).upper_right.ycord = y1+r1;


				(*prec).lower_left.xcord = x2-r2;
				(*prec).lower_left.ycord = y2-r2;
			}
	}
	else if(cond == 2)		//c1 encloses c2
	{
		(*prec).upper_right.xcord = x1+r1;
		(*prec).upper_right.ycord = y1+r1;


		(*prec).lower_left.xcord = x1-r1;
		(*prec).lower_left.ycord = y1-r1;
	}
	else if(cond == 3)		//c2 encloses c1
	{
		(*prec).upper_right.xcord = x2+r2;
		(*prec).upper_right.ycord = y2+r2;


		(*prec).lower_left.xcord = x2-r2;
		(*prec).lower_left.ycord = y2-r2;
	}
}

CIRC generate()
{
	CIRC c;
	c.centre.xcord = (float)(rand()%(10-0+1)+0);
	c.centre.ycord = (float)(rand()%(10-0+1)+0);

	int upper = 1,lower = 5;	//setting the limits of rand() function.
	c.radius = (float)(rand()%(upper - lower + 1) + lower);
	//printf("(%f %f)\n\n%f\n\n\n",c.centre.xcord,c.centre.ycord,c.radius);

	return c;
}

float area(CIRC c)
{
	return (pi*c.radius*c.radius);
}

void printc(CIRC c)
{
	printf("Centre of the circle is : (%f,%f)\n",c.centre.xcord,c.centre.ycord);
	printf("Radius of the circle is : %f\n",c.radius);
}

void printr(RECT r)
{
	float d1 = abs(r.upper_right.xcord - r.lower_left.xcord);
	float d2 = abs(r.upper_right.ycord - r.lower_left.ycord);

	if(d1 > d2)	//Length is always greater then breadth
	{
		printf("Length of rectangle : %f\n",d1);
		printf("Breadth of rectangle : %f\n",d2);
	}
	else
	{
		printf("Length of rectangle : %f\n",d2);
		printf("Breadth of rectangle : %f\n",d1);
	}
}
