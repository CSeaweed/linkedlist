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

void* freeNode(struct Node* node)
{
  // Recursively check if node is last 
  // If not last move to next 
  if (node->next != NULL)
  {
    node->next = freeNode(node->next);
  }
  // When node is last return free 
  // Return NULL to make previous node the last
  free(node);
  return NULL;
}

void freeList(struct List* list)
{
  // Initialize first node 
  // Free all nodes 
  // Free list
  struct Node* first = list->first;
  freeNode(first);
  free(list);
}

void reverse(struct List* list)
{
  // Initialize first and next node
  struct Node* previous = NULL;
  struct Node* node = list->first;
  struct Node* next = node->next;
  
  if (node == NULL) { return; }
  while (next != NULL)
  {
    previous = node;
    list->first = next;
    node->next = next->next;
    next->next = node;
    node = node->next;
    next = node->next;
  }
  node->next = list->first;
  list->first = node;
  previous->next = NULL;
}




