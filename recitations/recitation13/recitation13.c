#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node Node;

Node *insertHead(Node *head, int data);
Node *middleNode(Node *head);
int listLen(Node *head);
void freeList(Node *head);
void printList(Node *head);

int main(void)
{
  Node *head = NULL;
  head = insertHead(head, 24);
  head = insertHead(head, 21);
  head = insertHead(head, 18);
  head = insertHead(head, 12);
  head = insertHead(head, 6);
  head = insertHead(head, 5);
  printList(head);

  Node *mid = middleNode(head);
  printf("%d\n", mid->data);

  freeList(head);

  return 0;
}

Node *insertHead(Node *head, int data)
{
  Node *new = (Node *)malloc(sizeof(Node));
  new->data = data;
  new->next = head;
  return new;
}

Node *middleNode(Node *head)
{
  Node *ptr = head;
  int len = listLen(head);
  int index = (int)(len / 2) + 1;
  for (int i = 1; i < index; i++)
    ptr = ptr->next;

  return ptr;
}

int listLen(Node *head)
{
  Node *ptr = head;
  int count = 0;
  while (ptr != NULL)
  {
    count++;
    ptr = ptr->next;
  }

  return count;
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

