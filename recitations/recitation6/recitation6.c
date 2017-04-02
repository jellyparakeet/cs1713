#include <stdio.h>

int issumof2(int[], int, int);
int inarray(int[], int, int);

int main(void)
{
  int arr[7];
  int i;

  printf("Enter 7 numbers\n");

  for(i = 0; i < 7; i++)
    scanf("%i", &arr[i]);

  int start_num = 1;
  while(1)
  {
    if(!issumof2(arr, 7, start_num))
      if(!inarray(arr, 7, start_num))
        break;

    start_num++;
  }

  printf("Smallest positive Integer = %i\n", start_num);

  return 0;
}

int issumof2(int data[], int size, int number)
{
  int i, j;

  for(i = 0; i < size - 1; i++)
  {
    if(data[i] + data[i] == number)
      return 1;

    for(j = i + 1; j < size; j++)
    {
      if(data[i] + data[j] == number)
        return 1;
    }
  }

  // Check if final element (data[size - 1]) + itself is equal to number
  if(data[i] + data[i] == number)
    return 1;

  return 0;
}

int inarray(int data[], int size, int number)
{
  int i;

  for(i = 0; i < size; i++)
    if(data[i] == number)
      return 1;

  return 0;
}
