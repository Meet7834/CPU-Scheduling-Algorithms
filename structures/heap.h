#ifndef HEAP_H
#define HEAP_H

struct heap {
    int que[100]; // This will contain the main array
    int index[100]; // This will contain the index of element int the original data.
    int min; // Min element fo the heap
    int length; // Size of the heap
};

struct heap createHeap();

void insertHeap(struct heap *h, int ele, int index);

int minInHeapIndex(struct heap *h);

int deque(struct heap *h);

void printHeap(struct heap *h);

int peekFront(struct heap *h);

#endif