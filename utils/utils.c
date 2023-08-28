#include<stdio.h>
#include "utils.h"

//Utility Functions:
void printArr(int arr[], int length){
    printf("\n");
    for (int i=0; i<length; i++) printf("%d ", arr[i]);
}

int findMinIndex(int arr[], int length){
    int min = __INT_MAX__, index = length;

    for (int i=0; i<length; i++) if (min > arr[i] && arr[i] != -1) {
        min = arr[i];
        index = i;
    }

    // if it returns index as -1 it means the all the process are executed.
    if (index == length) return -1;             
    
    return index;
}