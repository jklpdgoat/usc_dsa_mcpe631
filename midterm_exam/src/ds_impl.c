// ds_impl.c

// init queue pointers
void init(int *head, int *tail) { *head = *tail = 0; }

/*
 * Enqueue an element
 * Given that the queue is not full
 */
void enQueue(int *q, int *tail, int element) { q[(*tail)++] = element; }

/*
 * Dequeue an element
 * The queue is not full
 */
int deQueue(int *q, int *head) { return q[(*head)++]; }

/*
    return 1 if queue is full, otherwise return 0
*/
int full(int tail, const int size) { return tail == size; }

/*
  return 1 if the queue is empty, otherwise return 0
*/
int empty(int head, int tail) { return tail == head; }

/*
  display queue content
*/
void display(int *q, int head, int tail) {
        int i = tail - 1;
        while (i >= head)
                printf("%d", q[i--]);
        printf("\n");
}
