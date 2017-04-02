#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    fprintf(stderr, "Usage: %s number number\n", argv[0]);
    return 1;
  }

  int num1 = atoi(argv[1]);
  int num2 = atoi(argv[2]);

  printf("Before: %i %i\n", num1, num2);

  swap(&num1, &num2);

  printf("After: %i %i\n", num1, num2);
  return 0;
}

void swap(int *num1, int *num2)
{
  *num1 = *num1 + *num2;
  *num2 = *num1 - *num2;
  *num1 = *num1 - *num2;
}
