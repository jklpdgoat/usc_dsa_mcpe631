#ifndef QUEUES_H
#define QUEUES_H

#include "customer.h"
#include <string.h>

// int TreeHeight[50];
// int TreeSize = -1; // or NULL, no elements yet
extern int TreeHeight[];
extern int TreeSize;

// typedef struct __RegularLaneQueue* RegularLaneQueue;
typedef struct __PriorityLaneQueue* PriorityLaneQueue;
typedef int key_type;

typedef struct {
    int size;
    RegularCustomer *front, *rear;
} RegularLaneQueue;

// typedef struct {
//     int size;
//     int priority;
//     SpecialCustomer *first_node, *last_node;
// } PriorityLaneQueue;

struct __PriorityLaneQueue {
    key_type* array;
    int max_size;
    int cur_size;
    int priority;
    SpecialCustomer *first_node, *last_node;
};

/*
 * Regular Lane Functions
 * 
 */
RegularCustomer *newCustomerRegular(int);
RegularCustomer *deQueue(RegularLaneQueue *);
RegularLaneQueue *createQueue();
void enQueue(RegularLaneQueue *, int);
void list(RegularLaneQueue *q);

/*
 * Special Lane Functions
 * 
 */

PriorityLaneQueue minheapCreate();
PriorityLaneQueue minheapHeapify(const key_type* array, int n);

static void minheapDoubleCapacity(PriorityLaneQueue);
static void minheapFixdown(PriorityLaneQueue, int);

void minheapDestroy(PriorityLaneQueue);

int minheapFindmin(PriorityLaneQueue);
void minheapInsert(PriorityLaneQueue, key_type);
void minheapDeleteMin(PriorityLaneQueue);

int minheapisEmpty(PriorityLaneQueue);
int minheapSize(PriorityLaneQueue);
void minheapClear(PriorityLaneQueue);

void minheapSwap(PriorityLaneQueue, int, int);

// int parent(int);
// int leftChild(int);
// int rightChild(int);
// void shiftUp(int);
// void shiftDown(int);
// void insertNode(int);
// int extractMax();
// void changePriority(int, int);
// int getMax();
// void removeNode(int);

#endif