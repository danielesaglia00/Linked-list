#include "../include/stack.h"


typedef list stack;

stack* stack_create(){  
    stack *s = list_create(NULL);

    return s;
}

size_t stack_size(stack *s){
    return list_size(s);
}

bool stack_push(stack *s, void* value){
    return list_append_on_head(s, value);
}

void* stack_pop(stack *s){
    return list_get_head(s);
}