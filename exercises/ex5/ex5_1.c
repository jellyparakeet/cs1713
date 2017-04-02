#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertrandom(int[], int);

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  int data[n];

  int i;
  for(i = 0; i < n; i++)
    data[i] = -1;

  insertrandom(data, n);

  for(i = 0; i < n; i++)
    printf("%i, ", data[i]);

  printf("\n");
  return 0;
}

void insertrandom(int data[], int n)
{
  srand(time(0));

  int i = 0;
  int random = rand() % n;
  while(i < n)
  {
    while(data[random] >= 0)
      random = rand() % n;

    data[random] = i;
    i++;
  }
}

