#ifndef STACK
#define STACK
#include "../include/llist.h"

typedef list stack;

stack* stack_create();

size_t stack_size(stack* s);

bool stack_push(stack *s, void* value);

void* stack_pop(stack *s);

#endif