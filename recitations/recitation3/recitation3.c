#include <stdio.h>
#include <stdlib.h>

void reverseDigits(int);
int numDigits(int);

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    printf("Usage: %s number\n", argv[0]);
    return 1;
  }

  int number = atoi(argv[1]);

  int numDig = numDigits(number);
  reverseDigits(number);
  printf("%i\n", numDig);

  return 0;
}

void reverseDigits(int num)
{
  if(num <= 0)
  {
    printf("\n");
    return;
  }

  int digit = num % 10;
  printf("%i", digit);
  reverseDigits(num / 10);
}

int numDigits(int num)
{
  if(num <= 0)
    return 0;

  return 1 + numDigits(num / 10);
}
