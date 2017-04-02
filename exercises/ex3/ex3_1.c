#include <stdio.h>

int main(void)
{
  FILE *file = fopen("data.txt", "r");
  if(file == NULL)
  {
    fprintf(stderr, "Error: file unavailable.\n");
    fclose(file);
    return 1;
  }

  int n, num;
  int max1 = -1;
  int max2 = -1;
  n = fscanf(file, "%i", &num);
  if(n == EOF)
  {
    fprintf(stderr, "Error: file is empty.\n");
    fclose(file);
    return 1;
  }
  max1 = num;

  n = fscanf(file, "%i", &num);
  if(n == EOF)
  {
    printf("Only 1 integer: %i\n", max1);
    fclose(file);
    return 0;
  }

  while(n != EOF)
  {
    if(num > max1)
    {
      max2 = max1;
      max1 = num;
    }
    else if(num > max2)
      max2 = num;
    n = fscanf(file, "%i", &num);
  }
  fclose(file);
  printf("Second largest number: %i\n", max2);

  return 0;
}
