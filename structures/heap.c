#include <stdio.h>
#include "heap.h"

struct heap createHeap() { // Creates the heap and initialize the data
    struct heap newHeap;
    newHeap.min = __INT_MAX__;
    newHeap.length = 0;

    return newHeap;
}

void insertHeap(struct heap *h, int ele, int index) { // To insert the data into the heap.

    // First insert the element at the end of the heap
    h->que[h->length] = ele;
    h->index[h->length] = index;
    h->length++;

    // if element inserted is smaller than the minimum element in the heap then update the heap
    if (ele < h->min) {
        int previousMin = h->que[0];
        int previousMinIndex = h->index[0];

        // Set the previous element at the end of the heap and set the smallest element at the first.
        h->min = ele;
        h->que[0] = ele;
        h->index[0] = index;
        h->que[h->length - 1] = previousMin;
        h->index[h->length - 1] = previousMinIndex;
    }
}

int minInHeapIndex(struct heap *h) { // This function will return the index of the minElement in the heap. (also if the element is -1 then it ignores it)
    if (h->length == 0) return -1; // if the heap is empty return -1
    int minIndex = 0; // Else presume the first element to be minimum
    for (int i = 0; i < h->length; i++) {
        if (h->que[i] < h->que[minIndex] && h->que[i] != -1) minIndex = i;
        if (h->que[i] == h->que[minIndex] && h->que[i] != -1 && h->index[minIndex] > h->index[i]) minIndex = i;// Basic logic for finding the minimum element (except it ignores -1)
    }
    h->min = h->que[minIndex];
    return minIndex;
}

int deque(struct heap *h) { // remove the first element of the heap and returns its index
    if (h->length == 0) return -1;

    int removed = h->que[0];
    int removedIndex = h->index[0];

    // Left shift all the elements
    for (int i = 0; i < h->length - 1; i++) {
        h->que[i] = h->que[i + 1];
        h->index[i] = h->index[i + 1];
    }

    // Finds the new minimum index of que and the asociated index of that.
    int minIndex = minInHeapIndex(h);
    int indexOfMinIndex = h->index[minIndex];

    // Sets the min element as the first element of the heap.
    h->min = h->que[minIndex];
    h->que[minIndex] = h->que[0];
    h->index[minIndex] = h->index[0];

    h->que[0] = h->min;
    h->index[0] = indexOfMinIndex;
    h->length--;

    if (h->length == 0) h->min = __INT_MAX__; // if the heap is empty we set the min to very high value

    return removedIndex;
}

void printHeap(struct heap *h) { // prints the element and indexs of the heap.
    printf("\nElements: ");
    for (int i = 0; i < h->length; i++) printf("%d ", h->que[i]);
    printf("\nIndexes: ");
    for (int i = 0; i < h->length; i++) printf("%d ", h->index[i]);
}

int peekFront(struct heap *h) { // Returns the first element of the heap
    return h->que[0];
}