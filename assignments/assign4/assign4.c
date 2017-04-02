#include <stdio.h>
#include <stdlib.h>

void find_largest_k(FILE *, int, int[]);

int main(int argc, char *argv[])
{
  /*
   * Check for proper arguments
   */
  if(argc != 3)
  {
    printf("Usage: ./assign4 FILE k\n");
    return 0;
  }

  /*
   * Get arguments and check file opened successfully
   */
  int k = atoi(argv[2]);
  FILE *file = fopen(argv[1], "r");
  if(file == NULL)
  {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }

  /*
   * Declare and initialize array of length k to 0's
   */
  int arr[k];
  int i;
  for(i = 0; i < k; i++)
    arr[i] = 0;

  find_largest_k(file, k, arr);

  for(int i = 0; i < k; i++)
    printf("%i ", arr[i]);

  printf("\n");

  fclose(file);

  return 0;
}

void find_largest_k(FILE *file, int size, int arr[])
{
  int current;

  while(feof(file) <= 0)
  {
    int i = size - 2; /* Because there is a check for size - 1 already */
    fscanf(file, "%i", &current);

    if(arr[i + 1] < current)
    {
      while(i >= 0 && arr[i] <= current)
      {
        arr[i + 1] = arr[i];
        i--;
      }
      arr[i + 1] = current;
    }
  }
}
