#include <stdio.h>
#include "../utils/utils.h"
//#include "../structures/myProcess.h"
#include "../algos/FCFS.h"
#include "assert.h"

void test_FCFS_algorithm() {
    // test 1:
    int arrivalTime1[] = {0, 1, 5, 6};
    int burstTime1[] = {2, 2, 3, 4};
    struct myProcess test1 = createProcess(4, arrivalTime1, burstTime1);
    FCFS(&test1);

    assert(test1.timeSpent == 12);
    assert(test1.idleCPUTime == 1);
    assert(test1.totalWaitingTime == 3);
    assert(test1.totalTurnAroundTime == 14);
    printf("FCFS test 1 passed!\n");

    // test 2:
    int arrivalTime2[] = {0, 5, 2, 10};
    int burstTime2[] = {10, 4, 5, 1};
    struct myProcess test2 = createProcess(4, arrivalTime2, burstTime2);
    FCFS(&test2);

    assert(test2.timeSpent == 20);
    assert(test2.idleCPUTime == 0);
    assert(test2.totalWaitingTime == 27);
    assert(test2.totalTurnAroundTime == 47);
    printf("FCFS test 2 passed!\n");


    // test 3
    int arrivalTime3[] = {0, 5, 19, 30};
    int burstTime3[] = {9, 4, 2, 5};
    struct myProcess test3 = createProcess(4, arrivalTime3, burstTime3);
    FCFS(&test3);

    assert(test3.timeSpent == 35);
    assert(test3.idleCPUTime == 15);
    assert(test3.totalWaitingTime == 4);
    assert(test3.totalTurnAroundTime == 24);
    printf("FCFS test 3 passed!\n");
    printf("All the FCFS test passed!\n");

}

int main() {
    test_FCFS_algorithm();
    return 0;
}
