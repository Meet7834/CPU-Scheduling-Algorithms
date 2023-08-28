@echo off

rem Compile the source files
gcc -c structures/myProcess.c -o myProcess.o
gcc -c utils/utils.c -o utils.o
gcc -c algos/FCFS.c -o FCFS.o
gcc -c main.c -o main.o

rem Link the object files to create the executable
gcc main.o myProcess.o utils.o FCFS.o -o myprogram

rem Run the compiled program
myprogram

rem Pause to see the output before the window closes
pause
