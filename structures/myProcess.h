// structures/myProcess.h
#ifndef MY_PROCESS_H
#define MY_PROCESS_H

struct myProcess { // data structure to store different data for the processes
    int numProcess; // number of process
    int idleCPUTime; // the amount of time cpu has been idle
    int timeSpent; // time spent to run all the process
    int totalTurnAroundTime;
    int totalWaitingTime;
    int arrivalTime[100];
    int burstTime[100];
    int completionTime[100]; // the point in time when the process was completed
    int turnAroundTime[100]; // turn around time for each process ( TAT = CT - AT )
    int waitingTime[100]; // waiting time for each process ( WT = TAT - BT )
};

struct myProcess createProcess(int numProcess, int arrivalTime[], int burstTime[]);

void printProcess(struct myProcess *pr);

#endif