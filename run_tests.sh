gcc -o test_fcfs tests/tests_fcfs.c structures/myProcess.c utils/utils.c algos/FCFS.c -I. -lm
./test_fcfs
rm test_fcfs