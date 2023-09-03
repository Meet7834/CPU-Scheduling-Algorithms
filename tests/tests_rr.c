#include <stdio.h>
#include "../utils/utils.h"
#include "../algos/RoundRobin.h"
#include "assert.h"

void test_RR_algorithm() {
    // test 1:
    int numProcess1 = 4;
    int arrivalTime1[] = {0, 1, 2, 4};
    int burstTime1[] = {5, 4, 2, 1};
    int timeQuantum1 = 2;
    struct myProcess test1 = createProcessPreEmptive(numProcess1, arrivalTime1, burstTime1,timeQuantum1);
    roundRobin(&test1);

    assert(test1.timeSpent == 12);
    assert(test1.idleCPUTime == 0);
    assert(test1.totalWaitingTime == 19);
    assert(test1.totalTurnAroundTime == 31);
    assert(test1.contextSwitches == 6);
    printf("\n\nRound Robin test 1 passed!");

    // test 2:
    int numProcess2 = 5;
    int arrivalTime2[] = {0, 1, 2,3 , 4};
    int burstTime2[] = {5, 3,1, 2, 3};
    int timeQuantum2 = 2;
    struct myProcess test2 = createProcessPreEmptive(numProcess2, arrivalTime2,burstTime2,timeQuantum2);
    roundRobin(&test2);

    assert(test2.timeSpent == 14);
    assert(test2.idleCPUTime == 0);
    assert(test2.totalWaitingTime == 29);
    assert(test2.totalTurnAroundTime == 43);
    assert(test2.contextSwitches == 8);
    printf("\nRound Robin test 2 passed!");

    // test 3:
    int numProcess3 = 6;
    int arrivalTime3[] = {5, 4, 3,1 , 2, 6};
    int burstTime3[] = {5, 6,7, 9, 2, 3};
    int timeQuantum3 = 3;
    struct myProcess test3 = createProcessPreEmptive(numProcess3, arrivalTime3,burstTime3,timeQuantum3);
    roundRobin(&test3);

    assert(test3.timeSpent == 33);
    assert(test3.idleCPUTime == 1);
    assert(test3.totalWaitingTime == 96);
    assert(test3.totalTurnAroundTime == 128);
    assert(test3.contextSwitches == 11);
    printf("\nRound Robin test 3 passed!");

    printf("\nAll Round Robin tests passed!");
}

int main() {
    test_RR_algorithm();
    return 0;
}