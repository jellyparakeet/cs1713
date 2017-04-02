#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double factorial(int);
double exponent(double, int);

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    printf("Usage: %s n x\n", argv[0]);
    return 1;
  }
  int n = atoi(argv[1]);
  double x = atof(argv[2]);

  printf("%13s", "i");
  printf("%17s\n", "Approximation");
  printf("----------------------------------\n");
  for(int i = 0; i <= n; i++)
  {
    printf("%13d", i);
    printf("%17.10f\n", exponent(x, i));
  }

  printf("Exact Value =%17.10f\n", exp(x));

  return 0;
}

double factorial(int n)
{
  if(n <= 1)
    return 1.0;

  double fact = (double) n;

  while(--n)
    fact *= n;

  return fact;
}

double exponent(double x, int n)
{
  double approx = 0.0;
  double num;
  double den;

  for(int i = 0; i <= n; i++)
  {
    num = pow(x, i);
    den = factorial(i);
    approx += num / den;
  }

  return approx;
}

