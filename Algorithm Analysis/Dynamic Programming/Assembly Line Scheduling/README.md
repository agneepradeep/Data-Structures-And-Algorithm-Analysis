# Assembly Line Scheduling Algorithm

This program is an implementation of the Assembly Line Scheduling problem, which determines the minimum time required to traverse an assembly line with multiple stations, while also keeping track of the path taken.

## Table of Contents
- [Overview](#overview)
- [Input](#input)
- [Algorithm](#algorithm)
- [Code Explanation](#code-explanation)
  - [Structure Definition](#structure-definition)
  - [Function Declarations](#function-declarations)
  - [Main Function](#main-function)
  - [Min Function](#min-function)
  - [Recursive Path Printing Function](#recursive-path-printing-function)
- [Images](#images)

## Overview
The program calculates the minimum cost (time) required to process through a series of stations in two assembly lines. Each station in the assembly line has a processing time and a transfer time to switch between the assembly lines.

## Input
The input is provided as a 2D array `Q` which contains the processing times and transfer times for each station:
- The first and third rows contain processing times for the two assembly lines.
- The second and fourth rows contain transfer times between the two assembly lines.

## Algorithm
1. Initialize the entry times for both assembly lines.
2. Calculate the cost for each station iteratively for both assembly lines.
3. Use dynamic programming to store the minimum cost to reach each station.
4. Track the path taken to reach each station.
5. Calculate the total minimum cost including exit times.
6. Print the solution and path.

## Code Explanation

### Structure Definition
```c
struct Cost_Path_Info {
    int Cost;
    int Path;
};
```
This structure is used to store the cost and the path information. `Cost` holds the minimum cost, and `Path` indicates the previous assembly line.

### Function Declarations
```c
struct Cost_Path_Info min(int, int);
void printAssemblyLinePathRecursive(int[][6], int[][6], int, int);
```
- `min(int a, int b)`: Compares two costs and returns the minimum along with the corresponding path.
- `printAssemblyLinePathRecursive(int PathArray[][6], int Q[][6], int assemblyLine, int station)`: Recursively prints the path taken through the assembly lines.

### Main Function
```c
int main() {
    int Q[4][6] = {{7,9,3,4,8,4}, {2,3,1,3,4,3}, {2,1,2,2,1,2}, {8,5,6,4,5,7}};
    struct Cost_Path_Info CPI;
    int SolutionArray[2][6];
    int PathArray[2][6];
    int e1 = 2; // Entry Time At Station 1
    int e2 = 4; // Entry Time At Station 2

    SolutionArray[0][0] = e1 + Q[0][0]; // Base Case
    SolutionArray[1][0] = e2 + Q[3][0]; // Base Case
    PathArray[0][0] = 0;
    PathArray[1][0] = 1;

    for (int i = 1; i < 6; i++) {
        // For Assembly Line 1
        CPI = min(SolutionArray[0][i-1] + Q[0][i], SolutionArray[1][i-1] + Q[2][i-1] + Q[0][i]);
        SolutionArray[0][i] = CPI.Cost;
        PathArray[0][i] = (CPI.Path == 0) ? 0 : 1;

        // For Assembly Line 2
        CPI = min(SolutionArray[1][i-1] + Q[3][i], SolutionArray[0][i-1] + Q[1][i-1] + Q[3][i]);
        SolutionArray[1][i] = CPI.Cost;
        PathArray[1][i] = (CPI.Path == 0) ? 1 : 0;
    }

    SolutionArray[0][5] += Q[1][5]; // Adding the Exit Time
    SolutionArray[1][5] += Q[2][5]; // Adding the Exit Time

    // Print SolutionArray and PathArray
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d ", SolutionArray[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d ", PathArray[i][j]);
        }
        printf("\n");
    }

    int minTime = SolutionArray[0][5];
    int minPath = 0;
    if (SolutionArray[1][5] < minTime) {
        minTime = SolutionArray[1][5];
        minPath = 1;
    }

    printf("\nMinimum time: %d\n", minTime);
    printf("\nAssembly Line Path:\n");
    printAssemblyLinePathRecursive(PathArray, Q, minPath, 5);
    return 0;
}
```
- The main function initializes the processing times and computes the minimum cost for each station iteratively.
- It uses the `SolutionArray` to store the minimum cost to reach each station and `PathArray` to store the path taken.
- After computing the costs, it prints the `SolutionArray` and `PathArray`.
- It determines the minimum exit time and prints the corresponding path using the recursive function.

### Min Function
```c
struct Cost_Path_Info min(int a, int b) {
    struct Cost_Path_Info Ptr;
    if (a < b) {
        Ptr.Cost = a;
        Ptr.Path = 0;
    } else {
        Ptr.Cost = b;
        Ptr.Path = 1;
    }
    return Ptr;
}
```
This function compares two costs and returns the minimum cost along with the path taken.

### Recursive Path Printing Function
```c
void printAssemblyLinePathRecursive(int PathArray[][6], int Q[][6], int assemblyLine, int station) {
    if (station >= 0) {
        printAssemblyLinePathRecursive(PathArray, Q, PathArray[assemblyLine][station], station - 1);
        printf("Station %d, Assembly Line %d\n", station + 1, assemblyLine + 1);
    }
}
```
This function recursively prints the path taken through the assembly lines, starting from the last station and moving backward.

## Images
Here are the images of the assembly line schedule and its solution:

### Assembly Line Schedule
![Assembly Line Schedule](https://github.com/agneepradeep/Data-Structures-And-Algorithm-Analysis/blob/main/Algorithm%20Analysis/Dynamic%20Programming/Assembly%20Line%20Scheduling/Question.png))

### Solution
![Solution](https://github.com/agneepradeep/Data-Structures-And-Algorithm-Analysis/blob/main/Algorithm%20Analysis/Dynamic%20Programming/Assembly%20Line%20Scheduling/Answer.png))
