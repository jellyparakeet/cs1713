#include <stdio.h>
#include <string.h>

int palindromelength(char *str, int i, int j);

int main(void)
{
  char buf[150];
  printf("Enter a string\n");
  fgets(buf, 150, stdin);
  buf[strcspn(buf, "\n")] = 0;

  int len = strlen(buf);
  int i, j, max_i = 0;
  int max_len = 0;
  int temp = 0;
  for(i = 0; i < len; i++)
  {
    for(j = i + 1; j < len; j++)
    {
      if(buf[i] == buf[j])
        temp = palindromelength(buf, i, j);

      if(temp > max_len)
      {
        max_len = temp;
        max_i = i;
      }
    }
  }
  char *palptr = buf + max_i;
  char max_pal[150];
  strncpy(max_pal, palptr, max_len);

  printf("Largest palindrome is %s\n", max_pal);
  return 0;
}

int palindromelength(char *str, int i, int j)
{
  int is_palindrome = 1;
  char *ptr1 = str + i;
  char *ptr2 = str + j;
  while(ptr1 <= ptr2)
  {
    if(*ptr1 != *ptr2)
    {
      is_palindrome = -1;
      break;
    }
    ptr1++;
    ptr2--;
  }

  if(is_palindrome != -1)
    is_palindrome = j - i + 1;

  return is_palindrome;
}
