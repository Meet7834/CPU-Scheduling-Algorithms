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
    printf("\nSJF test 1 passed!");

    // test 2:
    int arrivalTime2[] = {0, 1, 2, 3, 4};
    int burstTime2[] = {3, 2, 3, 2, 3};
    struct myProcess test2 = createProcess(5, arrivalTime2, burstTime2);
    SJF(&test2);

    assert(test2.timeSpent == 13);
    assert(test2.idleCPUTime == 0);
    printf("\nSJF test 2 passed!");

    // test 3:
    int arrivalTime3[] = {0, 0, 4, 30};
    int burstTime3[] = {9, 4, 2, 5};
    struct myProcess test3 = createProcess(4, arrivalTime3, burstTime3);
    SJF(&test3);

    assert(test3.timeSpent == 35);
    assert(test3.idleCPUTime == 15);
    printf("\nSJF test 3 passed!");
    printf("\nAll SJF tests passed!");
}

int main() {
    test_SJF_algorithm();
    return 0;
}
