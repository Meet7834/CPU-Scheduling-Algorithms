#include<stdio.h>
#include <stdlib.h>
#include "structures/myProcess.h"
#include "structures/heap.h"
#include "utils/utils.h"
#include "algos/FCFS.h"
#include "algos/SJF.h"

int main() {
    int numProcess;

    // Input Part:
    // Enter the number of process and then enter the elements to the array: 

    printf("Enter the number of the process: ");
    scanf("%d", &numProcess);
    int arrivalTime[numProcess], burstTime[numProcess];

    printf("\nEnter arrival time of the process: ");
    for (int i = 0; i < numProcess; i++) scanf("%d", &arrivalTime[i]);

    printf("\nEnter burst time of the process: ");
    for (int i = 0; i < numProcess; i++) scanf("%d", &burstTime[i]);

    struct myProcess myPrFCFS = createProcess(numProcess, arrivalTime, burstTime);
    struct myProcess myPrSJF = createProcess(numProcess, arrivalTime, burstTime);


    // Call to FCFS function will calculate all the required numbers and then the printProcess function will print all the arrays and needed numbers.
    FCFS(&myPrFCFS);
    SJF(&myPrSJF);

    printf("\nFor FCFS: ");
    printProcess(&myPrFCFS);
    printf("\n\nFor SJF: ");
    printProcess(&myPrSJF);
}