#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 50
#define PI 3.14159

double rand_float(double a, double b);

typedef struct {
  double x;
  double y;
  double radius;
} Circle;

int main(void)
{
  /* Seed random number generator */
  srand(time(0));

  Circle *circles[ARR_SIZE];
  int i;
  for(i = 0; i < ARR_SIZE; i++)
  {
    circles[i] = (Circle *)malloc(sizeof(Circle));
    circles[i]->x = rand_float(100, 900);
    circles[i]->y = rand_float(100, 900);
    circles[i]->radius = rand_float(0, 100);
  }
  
  Circle *largest;
  double area = 0.0;
  double maxarea = 0.0;
  for(i = 0; i < ARR_SIZE; i++)
  {
    area = PI * circles[i]->radius * circles[i]->radius;
    if(area > maxarea)
    {
      maxarea = area;
      largest = circles[i];
    }
  }

  printf("Circle with largest area (%lf) has\n", maxarea);
  printf("center (%lf, %lf) and radius %lf\n", largest->x, largest->y, largest->radius);

  for(i = 0; i < ARR_SIZE; i++)
    free(circles[i]);

  return 0;
}

double rand_float(double a, double b)
{
  return ((double)rand() / RAND_MAX) * (b - a) + a;
}

