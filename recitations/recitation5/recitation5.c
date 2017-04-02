#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int num = 0;
  int arr[50];
  int pair[2];
  int len = 0;

  while(1)
  {
    scanf("%i", &num);
    if(num == -1)
      break;

    arr[len] = num;
    len++;
  }

  int i, j, temp = 0, diff = 1000000;
  pair[0] = 0;
  pair[1] = 0;

  for(i = 0; i < (len - 1); i++)
  {
    for(j = i + 1; j < len; j++)
    {
      temp = abs(arr[i] - arr[j]);
      if(temp < diff)
      {
        diff = temp;
        pair[0] = arr[i];
        pair[1] = arr[j];
      }
    }
  }

  printf("Closest pair: %i and %i, Difference: %i\n", pair[0], pair[1], diff);

  return 0;
}
