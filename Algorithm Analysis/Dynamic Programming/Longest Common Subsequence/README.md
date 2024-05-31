```markdown
# Longest Common Subsequence (LCS) Algorithm

This program finds the longest common subsequence between two given strings using dynamic programming.

## Table of Contents
- [Overview](#overview)
- [Input](#input)
- [Algorithm](#algorithm)
- [Code Explanation](#code-explanation)
  - [Function Header Declaration](#function-header-declaration)
  - [Structure Definition](#structure-definition)
  - [Main Function](#main-function)
  - [Longest Common Subsequence Function](#longest-common-subsequence-function)
  - [Max Function](#max-function)

## Overview
The program calculates the longest common subsequence between two strings. The LCS of two strings is the longest sequence that can be derived from both strings by deleting some characters (without reordering the remaining characters).

## Input
The input consists of two character arrays `A` and `B`, representing the two strings. 

```c
char A[] = {'Q','P','Q','R','R','\0'};
char B[] = {'P','Q','P','R','Q','R','P','\0'};
```

## Algorithm
1. Initialize a table to store the lengths of longest common subsequences of substrings.
2. Iterate through both strings and fill the table according to the following rules:
   - If characters match, add 1 to the diagonal value.
   - If characters don't match, take the maximum value from either the left or the top cell.
3. Use the table to backtrack and find the longest common subsequence.

## Code Explanation

### Function Header Declaration
```c
void Longest_Common_Subsequence(char [], char [], int, int);
int max(int, int);
```
- `Longest_Common_Subsequence`: Function to calculate and print the longest common subsequence.
- `max`: Helper function to return the maximum of two integers.

### Structure Definition
```c
struct character_State {
    char direction;
    int max_occurance;
};
```
This structure holds two fields:
- `direction`: Indicates the direction of the cell from which the current cell value is derived ('s' for diagonal, 'u' for up, 'l' for left).
- `max_occurance`: Stores the length of the longest common subsequence up to the current cell.

### Main Function
```c
int main() {
    char A[] = {'Q','P','Q','R','R','\0'};
    char B[] = {'P','Q','P','R','Q','R','P','\0'};
    
    int A_Length = sizeof(A)/sizeof(A[0]) - 1;
    int B_Length = sizeof(B)/sizeof(B[0]) - 1;
    
    Longest_Common_Subsequence(A, B, A_Length, B_Length);
    
    return 0;
}
```
- Defines the two input strings `A` and `B`.
- Calculates the lengths of the strings.
- Calls the `Longest_Common_Subsequence` function.

### Longest Common Subsequence Function
```c
void Longest_Common_Subsequence(char A[], char B[], int X, int Y) {
    struct character_State LCS_Table[Y+1][X+1];
    
    for (int i = 0; i < Y+1; i++) {
        LCS_Table[i][0].max_occurance = 0;
    }
    
    for (int j = 0; j < X+1; j++) {
        LCS_Table[0][j].max_occurance = 0;
    }
    
    for (int i = 1; i < Y+1; i++) {
        for (int j = 1; j < X+1; j++) {
            if (B[i-1] == A[j-1]) {
                LCS_Table[i][j].max_occurance = 1 + LCS_Table[i-1][j-1].max_occurance;
                LCS_Table[i][j].direction = 's';
            } else if (LCS_Table[i-1][j].max_occurance >= LCS_Table[i][j-1].max_occurance) {
                LCS_Table[i][j].max_occurance = LCS_Table[i-1][j].max_occurance;
                LCS_Table[i][j].direction = 'u';
            } else {
                LCS_Table[i][j].max_occurance = LCS_Table[i][j-1].max_occurance;
                LCS_Table[i][j].direction = 'l';
            }
        }
    }
    
    printf("\nLength of Longest Common Subsequence: %d\n", LCS_Table[Y][X].max_occurance);
    
    int i = Y;
    int j = X;
    int index = LCS_Table[Y][X].max_occurance;
    char LCS[index + 1];
    LCS[index] = '\0';
    index -= 1;
    
    while (i > 0 && j > 0 && index >= 0) {
        if (LCS_Table[i][j].direction == 's') {
            LCS[index] = A[j-1];
            index--;
            i--;
            j--;
        } else if (LCS_Table[i][j].direction == 'u') {
            i--;
        } else {
            j--;
        }
    }
    
    printf("LCS Value: %s\n", LCS);
}
```
- Initializes the `LCS_Table` to store lengths of common subsequences and directions.
- Fills the table by comparing characters from `A` and `B`.
- Prints the length of the longest common subsequence.
- Backtracks to find and print the longest common subsequence.

### Max Function
```c
int max(int a, int b) {
    return (a > b) ? a : b;
}
```
- Returns the maximum of two integers.
