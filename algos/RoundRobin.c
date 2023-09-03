#include "../utils/utils.h"
#include "../structures/queue.h"
#include "RoundRobin.h"

void roundRobin(struct myProcess *pr) {
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

    struct queue q = createQueue();

    int completedProcess = 0; // To keep track of completed process
    int currentProcess = -1; // keeps track of what process is running currently.
    int quantumCounter = 0; // keeps track of how much time we have spent in current quantumTime cycle

    while (completedProcess < numProcess) { // utill we haven't executed all the process

        // this will find the first arrived process at the moment and if itsn't set to -1
        int minArrivalTimeIndex = findMinArrivalTimeIndex(arrivalTime, numProcess, timeSpent);

        // we add the earliest arrived process to the que
        if (minArrivalTimeIndex != -1) {
            insertQueueQue(&q, minArrivalTimeIndex);
            arrivalTime[minArrivalTimeIndex] = -1;
        }


        if (currentProcess == -1) { // no process is running
            if (q.length != 0) { // there are process available for execution waiting inside the que
                currentProcess = dequeQue(&q); // if no process is running then run the first process from the que
                contextSwitches++;
                // This one means if the process hasn't executed for even a single unit time then we can update the response time of the process to the current time - arrival time of the process
                if (remainingBurstTime[currentProcess] == pr->burstTime[currentProcess]) pr->responseTime[currentProcess] = timeSpent - pr->arrivalTime[currentProcess];

                quantumCounter = 0; // reset qunatumCounter to zero.
            } else { // there is no process available for execution
                // increase timeSpent and idleCPUTime by 1 unit
                timeSpent++;
                idleCPUTime++;
            }
        } else { // currently a process is running
            if (quantumCounter < timeQuantum) remainingBurstTime[currentProcess]--; // decrease remBurstTime by 1 unit if we are still within the timeQunatum limit

            if (remainingBurstTime[currentProcess] == 0) { // process is completed
                completedProcess++;
                timeSpent++;
                completionTime[currentProcess] = timeSpent;
                turnAroundTime[currentProcess] = completionTime[currentProcess] - pr->arrivalTime[currentProcess]; // TAT = CT - AT
                waitingTime[currentProcess] = turnAroundTime[currentProcess] - pr->burstTime[currentProcess]; // WT = TAT - BT
                currentProcess = -1; // no process is running now
                quantumCounter = 0; // reset the qunatumCounter
            } else if (quantumCounter >= timeQuantum) { // reached time quantum
                insertQueueQue(&q, currentProcess); // insert the process at the end of the que
                currentProcess = -1; // no process is running now
                quantumCounter = 0; // reset the qunatumCounter
            } else { // you still need to execute this process
                timeSpent++;
                quantumCounter++;
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