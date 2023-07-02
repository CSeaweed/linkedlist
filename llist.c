#include <stdio.h>
#include <stdlib.h>


struct Node 
{
  int value;
  struct Node* next;
};

struct List 
{
  struct Node* first;
};

void push(struct List* list, int value)
{
  // Initialize new node & allocate buffer memory 
  struct Node* node = malloc(sizeof(struct Node));  
  
  // Give new node a value 
  // Make new node the first 
  // make new nodes next the previous first 
  node->value = value;
  node->next = list->first;
  list->first = node;
}

void pop(struct List* list)
{
  // Store first to a buffer
  // Change first to the node after first node 
  // Free previous first  
  struct Node* first = list->first;
  list->first = first->next;
  free(first);
}

void iter(struct List *list)
{
  // Initialize loop by storing first node into a buffer 
  struct Node* node = list->first;
  while (node != NULL)
  {
    printf("%d\n", node->value);
    node = node->next; 
  }
}

int main() 
{

  // Initialize List
  struct List* list = malloc(sizeof(struct List));
  list->first = NULL;

  // Push values  
  push(list, 5);
  push(list, 25);
  push(list, 125);

  // Pop values 
  pop(list);
  pop(list);

  // Push more values 
  push(list, 3);
  push(list, 9);

  // Check results 
  iter(list);

  free(list);
  return 0;
}




