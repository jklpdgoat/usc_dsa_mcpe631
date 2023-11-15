#include <stdbool.h>
#include <stdio.h> // Including the standard input-output header file for functions like printf.
#include <stdlib.h> // Including the standard library header for functions like malloc and exit.
#include <string.h>

// A struct representing a customer
typedef struct {
    int priority_number;
    struct Customer *next;
} Customer;

// The queue, front stores the front node of the LL and rear stores the last
// node of LL
typedef struct {
    int size;
    Customer *front, *rear;
} RegularLaneQueue;

// A utility function to create a new linked list node.
Customer *newCustomerRegular(int);
Customer *newCustomerRegular(int priority_number) {
    Customer *temp = (Customer *)malloc(sizeof(Customer));
    temp->priority_number = priority_number++;
    temp->next = NULL;

    return temp;
}

// A utility function to create an empty queue
RegularLaneQueue *createQueue();
RegularLaneQueue *createQueue() {
    RegularLaneQueue *q = (RegularLaneQueue *)malloc(sizeof(RegularLaneQueue));
    q->front = q->rear = NULL;
    return q;
}

// The function to add a key to q
void enQueue(RegularLaneQueue *, int);
void enQueue(RegularLaneQueue *q, int priority_number) {
    // Create a new LL Node
    Customer *temp = newCustomerRegular(priority_number);

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
Customer *deQueue(RegularLaneQueue *);
Customer *deQueue(RegularLaneQueue *q) {
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return NULL;

    // Store previous front and move front one node ahead
    Customer *temp = q->front;
    q->front = q->front->next;

    // If front becomes NULL, the change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    return temp;
}

void list(RegularLaneQueue *q);
void list(RegularLaneQueue *q) {
    Customer *temp = q->front;
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;
    // puts("\n");
    puts("Queue is:");
    do {
        printf("<-[ #: %d ]", temp->priority_number);
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

int main() {
    RegularLaneQueue *q = createQueue();
    enQueue(q, 1000);
    // enQueue(q, 1002);
    list(q);

    // Customer *rL= deQueue(q);
    // if (rL != NULL)
    //     printf("Dequeued item is %d\n",
    //             rL->priority_number);

    puts("\nList After deQueue:");
    list(q);

    getchar();

    destructQueue(q);

    return 0;
}
