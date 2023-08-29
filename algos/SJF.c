#include "../utils/utils.h"
//#include "../structures/myProcess.h"
#include "../structures/heap.h"
#include "SJF.h"

void SJF(struct myProcess *pr)
{
    int numProcess = pr->numProcess;
    int timeSpent = 0, idleCPUTime = 0;
    int *arrivalTime = pr->arrivalTime;
    int *turnAroundTime = pr->turnAroundTime;
    int *completionTime = pr->completionTime;
    int *burstTime = pr->burstTime;
    int *waitingTime = pr->waitingTime;

    struct heap h = createHeap();

    int minIndex = findMinIndex(arrivalTime, numProcess);
    if (arrivalTime[minIndex] > timeSpent)
    {
        idleCPUTime += arrivalTime[minIndex] - timeSpent;
        timeSpent += arrivalTime[minIndex] - timeSpent;
    }

    int completedProcess = 0;
    while (completedProcess < numProcess)
    {
        for (int i = 0; i < numProcess; i++)
        {
            if (arrivalTime[i] <= timeSpent && burstTime[i] > 0){
                insertHeap(&h, burstTime[i], i);
                burstTime[i] = 0;
            }
        }
        if (h.length != 0)
        {
            int removedIndex = h.index[0];
            int removedBurstTime = deque(&h);
            completedProcess++;
            timeSpent += removedBurstTime;
            completionTime[removedIndex] = timeSpent;
            turnAroundTime[removedIndex] = completionTime[removedIndex] - arrivalTime[removedIndex];
            waitingTime[removedIndex] = turnAroundTime[removedIndex] - removedBurstTime;
        }
    }
    pr->timeSpent = timeSpent;
    pr->idleCPUTime = idleCPUTime;
}