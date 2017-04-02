#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse(char *);
int palindrome(char *);
int get_len(char *);

int main(void)
{
  char buf[100];
  printf("Enter a string: ");
  fgets(buf, 100, stdin);
  buf[strcspn(buf, "\n")] = 0;

  if(palindrome(buf) == 1)
    printf("%s is a palindrome\n", buf);
  else
    printf("%s is not a palindrome\n", buf);

  return 0;
}

char *reverse(char *str)
{
  /* Get Length of string */
  int len = get_len(str);

  /* Allocate new string and set end */
  char *new_str = (char *)malloc(sizeof(char) * (len + 1));
  new_str[len] = '\0';

  /* Copy chars in reverse order from str to new_str */
  int i;
  int j = 0;
  for(i = len - 1; i >= 0; i--)
    new_str[j++] = str[i];

  return new_str;
}

int palindrome(char *str)
{
  /* Get Length of string */
  int len = get_len(str);
  /* Create reverse of str */
  char *rev = reverse(str);

  /* Compare letters of the reverse and str return false if not equal */
  int i;
  for(i = 0; i < len; i++)
    if(str[i] != rev[i])
    {
      free(rev);
      return 0;
    }

  free(rev);
  return 1;
}

int get_len(char *str)
{
  int len = 0;
  char *ptr = str;
  while(*ptr != '\0')
  {
    ptr++;
    len++;
  }

  return len;
}
