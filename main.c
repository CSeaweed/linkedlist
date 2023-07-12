#include <stdio.h>
#include <stdlib.h>
#include "llist.h"


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
  
  reverse(list);

  iter(list);

  freeList(list);
  
  return 0;
}




