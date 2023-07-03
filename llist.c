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

void pop(struct List* list, int depth)
{
  // Initialize first node 
  // Choose correct operation 
  struct Node* node = list->first;
  if (depth == 0) 
  {
    // Replace previous first with next
    // Free previously stored first node 
    list->first = node->next;
    free(node);
    return;
  }
  else 
  {
    // Iterate to depth - 1
    // Replace previous node with next node
    // Replace current next with next of next  
    // Free next 
    for (int index = 0; index < depth - 1; index++)
    {
      node = node->next;
    }
    struct Node* to_be_popped = node->next;
    node->next = to_be_popped->next;
    free(to_be_popped);
  }
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
  pop(list, 2);
  pop(list, 0);

  // Push more values 
  push(list, 3);
  push(list, 9);

  // Check results 
  iter(list);

  free(list);
  return 0;
}




