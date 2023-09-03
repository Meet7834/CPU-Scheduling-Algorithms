#include<stdio.h>
#include <stdlib.h>
#include "structures/myProcess.h"
#include "structures/heap.h"
#include "utils/utils.h"
#include "algos/FCFS.h"
#include "algos/SJF.h"
#include "algos/RoundRobin.h"

int main() {
    int algo = 0;
    while (algo != -1) {
        int numProcess, timeQuantum;
        printf("\nEnter the scheduling algorithm: 1: FCFS, 2: SJF, 3: RR: ");
        scanf("%d", &algo);

        if (algo > 3 || algo < 1) {
            printf("\nPlease enter the correct algorithm.");
            continue;
        } else if (algo >= 1 && algo <= 3) {
            printf("\nEnter the number of the process: ");
            scanf("%d", &numProcess);
            int arrivalTime[numProcess], burstTime[numProcess];

            printf("\nEnter arrival time of the process: ");
            for (int i = 0; i < numProcess; i++) scanf("%d", &arrivalTime[i]);

            printf("\nEnter burst time of the process: ");
            for (int i = 0; i < numProcess; i++) scanf("%d", &burstTime[i]);

            if (algo == 1 || algo == 2) {
                struct myProcess pr = createProcess(numProcess, arrivalTime, burstTime);
                if (algo == 1) {
                    FCFS(&pr);
                    printProcess(&pr);
                } else if (algo == 2) {
                    SJF(&pr);
                    printProcess(&pr);
                }
            } else if (algo == 3) {
                printf("\nEnter time quantum:");
                scanf("%d", &timeQuantum);
                struct myProcess pr = createProcessPreEmptive(numProcess, arrivalTime, burstTime, timeQuantum);
                roundRobin(&pr);
                printProcessPreEmptive(&pr);
            }
        } else {
            printf("\nWrong Input, Exiting Program.");
            break;
        }
        printf("\n\nTo exit enter -1 or to continue enter 1");
        scanf("%d", &algo);
    }
}