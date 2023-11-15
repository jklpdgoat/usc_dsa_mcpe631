#ifndef STACK_INCLUDED
#define STACK_INCLUDED

typedef struct Stack_T *Stack_t;

extern Stack_T Stack_new(void);
extern int Stack_empty(Stack_T stk);
extern void Stack_push(Stack_T stk, void *);
extern void *Stack_pop(Stack_T stk);
extern void Stack_free(Stack_T *stk);

#endif