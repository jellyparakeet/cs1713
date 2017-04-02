#include <stdio.h>

int power(int, int);

int main(void)
{
  int a, b;
  printf("Enter two numbers to compute(a b): ");
  scanf("%i %i", &a, &b);

  int result = power(a, b);

  printf("a ^ b = %i\n", result);
  return 0;
}

int power(int a, int b)
{
  if(b == 0)
    return 1;

  return a * power(a, b - 1);
}
