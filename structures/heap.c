#include <stdio.h>
#include "heap.h"

struct heap createHeap(){
    struct heap newHeap;
    newHeap.min = __INT_MAX__;
    newHeap.length = 0;
    
    return newHeap;
}

void insertHeap(struct heap *h, int ele, int index){
    h->que[h->length] = ele;
    h->index[h->length] = index;
    h->length++;

    if (ele < h->min) {
        int lastMin = h->que[0];
        int lastMinIndex = h->index[0];
        h->min = ele;
        h->que[0] = ele;
        h->index[0] = index;
        h->que[h->length-1] = lastMin;
        h->index[h->length-1] = lastMinIndex;
    }
}

int minInHeapIndex(struct heap *h){
    if (h->length == 0) return -1;
    int min = 0;
    for (int i = 0; i < h->length; i++) {
        if (h->que[i] < h->que[min] && h->que[i] != -1) min = i;
    }
    h->min = min;
    return min;
}

int deque(struct heap *h){
    if (h->length == 0) return -1;
    int removed = h->que[0];
    int removedIndex = h->index[0];
    for (int i = 0; i < h->length - 1; i++) {
        h->que[i] = h->que[i + 1];
        h->index[i] = h->index[i + 1];
    }

    int minIndex = minInHeapIndex(h);
    int indexOfMinIndex = h->index[minIndex];
    h->min = h->que[minIndex];
    h->que[minIndex] = h->que[0];
    h->index[minIndex] = h->index[0];

    h->que[0] = h->min;
    h->index[0] = indexOfMinIndex;
    h->length--;

    return removed;
}

void printHeap(struct heap *h){
    printf("\nElements: ");
    for (int i=0; i<h->length; i++) printf("%d ", h->que[i]);
    printf("\nIndexs: ");
    for (int i=0; i<h->length; i++) printf("%d ", h->index[i]);
}

int peekFront(struct heap *h){
    return h->que[0];
}