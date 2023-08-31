#include <stdio.h>
#include "../utils/utils.h"
#include "../algos/SJF.h"
#include "assert.h"

void test_SJF_algorithm() {
    // test 1:
    int arrivalTime1[] = {1, 2, 1, 4};
    int burstTime1[] = {3, 4, 2, 4};
    struct myProcess test1 = createProcess(4, arrivalTime1, burstTime1);
    SJF(&test1);

    assert(test1.timeSpent == 14);
    assert(test1.idleCPUTime == 1);
    assert(test1.totalWaitingTime == 12);
    assert(test1.totalTurnAroundTime == 25);
    printf("\nSJF test 1 passed!");

    // test 2:
    int arrivalTime2[] = {0, 1, 2, 3, 4};
    int burstTime2[] = {3, 2, 3, 2, 3};
    struct myProcess test2 = createProcess(5, arrivalTime2, burstTime2);
    SJF(&test2);

    assert(test2.timeSpent == 13);
    assert(test2.idleCPUTime == 0);
    assert(test2.totalWaitingTime == 15);
    assert(test2.totalTurnAroundTime == 28);
    printf("\nSJF test 2 passed!");

    // test 3:
    int arrivalTime3[] = {0, 0, 4, 30};
    int burstTime3[] = {9, 4, 2, 5};
    struct myProcess test3 = createProcess(4, arrivalTime3, burstTime3);
    SJF(&test3);

    assert(test3.timeSpent == 35);
    assert(test3.idleCPUTime == 15);
    assert(test3.totalWaitingTime == 6);
    assert(test3.totalTurnAroundTime == 26);
    printf("\nSJF test 3 passed!");

    // test 4:
    int arrivalTime4[] = {3, 1, 4, 0, 2};
    int burstTime4[] = {1, 4, 2, 6, 3};
    struct myProcess test4 = createProcess(5, arrivalTime4, burstTime4);
    SJF(&test4);

    assert(test4.timeSpent == 16);
    assert(test4.idleCPUTime == 0);
    assert(test4.totalWaitingTime == 24); // avg = 4.80
    assert(test4.totalTurnAroundTime == 40); // avg = 8.00
    printf("\nSJF test 4 passed!");
    printf("\nAll SJF tests passed!");
}

int main() {
    test_SJF_algorithm();
    return 0;
}
