//structures/myProcess.c
#include "../utils/utils.h"
#include "myProcess.h"

struct myProcess createProcess(int numProcess, int arrivalTime[], int burstTime[]) { // Creates a new instance of structure myProcess
    struct myProcess newProcess; // declare a instace of myProcess

    // Initialize the varaibles
    newProcess.numProcess = numProcess;
    newProcess.idleCPUTime = 0;
    newProcess.timeSpent = 0;
    newProcess.totalWaitingTime = 0;
    newProcess.totalTurnAroundTime = 0;
    newProcess.contextSwitches = -1;
    newProcess.timeQuantum = -1;

    // Initialize the array for the arrival and burst time.
    for (int i = 0; i < numProcess; i++) {
        newProcess.arrivalTime[i] = arrivalTime[i];
        newProcess.burstTime[i] = burstTime[i];
    }

    return newProcess;
}

struct myProcess createProcessPreEmptive(int numProcess, int arrivalTime[], int burstTime[], int timeQuantum) { // Creates a new instance of structure myProcess
    struct myProcess newProcess; // declare a instace of myProcess

    // Initialize the varaibles
    newProcess.numProcess = numProcess;
    newProcess.idleCPUTime = 0;
    newProcess.timeSpent = 0;
    newProcess.totalWaitingTime = 0;
    newProcess.totalTurnAroundTime = 0;
    newProcess.contextSwitches = 0;
    newProcess.timeQuantum = timeQuantum;

    // Initialize the array for the arrival and burst time.
    for (int i = 0; i < numProcess; i++) {
        newProcess.arrivalTime[i] = arrivalTime[i];
        newProcess.burstTime[i] = burstTime[i];
    }

    return newProcess;
}

void printProcess(struct myProcess *pr) { // Prints the process varibles
    printf("\nTotal time spent on running these process(s): %d", pr->timeSpent);
    printf("\nTotal idle CPU time: %d", pr->idleCPUTime);

    printf("\nCompletion Time for each process: ");
    printArr(pr->completionTime, pr->numProcess);

    printf("\nTurn Around Time for each process: ");
    printArr(pr->turnAroundTime, pr->numProcess);

    printf("\nWaiting Time for each process: ");
    printArr(pr->waitingTime, pr->numProcess);

    printf("\nAvg Waiting Time: %.2f", (float) pr->totalWaitingTime / (float) pr->numProcess);
    printf("\nAvg Turn Around Time: %.2f", (float) pr->totalTurnAroundTime / (float) pr->numProcess);
}

void printProcessPreEmptive(struct myProcess *pr) { // Prints the process varibles
    printf("\nTotal time spent on running these process(s): %d", pr->timeSpent);
    printf("\nTotal idle CPU time: %d", pr->idleCPUTime);

    printf("\nCompletion Time for each process: ");
    printArr(pr->completionTime, pr->numProcess);

    printf("\nTurn Around Time for each process: ");
    printArr(pr->turnAroundTime, pr->numProcess);

    printf("\nWaiting Time for each process: ");
    printArr(pr->waitingTime, pr->numProcess);

    printf("\nResponse Time for each process: ");
    printArr(pr->responseTime, pr->numProcess);

    printf("\nAvg Waiting Time: %.2f", (float) pr->totalWaitingTime / (float) pr->numProcess);
    printf("\nAvg Turn Around Time: %.2f", (float) pr->totalTurnAroundTime / (float) pr->numProcess);
    printf("\nNumber of context switches: %d", pr->contextSwitches);
}