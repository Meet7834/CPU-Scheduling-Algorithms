// structures/myProcess.h
#ifndef MY_PROCESS_H
#define MY_PROCESS_H

struct myProcess {
    int numProcess;
    int idleCPUTime;
    int timeSpent;
    float avgTurnAroundTime;
    float avgWaitingTime;
    int arrivalTime[100];
    int burstTime[100];
    int completionTime[100];
    int turnAroundTime[100];
    int waitingTime[100];
};

struct myProcess createProcess(int numProcess, int arrivalTime[], int burstTime[]);
void printProcess(struct myProcess *pr);

#endif