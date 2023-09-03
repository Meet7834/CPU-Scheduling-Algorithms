#include <stdio.h>

#ifndef UTILS_H
#define UTILS_H

#include "../structures/myProcess.h"

void printArr(int arr[], int length);

int findMinIndex(int arr[], int length);

int findMinArrivalTimeIndex(int arrivalTime[], int numProcess, int currentTime);

#endif