#include<stdio.h>
#include <stdlib.h>

// Defination of functions:
struct myProcess createProcess();
void printArr();
void printProcess();
int findMinIndex();
void FCFS();

//Structure:
struct myProcess{
    int numProcess;
    int idleCPUTime; // Amount of time CPU is being idle for the process sequence.
    int timeSpent; // Amount of time to execute the all of the processes
    int arrivalTime[100]; // Arrival Time of the process
    int burstTime[100]; // Burst Time (execution time of the process)
    int completionTime[100]; // The point in time at which the process was done being executed
    int turnAroundTime[100]; // The amount of time that process spent in the CPU
    // TurnAroundTime = CompletionTime for the process - ArrivalTime of the process
    int waitingTime[100]; // The amount of time spent by process in the waiting queue
};

// Constructor & Other Class-Like Functions:

struct myProcess createProcess(int numProcess) {
    struct myProcess newProcess;

    newProcess.numProcess = numProcess;
    newProcess.idleCPUTime = 0;
    newProcess.timeSpent = 0;

    return newProcess;
}

void printProcess(struct myProcess *pr){
    printf("\nTotal time spent on running these process(s): %d", pr->timeSpent);
    printf("\nTotal idle CPU time: %d", pr->idleCPUTime);

    printf("\nCompletion Time for each process: ");
    printArr(pr->completionTime, pr->numProcess);
    
    printf("\nTurn Around Time for each process: ");
    printArr(pr->turnAroundTime, pr->numProcess);
    
    printf("\nWaiting Time for each process: ");
    printArr(pr->waitingTime, pr->numProcess);
}

//Utility Functions:
void printArr(int arr[], int length){
    printf("\n");
    for (int i=0; i<length; i++) printf("%d ", arr[i]);
}

int findMinIndex(int arr[], int length){
    int min = __INT_MAX__, index = length;

    for (int i=0; i<length; i++) if (min > arr[i] && arr[i] != -1) {
        min = arr[i];
        index = i;
    }

    // if it returns index as -1 it means the all the process are executed.
    if (index == length) return -1;             
    
    return index;
}

// Main Algorithms:

void FCFS(struct myProcess *pr){
    int numProcess = pr->numProcess;
    int timeSpent = pr->timeSpent;
    int idleCPUTime = pr->idleCPUTime;
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
        completionTime[minIndex] = turnAroundTime[minIndex] + arrivalTime[minIndex];
        waitingTime[minIndex] = turnAroundTime[minIndex] - burstTime[minIndex];

        arrivalTime[minIndex] = -1;
    }
}

int main(){
    int numProcess;
    
    // Input Part:
    // Enter the number of process and then enter the elements to the array: 

    printf("Enter the number of the process: ");
    scanf("%d", &numProcess);
    int arrivalTime[numProcess], burstTime[numProcess];

    struct myProcess myPr = createProcess(numProcess);
    
    printf("\nEnter arrival time of the process: ");
    for(int i=0; i<numProcess; i++) scanf("%d", &myPr.arrivalTime[i]);
    
    printf("\nEnter burst time of the process: ");
    for(int i=0; i<numProcess; i++) scanf("%d", &myPr.burstTime[i]);

    // Call to FCFS function will calculate all the required numbers and then the printProcess function will print all the arrays and needed numbers.
    FCFS(&myPr);
    printProcess(&myPr);
    
}