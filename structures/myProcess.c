//structures/myProcess.c
#include "../utils/utils.h"
#include "myProcess.h"

struct myProcess createProcess(int numProcess, int arrivalTime[], int burstTime[]) {
    struct myProcess newProcess;

    newProcess.numProcess = numProcess;
    newProcess.idleCPUTime = 0;
    newProcess.timeSpent = 0;
    newProcess.avgWaitingTime = 0;
    newProcess.avgTurnAroundTime = 0;

    for (int i=0; i<numProcess; i++) newProcess.arrivalTime[i] = arrivalTime[i];
    for (int i=0; i<numProcess; i++) newProcess.burstTime[i] = burstTime[i];
    return newProcess;
}

void printProcess(struct myProcess *pr){
    printf("\nTotal time spent on running these process(s): %d", pr->timeSpent);
    printf("\nTotal idle CPU time: %d", pr->idleCPUTime);

    printf("\nCompletion Time for each process: ");
    printArr(pr->completionTime, pr->numProcess);
    
    printf("\nTurn Around Time for each process: ");
    printArr(pr->turnAroundTime, pr->numProcess);
    
    printf("\nWaiting Time for each process: ");
    printArr(pr->waitingTime, pr->numProcess);

    printf("\nAvg Waiting Time: %.2f", pr->avgWaitingTime);
    printf("\nAvg Turn Around Time: %.2f", pr->avgTurnAroundTime);
}