#include "../include/llist.h"

typedef struct node node;

struct node{
    void *value;
    
    node *next;
    node *prev;
};


struct list{    
    node* head;
    node* tail;

    size_t size;
    list_free_function free_f;
};

list* create_list(list_free_function free_f){
    list *l = malloc(sizeof(list));

    if(l == NULL) 
        return NULL;

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    l->free_f = free_f;

    return l;
}

bool append_list(list *l, void *value){
    node *n = malloc(sizeof(node));

    if(n == NULL)
        return false;
    
    n->value = value;
    n->next = NULL;
    n->prev = l->tail;

    if(l->size == 0)
        l->head = n;
    else
        l->tail->next = n;

    l->tail = n;
    l->size++;

    return true;
}


size_t size(const list *l){
    if(l == NULL)
        return 0;
    else
        return l->size;
}

bool list_remove(list *l, const void *value, list_compare_function cmp_f){
    node *n = l->head;

    while (n != NULL){
        if(cmp_f(value, n->value)){
            if(n->next != NULL)
                n->next->prev = n->prev;
            else
                l->tail = n->prev;

            if(n->prev != NULL)
                n->prev->next = n->next;
            else
                l->head = n->next;
            l->size--;
            return true;
        }
    }

    return false;
}

void list_destroy(list *l){
    node *n = l->head;

    while(n != NULL){
        l->free_f(n->value);
        node *next = n->next;
        n = next;
        free(n);
    }

    free(l);
}