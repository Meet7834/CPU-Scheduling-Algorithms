#include "../structures/myProcess.h"
#include "../utils/utils.h"
#include "FCFS.h"

void FCFS(struct myProcess *pr) {
    // Destructring all the data from the process struct.
    int numProcess = pr->numProcess;
    int timeSpent = 0, idleCPUTime = 0;
    int *turnAroundTime = pr->turnAroundTime;
    int *completionTime = pr->completionTime;
    int *waitingTime = pr->waitingTime;
    int totalTurnAroundTime = 0;
    int totalWaitingTime = 0;

    // we make two new arrays as we are going to make changes in them (so it wouldn't affect our original data)
    int arrivalTime[numProcess];
    int burstTime[numProcess];

    // intialize the array with the original data
    for (int i=0; i<numProcess; i++) {
        arrivalTime[i] = pr->arrivalTime[i];
        burstTime[i] = pr->burstTime[i];
    }

    while (findMinIndex(arrivalTime, numProcess) != -1) { // this will run unitll we set all the arrival time to -1
        int minIndex = findMinIndex(arrivalTime, numProcess); // finds min arrivalTime which isn't -1.

        if (arrivalTime[minIndex] == timeSpent); // Process doesn't have to wait for its turn ----> waiting time will be zero;
        else if (arrivalTime[minIndex] < timeSpent); //Process will have to wait for other process to finish.
        else if (arrivalTime[minIndex] > timeSpent) { // CPU will be idle untill the next process arrives (there aren't any process present to be executed)
            idleCPUTime += arrivalTime[minIndex] - timeSpent;
            timeSpent += arrivalTime[minIndex] - timeSpent;
        }

        timeSpent += burstTime[minIndex]; // This is the time that process is running
        turnAroundTime[minIndex] = timeSpent - arrivalTime[minIndex]; // TAT = CT - AT
        completionTime[minIndex] = timeSpent;
        waitingTime[minIndex] = turnAroundTime[minIndex] - burstTime[minIndex]; // WT = TAT - BT

        arrivalTime[minIndex] = -1; // Setting arrival time to -1 so that we don't execute the same process again.
    }

    for (int i = 0; i < numProcess; i++) {
        totalTurnAroundTime += turnAroundTime[i];
        totalWaitingTime += waitingTime[i];
    }

    // Setting data to the original structure.
    pr->timeSpent = timeSpent;
    pr->idleCPUTime = idleCPUTime;
    pr->totalTurnAroundTime = totalTurnAroundTime;
    pr->totalWaitingTime = totalWaitingTime;
}