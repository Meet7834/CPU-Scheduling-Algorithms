#include "../utils/utils.h"
//#include "../structures/myProcess.h"
#include "../structures/heap.h"
#include "SJF.h"

void SJF(struct myProcess *pr) {
    int numProcess = pr->numProcess;
    int timeSpent = 0, idleCPUTime = 0;
    int *arrivalTime = pr->arrivalTime;
    int *turnAroundTime = pr->turnAroundTime;
    int *completionTime = pr->completionTime;
    int *burstTime = pr->burstTime;
    int *waitingTime = pr->waitingTime;
    int totalTurnAroundTime = 0;
    int totalWaitingTime = 0;

    struct heap h = createHeap();

    int minIndex = findMinIndex(arrivalTime, numProcess);
    if (arrivalTime[minIndex] > timeSpent) {
        idleCPUTime += arrivalTime[minIndex] - timeSpent;
        timeSpent += arrivalTime[minIndex] - timeSpent;
    }

    int completedProcess = 0;
    int loop = 0;
    while (completedProcess < numProcess) {
        minIndex = findMinIndex(arrivalTime, numProcess);
        if (arrivalTime[minIndex] > timeSpent && burstTime[minIndex] != 0) {
            idleCPUTime += arrivalTime[minIndex] - timeSpent;
            timeSpent += arrivalTime[minIndex] - timeSpent;
        }
        for (int i = 0; i < numProcess; i++) {
            if (arrivalTime[i] <= timeSpent && burstTime[i] > 0 && arrivalTime[i] != -1) {
                insertHeap(&h, burstTime[i], i);
                burstTime[i] = 0;
            }
        }
        if (h.length != 0) {
            int removedIndex = h.index[0];
            int removedBurstTime = deque(&h);
            int removedArrivalTime = arrivalTime[removedIndex];
            arrivalTime[removedIndex] = -1;
            completedProcess++;
            timeSpent += removedBurstTime;
            completionTime[removedIndex] = timeSpent;
            turnAroundTime[removedIndex] = completionTime[removedIndex] - removedArrivalTime;
            waitingTime[removedIndex] = turnAroundTime[removedIndex] - removedBurstTime;
        }
        loop++;
    }
    for (int i = 0; i < numProcess; i++) totalTurnAroundTime += turnAroundTime[i];
    for (int i = 0; i < numProcess; i++) totalWaitingTime += waitingTime[i];
    pr->timeSpent = timeSpent;
    pr->idleCPUTime = idleCPUTime;
    pr->avgTurnAroundTime = (float) totalTurnAroundTime / (float) numProcess;
    pr->avgWaitingTime = (float) totalWaitingTime / (float) numProcess;
}