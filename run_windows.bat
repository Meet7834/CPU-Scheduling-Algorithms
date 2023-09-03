@echo off

rem Compile the source files
gcc -c utils/utils.c -o utils.o
gcc -c structures/myProcess.c -o myProcess.o
gcc -c structures/heap.c -o heap.o
gcc -c structures/queue.c -o queue.o
gcc -c algos/FCFS.c -o FCFS.o
gcc -c algos/SJF.c -o SJF.o
gcc -c algos/RoundRobin.c -o RoundRobin.o
gcc -c algos/SRTF.c -o SRTF.o
gcc -c main.c -o main.o

rem Link the object files to create the executable
gcc main.o utils.o myProcess.o heap.o queue.o FCFS.o SJF.o SRTF.o RoundRobin.o -o myprogram

rem Run the compiled program
myprogram

rem Remove the object files and the executable
del utils.o myProcess.o heap.o queue.o FCFS.o SJF.o RoundRobin.o SRTF.o main.o myprogram.exe
rem Pause to see the output before the window closes
pause