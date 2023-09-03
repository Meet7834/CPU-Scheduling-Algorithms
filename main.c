#include<stdio.h>
#include <stdlib.h>
#include "structures/myProcess.h"
#include "structures/heap.h"
#include "utils/utils.h"
#include "algos/FCFS.h"
#include "algos/SJF.h"
#include "algos/RoundRobin.h"

int main() {
    int numProcess, timeQuantum;
    // Input Part:
    // Enter the number of process and then enter the elements to the array:

    printf("Enter the number of the process: ");
    scanf("%d", &numProcess);
    int arrivalTime[numProcess], burstTime[numProcess];

    printf("\nEnter arrival time of the process: ");
    for (int i = 0; i < numProcess; i++) scanf("%d", &arrivalTime[i]);

    printf("\nEnter burst time of the process: ");
    for (int i = 0; i < numProcess; i++) scanf("%d", &burstTime[i]);

    printf("\nEnter the time quantum: ");
    scanf("%d", &timeQuantum);

    struct myProcess myPr = createProcessPreEmptive(numProcess, arrivalTime, burstTime,timeQuantum);
    roundRobin(&myPr);
    printProcessPreEmptive(&myPr);
}