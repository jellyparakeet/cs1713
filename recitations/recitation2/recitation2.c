#include <stdio.h>

int main(void)
{
  int per;
  printf("Enter perimeter\n");
  scanf("%i", &per);

  printf("Triangles with perimeter %i\n", per);
  int a = 1, b = 1, c = 1;
  int a_max = per / 3;
  int c_max = per / 2;
  
  for(a = 1; a <= a_max; a++)
  {
    for(b = 1; b <= c; b++)
    {
      for(c = 1; c <= c_max; c++)
      {
        if(a + b > c && c >= b && b >= a && a + b + c == per)
          printf("%i %i %i\n", a, b, c);
      }
    }
  }
  printf("\n");

  return 0;
}
