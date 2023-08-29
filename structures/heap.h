#ifndef HEAP_H
#define HEAP_H

struct heap{
    int que[100];
    int index[100];
    int min;
    int length;
};

struct heap createHeap();
void insertHeap(struct heap *h, int ele, int index);
int minInHeapIndex(struct heap *h);
int deque(struct heap *h);
void printHeap(struct heap *h);
int peekFront(struct heap *h);

#endif