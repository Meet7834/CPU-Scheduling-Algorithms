cmake_minimum_required(VERSION 3.26)
project(CPU_Scheduling_Algorithms C)

set(CMAKE_C_STANDARD 11)

include_directories(algos)
include_directories(structures)
include_directories(utils)

add_executable(CPU_Scheduling_Algorithms
        algos/FCFS.c
        algos/FCFS.h
        algos/SJF.c
        algos/SJF.h
        structures/heap.c
        structures/heap.h
        structures/myProcess.c
        structures/myProcess.h
        utils/utils.c
        utils/utils.h
        main.c
        structures/queue.c
        structures/queue.h
        algos/RoundRobin.c
        algos/RoundRobin.h
        algos/SRTF.c
        algos/SRTF.h
)
