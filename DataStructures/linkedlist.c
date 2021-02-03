#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

//int main()
//{
//  List* lst = list_init ();
//  list_push (lst, 0);
//  list_push (lst, 1);
//  list_push (lst, 2);
//  list_push (lst, 3);
//  list_push (lst, 4);
//  list_push (lst, 5);
//  list_push (lst, 6);
//  list_print (lst);
//  for (int i = 0; i < 10; i++) {
//    int x = list_pop (lst);
//    printf ("%d\n", x);
//    list_print (lst);
//  }
//  return 0;
//}

/*
 * Allocates memory space for a new linked list and returns a ptr to this memory
 */
List* list_init ()
{
  List* ret = malloc(sizeof(List));
  ret->head = NULL;
  ret->size = 0;
  return ret;
}

void list_delete (List* lst)
{
  ListNode* tmp1 = lst->head;
  ListNode* tmp2 = lst->head;
  while (tmp1)
  {
    tmp2 = tmp1;
    tmp1 = tmp1->next;
    free (tmp2);
  }
  free (lst);
}

/*
 * insert value after the given prev_node
 */
void list_insertAfter (List* lst, ListNode* prev_node, int value)
{
  ListNode* new_node = malloc(sizeof(ListNode));
  new_node->value = value;
  new_node->next = prev_node->next;
  prev_node = new_node;
  lst->size++;
}

/*
 * Pushes a new ListNode with the given value at the front of the given LinkedList.
 */
void list_push (List* lst, int value)
{
  lst->size++;
  ListNode* new_head = malloc(sizeof(ListNode));
  new_head->value = value;
  new_head->next = lst->head;
  lst->head = new_head;
}

/*
 * Pops the frontmost ListNode in the Linkedlist
 * returns -1 if it fails
 */
int list_pop (List* lst)
{
  int ret = -1;
  if (lst->size)
  {
    lst->size--;
    ret = lst->head->value;
    ListNode* tmp = lst->head;
    lst->head = lst->head->next;
    free (tmp);
  }
  return ret;
}

/*
 * returns the size of the list
 */
int list_size (List* lst)
{
  return lst->size;
}

/*
 * print the contents of the list
 */
void list_print (List* lst)
{
  ListNode* curr = lst->head;
  while (curr)
  {
    printf ("[%d] -> ", curr->value);
    curr = curr->next;
  }
  printf ("[NULL]\n");
}
