#include "../utils/utils.h"
#include "../structures/heap.h"
#include "SJF.h"

void SJF(struct myProcess *pr) {
    // Destructuring all the data from the process struct.
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

    struct heap h = createHeap(); // Creating our custom made heap data structure.

    // If there aren't any process at time 0 this will take care of that by skipping time untill the first process arrives
    int minIndex = findMinIndex(arrivalTime, numProcess);
    if (arrivalTime[minIndex] > timeSpent) {
        idleCPUTime += arrivalTime[minIndex] - timeSpent;
        timeSpent += arrivalTime[minIndex] - timeSpent;
    }

    int completedProcess = 0; // To keep track of completed process
    while (completedProcess < numProcess) {

        // In the case that there aren't any process available to execute skip to next arrival process. (same as the previous one)
        minIndex = findMinIndex(arrivalTime, numProcess);
        if (arrivalTime[minIndex] > timeSpent && burstTime[minIndex] != 0) {
            idleCPUTime += arrivalTime[minIndex] - timeSpent;
            timeSpent += arrivalTime[minIndex] - timeSpent;
        }

        // It collects all the process which have arrived untill the timeSpent and adds them to the custom made heap
        for (int i = 0; i < numProcess; i++) {
            if (arrivalTime[i] <= timeSpent && burstTime[i] > 0 && arrivalTime[i] != -1) {
                insertHeap(&h, burstTime[i], i);
                burstTime[i] = 0; // Setting the burstTime to zero in the original array so that we don't insert it again.
            }
        }

        if (h.length != 0) { // If heap isn't empty.

            // Store the data for the removed process
            int removedIndex = h.index[0];
            int removedBurstTime = h.que[0];
            deque(&h);
            int removedArrivalTime = arrivalTime[removedIndex];

            arrivalTime[removedIndex] = -1; // Set arrival time to -1 so that we don't encouter the same process again
            completedProcess++;

            // Updating the data
            timeSpent += removedBurstTime;
            completionTime[removedIndex] = timeSpent;
            turnAroundTime[removedIndex] = completionTime[removedIndex] - removedArrivalTime; // TAT = CT - AT
            waitingTime[removedIndex] = turnAroundTime[removedIndex] - removedBurstTime; // WT = TAT - BT
        }
    }

    // Updating totalTurnAroundTime and totalWaitingTime
    for (int i = 0; i < numProcess; i++) {
        totalTurnAroundTime += turnAroundTime[i];
        totalWaitingTime += waitingTime[i];
    }

    // Updating the original data in the sturct
    pr->timeSpent = timeSpent;
    pr->idleCPUTime = idleCPUTime;
    pr->totalTurnAroundTime = totalTurnAroundTime;
    pr->totalWaitingTime = totalWaitingTime;
}