#!/bin/bash

gcc -c utils/utils.c -o utils.o
gcc -c structures/myProcess.c -o myProcess.o
gcc -c algos/FCFS.c -o FCFS.o

gcc main.c utils.o myProcess.o FCFS.o -o my_program
./my_program

rm utils.o myProcess.o FCFS.o my_program