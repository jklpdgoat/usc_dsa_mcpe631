#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "minheap.h"

int main() {
    int i;

    srand(time(NULL));

    minheap h = minheap_create();

    for(i = 0; i < 100; i++)
        minheap_insert(h, rand() % 1000);

    while (!minheap_is_empty(h)) {
        printf("%4d", minheap_findmin(h));
        minheap_deletemin(h);
    }

    minheap_destroy(h);

    return 0;
}