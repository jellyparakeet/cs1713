#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void insertionSort(int *info[], int n);
void printList(int *info[], int n);

int main(void)
{
  int i;
  int *info[MAX_SIZE];
  for (i = 0; i < MAX_SIZE; i++)
  {
    info[i] = (int *)malloc(sizeof(int));
    *info[i] = rand() % 100;
  }

  printf("Before:\n");
  printList(info, MAX_SIZE);

  insertionSort(info, MAX_SIZE);

  printf("After:\n");
  printList(info, MAX_SIZE);

  for (i = 0; i < MAX_SIZE; i++)
    free(info[i]);

  return 0;
}

void insertionSort(int *info[], int n)
{
  int i, j, *temp;
  for (i = 1; i < n; i++)
  {
    temp = info[i];
    j = i - 1;

    while (j >= 0 && *info[j] > *temp)
    {
      info[j + 1] = info[j];
      j--;
    }

    info[j + 1] = temp;
  }
}

void printList(int *info[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", *info[i]);

  printf("\n");
}

