#include <stdio.h>

int findMajority(int[], int);

int main(void)
{
  int arr[7];
  int i;

  printf("Enter 7 numbers\n");
  for(i = 0; i < 7; i++)
    scanf("%i", &arr[i]);

  int is_majority = findMajority(arr, 7);

  if(is_majority == -1)
    printf("No Majority\n");
  else
    printf("Majority = %i\n", is_majority);

  return 0;
}

int findMajority(int array[], int n)
{
  int count = 0;
  int majority = -1;
  int curr_num = 0;
  int threshold = n / 2 + 1;
  int i = 0, j;

  while(i < n - 1)
  {
    curr_num = array[i];
    count = 1;
    for(j = i + 1; j < n; j++)
    {
      if(array[j] == curr_num)
        count++;
    }
    if(count >= threshold)
    {
      majority = curr_num;
      break;
    }
    i++;
  }
  return majority;
}
