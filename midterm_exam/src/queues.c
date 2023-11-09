#include "../include/queues.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* ------------------------------------------------------------
 * Regular Lane
 * Queue Implemented using Singly Linked List
 * ------------------------------------------------------------
 */

RegularCustomer *newCustomerRegular(int pn) {
    RegularCustomer *temp = (RegularCustomer*)malloc(sizeof(RegularCustomer));
    temp->regular_pn = pn++;
    temp->next = NULL;

    return temp;
}

// A utility function to create an empty queue
RegularLaneQueue *createQueue() {
    RegularLaneQueue *q = (RegularLaneQueue*)malloc(sizeof(RegularLaneQueue));
    q->front = q->rear = NULL;
    return q;
}

// The function to add a key to q
void enQueue(RegularLaneQueue *q, int pn) {
    // Create a new LL Node
    RegularCustomer *temp = newCustomerRegular(pn);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
    q->size++;
}

// Function to rmeove a key from given queue q
RegularCustomer  *deQueue(RegularLaneQueue *q) {
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return NULL;

    // Store previous front and move front one node ahead
    RegularCustomer  *temp = q->front;
    q->front = q->front->next;

    // If front becomes NULL, the change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
    
    return temp;
}

void list(RegularLaneQueue *q) {
    RegularCustomer *temp = q->front;
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;
    // puts("\n");
    puts("Queue is:");
    do {
        printf("<-[ #: %d ]", temp->regular_pn);
        temp = temp->next;
    } while (temp != NULL);
    printf("\n");
}

int isEmpty(RegularLaneQueue *q) {
    if (q == NULL) {
        return 0;
    }
    if (q->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

void destructQueue(RegularLaneQueue *q) {
    // while (!isEmpty(q)) {
    //     free(cN);
    // }
    free(q);
}


/* ------------------------------------------------------------
 * Special Lane
 * Priority Queue Implemented using Binary Heap (Min)
 * ------------------------------------------------------------
 */

PriorityLaneQueue minheapCreate() {
	PriorityLaneQueue h = (PriorityLaneQueue) malloc(sizeof(struct __PriorityLaneQueue));
	if (h == NULL) {
		fprintf(stderr, "Not enough memory!\n");
		abort();
	}
	h->max_size = 64;
	h->cur_size = 0;
	h->array = (key_type*) malloc( \
		sizeof(key_type)*(h->max_size+1));
	if (h->array == NULL) {
		fprintf(stderr, "Not enough memory!\n");
		abort();
	}

	return h;
}

PriorityLaneQueue minheapHeapify(const key_type* array, int n) {
	assert(array && n > 0);

	PriorityLaneQueue h = (PriorityLaneQueue) malloc(sizeof(struct __PriorityLaneQueue));
	if (h == NULL) {
	fprintf(stderr, "Not enough memory!\n");
	abort();
	}

	h->max_size = n;
	h->cur_size = 0;
	h->array = (key_type*) malloc(sizeof(key_type)*(h->max_size+1));

	if (h->array == NULL) {
		fprintf(stderr, "Not enough memory!\n");
		abort();
	}

	h->cur_size = n;
	for(int k = 0; k < n; k++)
		h->array[k+1] = array[k];

	for(int k = (h->max_size+1)/2; k > 0; k--)
		minheapFixdown(h, k);

	return h;
}

static void minheapDoubleCapacity(PriorityLaneQueue h) {

	// create another array
	int new_max_size = 2 * h->max_size;
	key_type* new_array = (key_type*) malloc(sizeof(key_type)*(new_max_size+1));

	if (new_array == NULL) {
		fprintf(stderr, "Not enough memory!\n");
		abort();
	}

	/* copy old elements to new array */
	for (int i = 1; i <= h->cur_size; i++) {
		new_array[i] = h->array[i];
	}

	free(h->array);
	h->array = new_array;
	h->max_size = new_max_size;
}

static void minheapFixdown(PriorityLaneQueue h, int k) {
	assert(h);

	while (2*k <= h->cur_size) {
		int j = 2*k;
		if (j < h->cur_size && h->array[j+1] < h->array[j])
			j++;
		if (h->array[k] <= h->array[j])
			break;

		minheapSwap(h, k, j);
		k = j;
	}
}

void minheapDestroy(PriorityLaneQueue h) {
	assert(h);
	free(h->array);
	free(h);
}

int minheapFindmin(PriorityLaneQueue h) {
	if (minheapisEmpty(h)) {
		fprintf(stderr, "Heap is empty!\n");
		abort();
	}

	// min is always in first position, h[1]
	return h->array[1];
}

void minheapInsert(PriorityLaneQueue h, key_type key) {
	assert(h);

	// make sure there is space
	if (h->cur_size == h->max_size)
		minheapDoubleCapacity(h);
}

void minheapDeleteMin(PriorityLaneQueue h) {
	if (minheapisEmpty(h)) {
		fprintf(stderr, "Heap is empty!\n");
		abort();
	}

	// swap first with last
	minheapSwap(h, 1, h->cur_size);

	// delete last-
	h->cur_size--;

	// fixdown first;
	minheapFixdown(h, 1);
}

int minheapisEmpty(PriorityLaneQueue h) {
	assert(h);
	return h->cur_size <= 0;
}

int minheapSize(PriorityLaneQueue h) {
	assert(h);
	return h->cur_size;
}

void minheapClear(PriorityLaneQueue h) {
	assert(h);
	h->cur_size = 0;
}

void minheapSwap(PriorityLaneQueue h, int i, int j) {
	assert (h && i >= 1 && i <= h->cur_size
			  && j >= 1 && j <= h->cur_size);

	key_type tmp = h->array[i];
	h->array[i] = h->array[j];
	h->array[j] = tmp;
}