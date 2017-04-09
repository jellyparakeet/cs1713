#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
  int count;
  char *word;
} wordfreq;

void gen_freq(FILE *infile, FILE *outfie);
void add_word(wordfreq *words[], char *word, int *pos);

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    fprintf(stderr, "Usage: %s [infile] [outfile]\n", argv[0]);
    exit(1);
  }

  FILE *infile = fopen(argv[1], "r");
  if(infile == NULL)
  {
    fprintf(stderr, "Error opening file %s\n", argv[1]);
    exit(1);
  }

  FILE *outfile = fopen(argv[2], "wb");
  if(outfile == NULL)
  {
    fprintf(stderr, "Error opening file %s\n", argv[2]);
    exit(1);
  }

  gen_freq(infile, outfile);

  fclose(infile);
  fclose(outfile);

  return 0;
}

void gen_freq(FILE *infile, FILE *outfile)
{
  /* Index of words array */
  int count = 0;
  int i;
  char buf[100];
  char c;
  /* Initialize array of MAX_SIZE wordfreq pointers to NULL */
  wordfreq *words[MAX_SIZE];
  for(i = 0; i < MAX_SIZE; i++)
    words[i] = NULL;

  i = 0;
  while((c = fgetc(infile)) != EOF)
  {
    if(c != '\n')
      buf[i++] = c;
    /* End of word so null-terminate then add to words array */
    else
    {
      buf[i] = '\0';
      i = 0;
      add_word(words, buf, &count);
    }
  }

  /* Output words and frequencies then free the word, then the struct */
  for(i = 0; i < count; i++)
  {
    fprintf(outfile, "%d %s\n", words[i]->count, words[i]->word);
    free(words[i]->word);
    free(words[i]);
  }
}

void add_word(wordfreq *words[], char *word, int *pos)
{
  int i;
  int found = 0;
  /* Check if word is in array */
  for(i = 0; i < *pos && !found; i++)
    if(strcmp(word, words[i]->word) == 0)
      found = 1;

  /* If word was found just increment its count */
  if(found)
    words[i - 1]->count++;
  /* If word not found allocate struct and word itself setting count to 1 */
  else
  {
    int len = strlen(word);
    words[*pos] = (wordfreq *)malloc(sizeof(wordfreq));
    words[*pos]->count = 1;
    words[*pos]->word = (char *)calloc(len + 1, sizeof(char));

    for(i = 0; i < len; i++)
      words[*pos]->word[i] = word[i];

    words[*pos]->word[len] = '\0';
    /* Increment position of index in words array */
    (*pos)++;
  }
}

