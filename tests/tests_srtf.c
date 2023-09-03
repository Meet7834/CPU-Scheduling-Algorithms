#include <stdio.h>
#include "../utils/utils.h"
#include "../algos/SRTF.h"
#include "assert.h"

void test_SRTF_algorithm() {
    // test 1:
    int numProcess1 = 4;
    int arrivalTime1[] = {0, 1, 2, 4};
    int burstTime1[] = {5, 3, 4, 1};
    struct myProcess test1 = createProcess(numProcess1, arrivalTime1, burstTime1);
    SRTF(&test1);

    assert(test1.timeSpent == 13);
    assert(test1.idleCPUTime == 0);
    assert(test1.totalWaitingTime == 11);
    assert(test1.totalTurnAroundTime == 24);
    assert(test1.contextSwitches == 4);
    printf("\n\nSRTF test 1 passed!");

    // test 2:
    int numProcess2 = 5;
    int arrivalTime2[] = {3, 1, 4, 0, 2};
    int burstTime2[] = {1, 4, 2, 6, 3};
    struct myProcess test2 = createProcess(numProcess2, arrivalTime2, burstTime2);
    SRTF(&test2);

    assert(test2.timeSpent == 16);
    assert(test2.idleCPUTime == 0);
    assert(test2.totalWaitingTime == 19);
    assert(test2.totalTurnAroundTime == 35);
    assert(test2.contextSwitches == 6);
    printf("\nSRTF test 2 passed!");

    // test 3:
    int numProcess3 = 3;
    int arrivalTime3[] = {0, 1, 2};
    int burstTime3[] = {9, 4, 9};
    struct myProcess test3 = createProcess(numProcess3, arrivalTime3, burstTime3);
    SRTF(&test3);

    assert(test3.timeSpent == 22);
    assert(test3.idleCPUTime == 0);
    assert(test3.totalWaitingTime == 15);
    assert(test3.totalTurnAroundTime == 37);
    assert(test3.contextSwitches == 3);
    printf("\nSRTF test 3 passed!");

    printf("\nAll SRTF tests passed!");
}

int main() {
    test_SRTF_algorithm();
    return 0;
}