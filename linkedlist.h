#ifndef LIST_H
#define LIST_H

#define NULL ((void*) 0)

typedef struct ListNode {
  int value;
  struct ListNode* next;
} ListNode;

typedef struct List {
  ListNode* head;
  int size;
} List;

List* list_init ();
void  list_delete (List* lst);
void  list_insertAfter (List* lst, ListNode* prev_node, int value);
void  list_push (List* lst, int value);
int   list_pop (List* lst);
int   list_size (List* lst);
void  list_print (List* lst);

#endif
