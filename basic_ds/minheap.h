#ifndef _MINHEAP_H
#define _MINHEAP_H

typedef int key_type;
typedef struct _minheap* minheap;

minheap minheap_create();
minheap minheap_heapify(const key_type* array, int n);

static void minheap_double_capacity(minheap);
static void minheap_fixdown(minheap, int);

void minheap_destroy(minheap);

int minheap_findmin(minheap);
void minheap_insert(minheap, key_type);
void minheap_deletemin(minheap);

int minheap_is_empty(minheap);
int minheap_size(minheap);
void minheap_clear(minheap);

void minheap_swap(minheap, int, int);


#endif