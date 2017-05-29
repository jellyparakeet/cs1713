#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

int findKthNode(Node *head, int k);
void freeList(Node *head);
Node *insertHead(Node *head, int data);
int recursiveFindKthNode(Node *head, int k);

int main(void)
{
  srand(time(NULL));
  Node *head = NULL;
  for (int i = 0; i < 10; i++)
  {
    head = insertHead(head, rand() % 100);
  }

  int data = findKthNode(head, 0);
  printf("0th findKthNode = %d\n", data);
  data = recursiveFindKthNode(head, 0);
  printf("0th recursiveFindKthNode = %d\n", data);
  data = findKthNode(head, 9);
  printf("9th findKthNode = %d\n", data);
  data = recursiveFindKthNode(head, 9);
  printf("9th recursiveFindKthNode = %d\n", data);
  data = findKthNode(head, 10);
  printf("10th findKthNode = %d\n", data);
  data = recursiveFindKthNode(head, 10);
  printf("10th recursiveFindKthNode = %d\n", data);

  freeList(head);

  return 0;
}

int findKthNode(Node *head, int k)
{
  if (head == NULL)
    return -1;

  int i;
  Node *ptr = head;

  for (i = 0; i < k && ptr != NULL; i++)
    ptr = ptr->next;

  if (ptr == NULL)
    return -1;

  return ptr->data;
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

int recursiveFindKthNode(Node *head, int k)
{
  if (head == NULL)
    return -1;

  if (k == 0)
    return head->data;
  else
    return recursiveFindKthNode(head->next, k - 1);
}

