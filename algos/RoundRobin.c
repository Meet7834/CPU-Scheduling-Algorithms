#include "../utils/utils.h"
#include "../structures/queue.h"
#include "RoundRobin.h"

void roundRobin(struct myProcess *pr){
    // Destructuring all the data from the process struct.
    int numProcess = pr->numProcess;
    int timeSpent = 0, idleCPUTime = 0;
    int *turnAroundTime = pr->turnAroundTime;
    int *completionTime = pr->completionTime;
    int *waitingTime = pr->waitingTime;
    int totalTurnAroundTime = 0;
    int totalWaitingTime = 0;
    int timeQuantum = pr->timeQuantum;

    // we make two new arrays as we are going to make changes in them (so it wouldn't affect our original data)
    int arrivalTime[numProcess];
    int burstTime[numProcess];

    // Intialize the array with the original data
    for (int i=0; i<numProcess; i++) {
        arrivalTime[i] = pr->arrivalTime[i];
        burstTime[i] = pr->burstTime[i];
    }

    struct queue q = createQueue();

    // If there aren't any process at time 0 this will take care of that by skipping time untill the first process arrives
    int minIndex = findMinIndex(arrivalTime, numProcess);
    if (arrivalTime[minIndex] > timeSpent) {
        idleCPUTime += arrivalTime[minIndex] - timeSpent;
        timeSpent += arrivalTime[minIndex] - timeSpent;
    }

    int completedProcess = 0; // To keep track of completed process

    while(completedProcess < numProcess) {

        // In the case that there aren't any process available to execute skip to next arrival process. (same as the previous one)
        // To Implement{
            // code
        //}

        for (int i=0; i<numProcess; i++){

        }
    }
}