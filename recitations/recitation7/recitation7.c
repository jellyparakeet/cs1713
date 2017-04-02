#include <stdio.h>
#include <string.h>

void rev_string(char *str);
void reverse(char *str, int i, int j);

int main(void)
{
  char buf[100];
  printf("Enter a string:\n");
  fgets(buf, 100, stdin);
  buf[strcspn(buf, "\n")] = 0;

  rev_string(buf);

  printf("Reversed string:\n");
  printf("%s\n", buf);

  return 0;
}

void rev_string(char *str)
{
  int temp = 0;
  int start = 0;
  while(*(str + temp))
  {
    temp++;
    if(*(str + temp) == '\0')
      reverse(str, start, temp - 1);
    else if(*(str + temp) == ' ')
    {
      reverse(str, start, temp - 1);
      start = temp + 1;
    }
  }
}

void reverse(char *str, int i, int j)
{
  char temp;
  while(i < j)
  {
    temp = *(str + i);
    *(str + i) = *(str + j);
    *(str + j) = temp;
    i++;
    j--;
  }
}
