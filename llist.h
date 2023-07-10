#ifndef LLIST_H
#define LLIST_H


struct Node 
{
  int value;
  struct Node* next;
};

struct List 
{
  struct Node* first;
};

void push(struct List* list, int value);
void pop(struct List* list, int depth);
void freeList(struct List* list);
void iter(struct List* list);


#endif /* LLIST_H */



