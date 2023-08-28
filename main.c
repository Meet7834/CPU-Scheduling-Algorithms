#include<stdio.h>
#include <stdlib.h>
#include "structures/myProcess.h"
#include "utils/utils.h"
#include "algos/FCFS.h"
// Defination of functions:

//Structure:

// Constructor & Other Class-Like Functions:

// Main Algorithms:

int main(){
    int numProcess;
    
    // Input Part:
    // Enter the number of process and then enter the elements to the array: 

    printf("Enter the number of the process: ");
    scanf("%d", &numProcess);

    struct myProcess myPr = createProcess(numProcess);
    
    printf("\nEnter arrival time of the process: ");
    for(int i=0; i<numProcess; i++) scanf("%d", &myPr.arrivalTime[i]);
    
    printf("\nEnter burst time of the process: ");
    for(int i=0; i<numProcess; i++) scanf("%d", &myPr.burstTime[i]);

    // Call to FCFS function will calculate all the required numbers and then the printProcess function will print all the arrays and needed numbers.
    FCFS(&myPr);
    printProcess(&myPr);
    
}