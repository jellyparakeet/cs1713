#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

void display_words(char *str, char c);
void search_print(char *str, char c, int i, int j);

int main(void)
{
  char buf[MAX_SIZE];
  char c;
  printf("Enter a sentence\n");
  fgets(buf, MAX_SIZE, stdin);
  buf[strcspn(buf, "\n")] = 0;
  printf("Enter a character\n");
  scanf("%c", &c);

  display_words(buf, c);

  return 0;
}

void display_words(char *str, char c)
{
  printf("Words containing %c are:\n", c);
  int temp = 0;
  int start = 0;
  while(*(str + temp))
  {
    temp++;
    if(*(str + temp) == '\0')
      search_print(str, c, start, temp - 1);
    else if(*(str + temp) == ' ')
    {
      search_print(str, c, start, temp - 1);
      start = temp + 1;
    }
  }
}

void search_print(char *str, char c, int i, int j)
{
  int found = 0;
  int start = i;
  while(start <= j)
  {
    if(tolower(*(str + start)) == tolower(c))
    {
      found = 1;
      break;
    }
    start++;
  }

  if(found)
  {
    while(i <= j)
    {
      printf("%c", *(str + i));
      i++;
    }
    printf("\n");
  }
}

