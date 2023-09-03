#include "../utils/utils.h"
#include "../structures/heap.h"
#include "SRTF.h"

void SRTF(struct myProcess *pr) {
    // Destructuring all the data from the process struct.
    int numProcess = pr->numProcess;
    int *turnAroundTime = pr->turnAroundTime;
    int *completionTime = pr->completionTime;
    int *waitingTime = pr->waitingTime;
    int timeQuantum = pr->timeQuantum;

    int timeSpent = 0, idleCPUTime = 0, totalWaitingTime = 0, totalTurnAroundTime = 0, contextSwitches = 0;

    // we make two new arrays as we are going to make changes in them (so it wouldn't affect our original data)
    int arrivalTime[numProcess], remainingBurstTime[numProcess];

    // Intialize the array with the original data
    for (int i = 0; i < numProcess; i++) {
        arrivalTime[i] = pr->arrivalTime[i];
        remainingBurstTime[i] = pr->burstTime[i];
    }

    struct heap h = createHeap();

    int completedProcess = 0; // To keep track of completed process
    int currentProcess = -1; // keeps track of what process is running currently.

    while (completedProcess < numProcess) { // utill we haven't executed all the process

        // this will find the first arrived process at the moment and if itsn't set to -1
        int minArrivalTimeIndex = findMinArrivalTimeIndex(arrivalTime, numProcess, timeSpent);

        // we add the earliest arrived process to the que
        if (minArrivalTimeIndex != -1) {
            insertHeap(&h, remainingBurstTime[minArrivalTimeIndex], minArrivalTimeIndex);
            arrivalTime[minArrivalTimeIndex] = -1;
        }


        if (currentProcess == -1) { // no process is running
            if (h.length != 0) { // there are process available for execution waiting inside the que
                currentProcess = deque(&h); // if no process is running then run the first process from the que
                contextSwitches++;
                // This one means if the process hasn't executed for even a single unit time then we can update the response time of the process to the current time - arrival time of the process
                if (remainingBurstTime[currentProcess] == pr->burstTime[currentProcess])
                    pr->responseTime[currentProcess] = timeSpent - pr->arrivalTime[currentProcess];

            } else { // there is no process available for execution
                // increase timeSpent and idleCPUTime by 1 unit
                timeSpent++;
                idleCPUTime++;
            }
        } else { // currently a process is running

            if (remainingBurstTime[currentProcess] == 0) { // process is completed
                completedProcess++;
//                timeSpent++;
                completionTime[currentProcess] = timeSpent;
                turnAroundTime[currentProcess] =
                        completionTime[currentProcess] - pr->arrivalTime[currentProcess]; // TAT = CT - AT
                waitingTime[currentProcess] =
                        turnAroundTime[currentProcess] - pr->burstTime[currentProcess]; // WT = TAT - BT
                currentProcess = -1; // no process is running now
            } else if (h.length != 0 && remainingBurstTime[currentProcess] > h.que[0]) {
                insertHeap(&h, remainingBurstTime[currentProcess], currentProcess);
                currentProcess = deque(&h);
                if (remainingBurstTime[currentProcess] == pr->burstTime[currentProcess])
                    pr->responseTime[currentProcess] = timeSpent - pr->arrivalTime[currentProcess];
                contextSwitches++;
//                timeSpent++;
            } else { // you still need to execute this process
                timeSpent++;
                remainingBurstTime[currentProcess]--;
            }
        }

    }

    for (int i = 0; i < numProcess; i++) {
        totalTurnAroundTime += turnAroundTime[i];
        totalWaitingTime += waitingTime[i];
    }

    pr->timeSpent = timeSpent;
    pr->idleCPUTime = idleCPUTime;
    pr->contextSwitches = contextSwitches - 1; // if we don't count the first one as context switch
    pr->totalTurnAroundTime = totalTurnAroundTime;
    pr->totalWaitingTime = totalWaitingTime;
}