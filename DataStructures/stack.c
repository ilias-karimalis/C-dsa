#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main ()
{
  return 0;
}

/*
 * Allocates memory for a new stack and returns a ptr to this memory
 */
Stack* stack_init ()
{
  return list_init();
}

/*
 * Deallocates all the memory allocated to the stack and all of its nodes
 */
void stack_delete (Stack* stack)
{
  list_delete (stack);
}

/*
 * Pushes a new Node onto the top of the stack
 */
void stack_push (Stack* stack, int value)
{
  list_push (stack, value);
}

/*
 * Pops the frontmost Node in the stack returning it's contained value
 * returns -1 if it fails
 */
int stack_pop (Stack* stack)
{
  return list_pop (stack);
}

/*
 * Returns the value contained in the topmost node in the stack
 * if stack is empty returns -1
 */
int stack_top (Stack* stack)
{
  int ret = -1;
  if (stack->size) {
    ret = stack->head->value;
  }
  return ret;
}

/*
 * return 1 if stack is empty 0 otherwise
 */
int stack_isEmpty (Stack* stack)
{
  int ret = 0;
  if (stack->size) {
    ret = 1;
  }
  return ret;
}
