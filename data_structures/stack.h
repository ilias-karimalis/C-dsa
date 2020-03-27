#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"

typedef List Stack;

Stack* stack_init ();
void stack_delete (Stack* stack);
void stack_push (Stack* stack, int value);
int stack_pop (Stack* stack);
int stack_top (Stack* stack);
int stack_isEmpty (Stack* stack);

#endif
