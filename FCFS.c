#include<stdio.h>

int findMinIndex(int arrivalTime[], int length){
    int min = __INT_MAX__, index = length;

    for (int i=0; i<length; i++) if (min > arrivalTime[i] && arrivalTime[i] != -1) {
        min = arrivalTime[i];
        index = i;
    }
    if (index == length) return -1;
    return index;
}

void FCFS(int numProcess, int arrivalTime[], int burstTime[]){
    int timeSpent = 0, waitingTime = 0;
    while(findMinIndex(arrivalTime, numProcess) != -1){
        int minIndex = findMinIndex(arrivalTime, numProcess);
    }
}

int main(){
    int numProcess;
    
    // Input Part:
    // Enter the number of process and then enter the elements to the array: 

    printf("Enter the number of the process: ");
    scanf("%d", &numProcess);
    int arrivalTime[numProcess], burstTime[numProcess];

    printf("\nEnter arrival time of the process: ");
    for(int i=0; i<numProcess; i++) scanf("%d", &arrivalTime[i]);
    
    printf("\nEnter burst time of the process: ");
    for(int i=0; i<numProcess; i++) scanf("%d", &burstTime[i]);



}