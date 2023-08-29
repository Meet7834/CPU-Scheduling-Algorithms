#!/bin/bash
gcc -c utils/utils.c -o utils.o
gcc -c structures/myProcess.c -o myProcess.o
gcc -c structures/heap.c -o heap.o
gcc -c algos/FCFS.c -o FCFS.o
gcc -c algos/SJF.c -o SJF.o

gcc main.c utils.o myProcess.o heap.o FCFS.o SJF.o -o my_program
./my_program

rm utils.o myProcess.o FCFS.o SJF.o my_program