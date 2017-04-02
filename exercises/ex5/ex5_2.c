#include <stdio.h>
#include <stdlib.h>

int issorted(int[], int);

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    return 1;
  }
  int n = atoi(argv[1]);
  int data[n];

  int el;
  int i;
  for(i = 0; i < n; i++)
  {
    printf("Enter element [%i]: ", i);
    scanf("%i", &el);
    data[i] = el;
  }
  printf("\n");

  printf("array = {");
  for(i = 0; i < n; i++)
  {
    if(i < n - 1)
      printf("%i, ", data[i]);
    else
      printf("%i", data[i]);
  }
  printf("}\n");

  int is_sorted = issorted(data, n);
  if(is_sorted)
    printf("This array is sorted\n");
  else
    printf("This array is not sorted\n");

  return 0;
}

int issorted(int data[], int n)
{
  if(n <= 1)
    return 1;

  int is_sorted = 1;
  int i = 1;
  int prev; 
  int curr;

  while(i < n && is_sorted)
  {
    prev = data[i - 1];
    curr = data[i];

    if(curr < prev)
      is_sorted = 0;

    i++;
  }
  return is_sorted;
}

