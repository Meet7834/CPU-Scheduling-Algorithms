//structures/myProcess.c
#include "../utils/utils.h"
#include "myProcess.h"

struct myProcess createProcess(int numProcess) {
    struct myProcess newProcess;

    newProcess.numProcess = numProcess;
    newProcess.idleCPUTime = 0;
    newProcess.timeSpent = 0;

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
}