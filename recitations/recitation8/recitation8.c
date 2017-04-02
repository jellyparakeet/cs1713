#include <stdio.h>
#include <stdlib.h>

double average(double *ptr, int size);
int aboveaverage(double *ptr, int size, double average);

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("Usage: %s file\n", argv[0]);
    exit(1);
  }

  FILE *file = fopen(argv[1], "r");
  if(file == NULL)
  {
    printf("Error opening %s\n", argv[1]);
    exit(1);
  }

  int num_elem = 10;
  double *array = (double *)calloc(num_elem, sizeof(double));
  if(array == NULL)
  {
    printf("Error allocating 10 integers\n");
    exit(1);
  }
  else
    printf("Allocated %d integers\n", num_elem);

  double el;
  int i = 0;
  while(fscanf(file, "%lf", &el) != EOF)// (feof(file) == 0) is incorrect checks for EOF based on last I/O operation not current position of FILE *, so will iterate 1 extra time even though EOF has already been reached which returns wrong average
  {
    if(i >= num_elem)
    {
      num_elem *= 2;
      array = (double *)realloc(array, num_elem * sizeof(double));
      printf("Reallocated to %d integers\n", num_elem);
    }
    array[i] = el;
    i++;
  }
  fclose(file);

  double avg = average(array, i);
  int abv_avg = aboveaverage(array, i, avg);

  printf("%d elements are above average of %.6lf\n", abv_avg, avg);

  free(array);
  printf("Dynamic array freed\n");
  return 0;
}

double average(double *ptr, int size)
{
  double sum = 0;
  int i;
  for(i = 0; i < size; i++)
    sum += *(ptr + i);

  sum /= size;
  return sum;
}

int aboveaverage(double *ptr, int size, double average)
{
  int count = 0;
  int i;
  for(i = 0; i < size; i++)
    if(*(ptr + i) > average)
      count++;

  return count;
}
