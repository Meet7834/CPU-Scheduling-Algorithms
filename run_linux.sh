#!/bin/bash
gcc -c utils/utils.c -o utils.o
gcc -c structures/myProcess.c -o myProcess.o
gcc -c structures/heap.c -o heap.o
gcc -c structures/queue.c -o queue.o
gcc -c algos/FCFS.c -o FCFS.o
gcc -c algos/SJF.c -o SJF.o
gcc -c algos/RoundRobin.c -o RoundRobin.o

gcc main.c utils.o myProcess.o heap.o queue.o FCFS.o SJF.o RoundRobin.o -o my_program
./my_program

rm utils.o heap.o queue.o RoundRobin.o myProcess.o FCFS.o SJF.o my_program