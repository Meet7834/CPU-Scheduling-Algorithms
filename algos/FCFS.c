#include "../structures/myProcess.h"
#include "../utils/utils.h"
#include "FCFS.h"

void FCFS(struct myProcess *pr){
    int numProcess = pr->numProcess;
    int timeSpent = 0, idleCPUTime = 0;
    int *arrivalTime = pr->arrivalTime;
    int *turnAroundTime = pr->turnAroundTime;
    int *completionTime = pr->completionTime;
    int *burstTime = pr->burstTime;
    int *waitingTime = pr->waitingTime;
    

    while(findMinIndex(arrivalTime, numProcess) != -1){
        int minIndex = findMinIndex(arrivalTime, numProcess);
        
        if (arrivalTime[minIndex] == timeSpent); // Process doesn't have to wait for its turn waiting time will be zero;
        else if (arrivalTime[minIndex] < timeSpent); //Process will have to wait for other process to finish:
        else if (arrivalTime[minIndex] > timeSpent){ // CPU will be idle untill the next process arrives:
            idleCPUTime += arrivalTime[minIndex] - timeSpent;
            timeSpent += arrivalTime[minIndex] - timeSpent;
        }

        timeSpent += burstTime[minIndex]; // This is the time that process is running
        turnAroundTime[minIndex] = timeSpent - arrivalTime[minIndex]; 
        completionTime[minIndex] = timeSpent;
        waitingTime[minIndex] = turnAroundTime[minIndex] - burstTime[minIndex];

        arrivalTime[minIndex] = -1;
    }
    pr->timeSpent = timeSpent;
    pr->idleCPUTime = idleCPUTime;
}