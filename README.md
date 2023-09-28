# CPU Scheduling Algorithm Simulator

This program simulates various CPU scheduling algorithms for a given process queue and provides important metrics such as CPU idle time, waiting time for each process, completion time for each process, and total execution time.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Features](#features)
- [Getting Started](#getting-started)

## Introduction

The CPU Scheduling Algorithm Simulator is a tool designed to help users understand and evaluate different CPU scheduling algorithms. It calculates and displays relevant metrics for a given set of processes and their characteristics.

## Usage

1. Compile the source code using the provided shell scripts:
   - `run_project.bat` for Windows Command Prompt.
   - `run_project.sh` for Unix-like systems (bash shell).

2. Run the compiled executable to input the number of processes, their arrival times, and burst times.

3. The program will simulate the selected CPU scheduling algorithm and provide various output metrics.

## Features

- Supports multiple CPU scheduling algorithms (FCFS, SJF, SRTF and Round Robin).
- Calculates and displays metrics including idle CPU time, waiting time, completion time, and total execution time.
- Organized project structure with separate files for utility functions, algorithms, and data structures.

## Getting Started

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/Meet7834/CPU-Scheduling-Algorithms.git
   ```
2. Navigate to the project directory. 

     ```bash
     cd CPU-Scheduling-Algorithms
     ```
3. Compile and run the project:

     - For Windows:
     ```bash
     run_windows.bat
     ```
     - For Unix based systems:
     ```bash
     run_linux.sh
     ```
