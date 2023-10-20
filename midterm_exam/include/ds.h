/*
 * ds.h
 * 
 * 
 */

#ifndef DS_IMPL_H_INCLUDED
#define DS_IMPL_H_INCLUDED

void init(int *head, int *tail);
void enQueue(int *q, int *tail, int element);
int deQueue(int *q, int *head);
int empty(int head, int tail);
int full(int tail, const int size);
void display(int *q, int head, int tail);

#endif /* DS_IMPL_H_INCLUDED */
