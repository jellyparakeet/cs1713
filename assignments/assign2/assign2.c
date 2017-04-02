#include <stdio.h>

int main(void)
{
  int i;
  for(i = 1; i <= 1000; i++)
  {
    int num = i;
    printf("%i ", i);

    while(num != 0)
    {
      if(num >= 1000)
      {
        printf("M");
        num -= 1000;
      }
      else if(num >= 500)
      {
        if(num >= 900)
        {
          printf("CM");
          num -= 900;
        }
        else
        {
          printf("D");
          num -= 500;
        }
      }
      else if(num >= 100)
      {
        if(num >= 400)
        {
          printf("CD");
          num -= 400;
        }
        else
        {
          printf("C");
          num -= 100;
        }
      }
      else if(num >= 50)
      {
        if(num >= 90)
        {
          printf("XC");
          num -= 90;
        }
        else
        {
          printf("L");
          num -= 50;
        }
      }
      else if(num >= 10)
      {
        if(num >= 40)
        {
          printf("XL");
          num -= 40;
        }
        else
        {
          printf("X");
          num -= 10;
        }
      }
      else if(num >= 5)
      {
        if(num >= 9)
        {
          printf("IX");
          num -= 9;
        }
        else
        {
          printf("V");
          num -= 5;
        }
      }
      else if(num >= 1)
      {
        if(num >= 4)
        {
          printf("IV");
          num -= 4;
        }
        else
        {
          printf("I");
          num--;
        }
      }
    }
    printf("\n");
  }

  return 0;
}
