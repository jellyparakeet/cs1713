#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *delete(Node *head, int k);
void freeList(Node *head);
Node *insertHead(Node *head, int data);
void printList(Node *head);
Node *recursivedelete(Node *head, int k);

int main(void)
{
  int i;
  Node *head = NULL;
  for (i = MAX_SIZE; i > 0; i--)
    head = insertHead(head, i);

  printList(head);
  printf("Delete 5\n");
  head = delete(head, 5);
  printList(head);
  printf("Recursive delete 7\n");
  head = recursivedelete(head, 7);
  printList(head);

  freeList(head);

  return 0;
}

Node *delete(Node *head, int k)
{
  Node *ptr = head;
  Node *prev;

  while (ptr != NULL && ptr->data != k)
  {
    prev = ptr;
    ptr = ptr->next;
  }

  if (ptr != NULL)
  {
    prev->next = ptr->next;
    free(ptr);
  }

  return head;
}

void freeList(Node *head)
{
  Node *ptr = head;
  while (head != NULL)
  {
    head = head->next;
    free(ptr);
    ptr = head;
  }
}

Node *insertHead(Node *head, int data)
{
  Node *ptr = head;
  Node *new = (Node *)malloc(sizeof(Node));
  new->data = data;
  new->next = NULL;

  if (ptr == NULL)
  {
    ptr = new;
  }
  else
  {
    new->next = ptr;
    ptr = new;
  }

  return ptr;
}

void printList(Node *head)
{
  Node *ptr = head;
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

Node *recursivedelete(Node *head, int k)
{
  if (head == NULL)
    return head;

  if (head->data == k)
  {
    Node *temp = head->next;
    free(head);
    return temp;
  }

  head->next = recursivedelete(head->next, k);

  return head;
}

