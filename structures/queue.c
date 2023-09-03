#include <stdio.h>
#include "queue.h"

struct queue createQueue() {
    struct queue newQueue;
    newQueue.length = 0;
    return newQueue;
}

void insertQueueQue(struct queue *q, int index) {
    if (q->length > 100) {
        printf("\nQueue overflow");
        return;
    }

    q->index[q->length] = index;
    q->length++;
}

int dequeQue(struct queue *q) {
    if (q->length == 0) return -1;
    int removed = q->index[0];

    // Left shift all the elements
    for (int i = 0; i < q->length - 1; i++) {
        q->que[i] = q->que[i + 1];
        q->index[i] = q->index[i + 1];
    }
    q->length--;

    return removed;
}

void printQueue(struct queue *q) {
    printf("\nElements:");
    for (int i = 0; i < q->length; i++) printf("%d ", q->que[i]);
    printf("\nIndexes: ");
    for (int i = 0; i < q->length; i++) printf("%d ", q->index[i]);
}

int peekFrontQue(struct queue *q) {
    return q->que[0];
}