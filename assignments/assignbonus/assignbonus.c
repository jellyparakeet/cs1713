#include <stdio.h>
#include <math.h>
int main()
{
  int i, n, sum;
  float sum2;
  printf("Enter n:\n");
  scanf("%d",&n);
  sum = 0;
  for(i=1; i<=n; i++)
    sum += i*i*i;
  printf("For Loop\n  Loop Result = %d\n  Formula = %d\n",sum,n*n*(n+1)*(n+1)/4);
  sum2 = 0;
  i = 1;
  while(i<=n)
  {
    sum2 += 1.0/(pow(2.0,i));
    i++;
  }
  printf("While Loop\n  Loop Result = %f\n  Formula = %f\n",sum2,1-1.0/pow(2,n));
  sum = 0;
  i = 1;
  do
  {
    sum += i*(i+1);
    i++;
  }while (i<=n);
  printf("Do while Loop\n  Loop Result = %d\n  Formula = %d\n",sum,n*(n+1)*(n+2)/3);
  return 0;   
}
