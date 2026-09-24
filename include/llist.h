#ifndef LLIST
#define LLIST

#include <stdlib.h>
#include <stdbool.h>

typedef struct list list;

typedef void (*list_free_function)(void *data);
typedef bool (*list_compare_function)(const void *a, const void *b);

list* list_create(list_free_function free_f);

bool list_append(list *l, void *value);

bool list_remove(list *l, const void *value, list_compare_function cmp_f);

size_t size(const list *l);

void  list_destroy(list *l);








#endif