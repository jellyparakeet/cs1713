#include <stdio.h>

void precomputesummation(int[], int);
int findsummation(int[], int, int, int);

int main(void)
{
  int n, a, b;

  printf("Enter (n): ");
  scanf("%i", &n);

  int data[n + 1];
  precomputesummation(data, n);

  while(1)
  {
    printf("Enter (a b) or -1 to quit: ");
    scanf("%i %i", &a, &b);

    if(a == -1 || b == -1)
      break;

    int sum = findsummation(data, n, a, b);
    printf("Sum from %i to %i = %i\n", a, b, sum);
  }

  return 0;
}

void precomputesummation(int data[], int n)
{
  int i;
  data[0] = 0;
  
  for(i = 1; i <= n; i++)
  {
    data[i] = i + data[i - 1];
  }
}

int findsummation(int data[], int n, int a, int b)
{
  int sum = -1;

  if(b <= n)
    sum = data[b] - data[a - 1];

  return sum;
}
