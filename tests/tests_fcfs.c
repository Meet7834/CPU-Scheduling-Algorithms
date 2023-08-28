#include <stdio.h>
#include "../utils/utils.h"
#include "../structures/myProcess.h"
#include "../algos/FCFS.h"
#include "assert.h"

void test_FCFS_algorithm() {
    // test 1:
    struct myProcess test1 = createProcess(4);
    int arrivalTime1[] = {0, 1, 5, 6};
    int burstTime1[] = {2, 2, 3, 4};

    for (int i = 0; i < test1.numProcess; i++) {
        test1.arrivalTime[i] = arrivalTime1[i];
        test1.burstTime[i] = burstTime1[i];
    }
    FCFS(&test1);

    assert(test1.timeSpent == 12);
    assert(test1.idleCPUTime == 1);
    printf("FCFS test 1 passed!\n");

    // test 2:
    struct myProcess test2 = createProcess(4);
    int arrivalTime2[] = {0, 5, 2, 10};
    int burstTime2[] = {10, 4, 5, 1};

    for (int i = 0; i < test2.numProcess; i++) {
        test2.arrivalTime[i] = arrivalTime2[i];
        test2.burstTime[i] = burstTime2[i];
    }
    FCFS(&test2);

    assert(test2.timeSpent == 20);
    assert(test2.idleCPUTime == 0);
    printf("FCFS test 2 passed!\n");
    
    
    // test 3
    struct myProcess test3 = createProcess(4);
    int arrivalTime3[] = {0, 5, 19, 30};
    int burstTime3[] = {9, 4, 2, 5};

    for (int i = 0; i < test3.numProcess; i++) {
        test3.arrivalTime[i] = arrivalTime3[i];
        test3.burstTime[i] = burstTime3[i];
    }
    FCFS(&test3);

    assert(test3.timeSpent == 35);
    assert(test3.idleCPUTime == 15);
    printf("FCFS test 3 passed!\n");
    printf("All the FCFS test passed!\n");
    
}

int main() {
    test_FCFS_algorithm();
    return 0;
}
