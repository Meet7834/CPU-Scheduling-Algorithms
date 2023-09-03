gcc -o test_fcfs tests/tests_fcfs.c structures/myProcess.c utils/utils.c algos/FCFS.c -I. -lm
gcc -o test_sjf tests/tests_sjf.c structures/myProcess.c structures/heap.c utils/utils.c algos/SJF.c -I. -lm
gcc -o test_rr tests/tests_rr.c structures/myProcess.c structures/queue.c utils/utils.c algos/RoundRobin.c -I. -lm
gcc -o test_srtf tests/tests_srtf.c structures/myProcess.c structures/heap.c utils/utils.c algos/SRTF.c -I. -lm
./test_fcfs
./test_sjf
./test_srtf
./test_rr
rm test_fcfs test_sjf test_rr test_srtf