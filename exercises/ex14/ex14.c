#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node Node;

Node *insertHead(Node *head, int data);
int listLen(Node *head);
void freeList(Node *head);
void printList(Node *head);
int sumEqualsK(Node *head, int k);

int main(void)
{
  Node *head = NULL;
  head = insertHead(head, 21);
  head = insertHead(head, 18);
  head = insertHead(head, 12);
  head = insertHead(head, 6);
  head = insertHead(head, 5);
  if (sumEqualsK(head, 33))
    printf("Found sum!\n");

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

int sumEqualsK(Node *head, int k)
{
  if (head == NULL)
    return 0;

  Node *first = head;
  Node *second = head;
  while (first->next != NULL)
  {
    second = first->next;
    while (second != NULL)
    {
      if (first->data + second->data == k)
      {
        printf("%d + %d = %d\n", first->data, second->data, k);
        return 1;
      }

      second = second->next;
    }
    first = first->next;
  }

  return 0;
}

