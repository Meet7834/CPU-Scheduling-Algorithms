#include<stdio.h>

int findMinIndex(int arrivalTime[], int length){
    int min = __INT_MAX__, index = length;

    for (int i=0; i<length; i++) if (min > arrivalTime[i] && arrivalTime[i] != -1) {
        min = arrivalTime[i];
        index = i;
    }

    // if it returns index as -1 it means the all the process are executed.
    if (index == length) return -1;             
    
    return index;
}

void printArr(int arr[], int length){
    printf("\n");
    for (int i=0; i<length; i++) printf("%d ", arr[i]);
}

void FCFS(int numProcess, int arrivalTime[], int burstTime[]){
    int timeSpent = 0, idleCPUTime = 0;
    int completionTime[numProcess], turnAroundTime[numProcess], waitingTime[numProcess];
    
    while(findMinIndex(arrivalTime, numProcess) != -1){
        int minIndex = findMinIndex(arrivalTime, numProcess);
        
        if (arrivalTime[minIndex] == timeSpent){ // Process doesn't have to wait for its turn waiting time will be zero;
            
        }
        else if (arrivalTime[minIndex] < timeSpent){ //Process will have to wait for other process to finish:
            
        }
        else if (arrivalTime[minIndex] > timeSpent){ // CPU will be idle untill the next process arrives:
            idleCPUTime += arrivalTime[minIndex] - timeSpent;
            timeSpent += arrivalTime[minIndex] - timeSpent;
            
        }

        timeSpent += burstTime[minIndex];
        turnAroundTime[minIndex] = timeSpent - arrivalTime[minIndex];
        completionTime[minIndex] = turnAroundTime[minIndex] + arrivalTime[minIndex];
        waitingTime[minIndex] = turnAroundTime[minIndex] - burstTime[minIndex];

        arrivalTime[minIndex] = -1;
    }

    printf("\nTotal time spent on running these process(s): %d", timeSpent);
    printf("\nTotal idle CPU time: %d", idleCPUTime);

    printf("\nCompletion Time for each process: ");
    printArr(completionTime, numProcess);
    
    printf("\nTurn Around Time for each process: ");
    printArr(turnAroundTime, numProcess);
    
    printf("\nWaiting Time for each process: ");
    printArr(waitingTime, numProcess);

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

    FCFS(numProcess, arrivalTime, burstTime);

    /*Sample Test case:
    4
    0 1 5 6
    2 2 3 4
    */
}