#include <stdio.h>

double fibonacci(int);

int main(void)
{
  int num = 0;
  while(1)
  {
    scanf("%i", &num);
    if(num == -1)
      break;

    printf("%i %.6f\n", num, fibonacci(num));
  }

  return 0;
}

double fibonacci(int n)
{
  double fibs[n + 1];
  fibs[0] = 1;
  fibs[1] = 1;

  int i;
  for(i = 2; i <= n; i++)
    fibs[i] = fibs[i - 1] + fibs[i - 2];

  return fibs[n];
}

