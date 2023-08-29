gcc -o test_fcfs tests/tests_fcfs.c structures/myProcess.c utils/utils.c algos/FCFS.c -I. -lm
gcc -o test_sjf tests/tests_sjf.c structures/myProcess.c structures/heap.c utils/utils.c algos/SJF.c -I. -lm
./test_fcfs
./test_sjf
rm test_fcfs test_sjf