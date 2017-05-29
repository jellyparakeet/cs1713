#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void find_max_intv(int *nums[], int interval);

int main(void)
{
  int i;
  int interval;
  printf("Enter interval: ");
  scanf("%d", &interval);
  int *info[MAX_SIZE];
  for(i = 0; i < MAX_SIZE; i++)
  {
    info[i] = (int *)malloc(sizeof(int));
    *info[i] = rand() % 1000;
  }

  find_max_intv(info, interval);

  for(i = 0; i < MAX_SIZE; i++)
    free(info[i]);

  return 0;
}

void find_max_intv(int *nums[], int interval)
{
  int i, j, lobound, hibound;
  int count, maxelem, maxcount = 0;

  for(i = 0; i < MAX_SIZE; i++)
  {
    count = 0;
    lobound = *nums[i];
    hibound = lobound + interval;

    for(j = 0; j < MAX_SIZE; j++)
      if(*nums[j] >= lobound && *nums[j] <= hibound)
        count++;

    if(count > maxcount)
    {
      maxcount = count;
      maxelem = lobound;
    }
  }

  printf("Interval of [%d, %d] contains maximum number of %d elements\n", maxelem, maxelem + interval, maxcount);
}

