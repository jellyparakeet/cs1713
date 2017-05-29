#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *delete_multiples(Node *head, int k);
void free_list(Node *head);
Node *insert_head(Node *head, int data);
void print_list(Node *head);

int main(void)
{
  int i;
  Node *head = NULL;
  for (i = MAX_SIZE; i >= 2; i--)
    head = insert_head(head, i);

  Node *ptr = head;
  int hibound = (int)floor(sqrt(MAX_SIZE));
  while (ptr->data <= hibound)
  {
    int mult = ptr->data;
    ptr = ptr->next;
    ptr = delete_multiples(ptr, mult);
  }

  print_list(head);
  free_list(head);

  return 0;
}

Node *delete_multiples(Node *head, int k)
{
  Node *ptr = head->next;
  Node *prev = head;

  while (ptr != NULL)
  {
    if (ptr->data % k == 0)
    {
      prev->next = prev->next->next;
      free(ptr);
      ptr = prev->next;
    }
    else
    {
      prev = prev->next;
      ptr = ptr->next;
    }
  }
  return head;
}

void free_list(Node *head)
{
  Node *ptr = head;
  while (head != NULL)
  {
    head = head->next;
    free(ptr);
    ptr = head;
  }
}

Node *insert_head(Node *head, int data)
{
  Node *new = (Node *)malloc(sizeof(Node));
  new->data = data;
  new->next = head;

  return new;
}

void print_list(Node *head)
{
  while (head != NULL)
  {
    printf("%d\n", head->data);
    head = head->next;
  }
}

