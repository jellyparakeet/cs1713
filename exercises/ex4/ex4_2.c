#include <stdio.h>

int mystery(int, int);

int main(void)
{
  int a, b;
  printf("Enter 2 numbers (a b): ");
  scanf("%i %i", &a, &b);

  int result = mystery(a, b);

  printf("a * b = %i\n", result);
  return 0;
}

int mystery(int a, int b)
{
  if(b == 1)
    return a;

  return a + mystery(a, b - 1);
}
