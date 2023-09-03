//structures/myProcess.c
#include "../utils/utils.h"
#include "myProcess.h"

struct myProcess
createProcess(int numProcess, int arrivalTime[], int burstTime[]) { // Creates a new instance of structure myProcess
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

struct myProcess createProcessPreEmptive(int numProcess, int arrivalTime[], int burstTime[],
                                         int timeQuantum) { // Creates a new instance of structure myProcess
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
    printf("\n");
    printf("\nTotal time spent on running these process(s): %d", pr->timeSpent);
    printf("\nTotal idle CPU time: %d", pr->idleCPUTime);
    printf("\n");

    printf("\nCompletion Time:  [ ");
    printArr(pr->completionTime, pr->numProcess);
    printf("]");

    printf("\nTurn Around Time: [ ");
    printArr(pr->turnAroundTime, pr->numProcess);
    printf("]");

    printf("\nWaiting Time:     [ ");
    printArr(pr->waitingTime, pr->numProcess);
    printf("]");

    printf("\n");
    printf("\nAvg Waiting Time: %.2f", (float) pr->totalWaitingTime / (float) pr->numProcess);
    printf("\nAvg Turn Around Time: %.2f", (float) pr->totalTurnAroundTime / (float) pr->numProcess);
}

void printProcessPreEmptive(struct myProcess *pr) { // Prints the process varibles
    printf("\n");
    printf("\nTotal time spent on running these process(s): %d", pr->timeSpent);
    printf("\nTotal idle CPU time: %d", pr->idleCPUTime);
    printf("\n");

    printf("\nCompletion Time:  [ ");
    printArr(pr->completionTime, pr->numProcess);
    printf("]");

    printf("\nTurn Around Time: [ ");
    printArr(pr->turnAroundTime, pr->numProcess);
    printf("]");

    printf("\nWaiting Time:     [ ");
    printArr(pr->waitingTime, pr->numProcess);
    printf("]");

    printf("\nResponse Time:    [ ");
    printArr(pr->responseTime, pr->numProcess);
    printf("]");

    printf("\n");
    printf("\nAvg Waiting Time: %.2f", (float) pr->totalWaitingTime / (float) pr->numProcess);
    printf("\nAvg Turn Around Time: %.2f", (float) pr->totalTurnAroundTime / (float) pr->numProcess);
    printf("\nNumber of context switches: %d", pr->contextSwitches);
}

void printCompare(struct myProcess *pr1, struct myProcess *pr2, struct myProcess *pr3, struct myProcess *pr4){
    printf("\n");
    printf("\nTotal time spent on running these process(s): %d", pr1->timeSpent);
    printf("\nTotal idle CPU time: %d", pr1->idleCPUTime);
    printf("\n");

    printf("\n");
    printf("\nAvg Waiting Time (FCFS): %.2f", (float) pr1->totalWaitingTime / (float) pr1->numProcess);
    printf("\nAvg Turn Around Time (FCFS): %.2f", (float) pr1->totalTurnAroundTime / (float) pr1->numProcess);

    printf("\n");
    printf("\nAvg Waiting Time (SJF): %.2f", (float) pr2->totalWaitingTime / (float) pr2->numProcess);
    printf("\nAvg Turn Around Time (SJF): %.2f", (float) pr2->totalTurnAroundTime / (float) pr2->numProcess);

    printf("\n");
    printf("\nAvg Waiting Time (SRTF): %.2f", (float) pr3->totalWaitingTime / (float) pr3->numProcess);
    printf("\nAvg Turn Around Time (SRTF): %.2f", (float) pr3->totalTurnAroundTime / (float) pr3->numProcess);
    printf("\nNumber of context switches (SRTF): %d", pr3->contextSwitches);

    printf("\n");
    printf("\nAvg Waiting Time (RR): %.2f", (float) pr4->totalWaitingTime / (float) pr4->numProcess);
    printf("\nAvg Turn Around Time (RR): %.2f", (float) pr4->totalTurnAroundTime / (float) pr4->numProcess);
    printf("\nNumber of context switches (RR): %d", pr4->contextSwitches);

    int arr[] = {pr1->totalTurnAroundTime, pr2->totalTurnAroundTime, pr3->totalTurnAroundTime, pr4->totalTurnAroundTime};
    int bestAlgo = findMinIndex(arr, 4);

    if (bestAlgo == 0) printf("\n\nFCFS will be the best algorithm for this sequence of processes.");
    else if (bestAlgo == 1) printf("\n\nSJF will be the best algorithm for this sequence of processes.");
    else if (bestAlgo == 2) printf("\n\nSRTF will be the best algorithm for this sequence of processes.");
    else if (bestAlgo == 3) printf("\n\nRR will be the best algorithm for this sequence of processes.");
}