#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100

struct node {
    int data;
    struct node *link;
} * front, *rear;

void insert();
void delete ();
void display();

void insert() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter the element to be inserted in the queue: ");
    scanf("%d", &temp->data);

    temp->link = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->link = temp;
        rear = temp;
    }
}

void delete () {
    struct node *temp;
    temp = front;

    if (front == NULL) {
        printf("Queue Underflow\n");
        front = rear = NULL;
    } else {
        printf("The deleted element from the queue is: %d\n", front->data);
        front = front->link;
        free(temp);
    }
}

void display() {
    struct node *temp;
    temp = front;
    int cnt = 0;

    if (front == NULL) {
        printf("Queue underflow=n");
    } else {
        printf("The elements of the queue are:\n");
        while (temp) {
            printf("%d\n", temp->data);
            temp = temp->link;
            cnt++;
        }
    }
}

int main() {
    int choice;

    printf("LINKED LIST IMPLEMENTATION OF QUEUES\n\n");

    do {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
        printf("Enter you choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Sorry, invalid choice!\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
