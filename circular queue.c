/******************************************************************************

                    Implement Circular Queue

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct CircularQueue {
    int items[SIZE];
    int front;
    int rear;
} CQ;

void initializeQueue(CQ *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CQ *q) {
    if ((q->front == q->rear + 1) || (q->front == 0 && q->rear == SIZE - 1))
        return 1;
    return 0;
}

int isEmpty(CQ *q) {
    if (q->front == -1)
        return 1;
    return 0;
}

void enqueue(CQ *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

int dequeue(CQ *q) {
    int element;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        element = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % SIZE;
        }
        printf("Deleted %d\n", element);
        return element;
    }
}

void display(CQ *q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Front -> %d\n", q->front);
        printf("Items -> ");
        for (i = q->front; i != q->rear; i = (i + 1) % SIZE) {
            printf("%d ", q->items[i]);
        }
        printf("%d ", q->items[i]);
        printf("\nRear -> %d\n", q->rear);
    }
}

int main() {
    CQ q;
    initializeQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 6);
    enqueue(&q, 7);

    display(&q);

    return 0;
}