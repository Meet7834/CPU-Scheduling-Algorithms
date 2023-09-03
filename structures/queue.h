#ifndef QUEUE_H
#define QUEUE_H

struct queue{
    int que[100]; // This will contain the main array
    int index[100]; // This will contain the index of element int the original data.
    int length; // Size of the queue
};

struct queue createQueue();

void insertQueueQue(struct queue *q, int index);

int dequeQue(struct queue *q);

void printQueue(struct queue *q);

int peekFrontQue(struct queue *q);

#endif