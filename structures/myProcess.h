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

    // For pre-emptive mode (Round Robin and SRJF):
    int timeQuantum; // Time quantum for Round Robin
    int contextSwitches; // Number of time context switched
    int responseTime[100]; // Response time of the process
};

struct myProcess createProcess(int numProcess, int arrivalTime[], int burstTime[]);

struct myProcess createProcessPreEmptive(int numProcess, int arrivalTime[], int burstTime[], int timeQuantum);

void printProcess(struct myProcess *pr);

void printProcessPreEmptive(struct myProcess *pr);

void printCompare(struct myProcess *pr1, struct myProcess *pr2, struct myProcess *pr3, struct myProcess *pr4);

#endif