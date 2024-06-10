```markdown
# Matrix Chain Multiplication

This program calculates the minimum number of multiplications needed to multiply a chain of matrices together efficiently using dynamic programming.

## Table of Contents
- [Overview](#overview)
- [Input](#input)
- [Algorithm](#algorithm)
- [Code Explanation](#code-explanation)
  - [Matrix Chain Order Function](#matrix-chain-order-function)
  - [Main Function](#main-function)

## Overview
Matrix chain multiplication is a classical problem in dynamic programming. Given a sequence of matrices, the goal is to find the most efficient way to multiply these matrices together, minimizing the total number of scalar multiplications required.

## Input
The input consists of the number of matrices and their dimensions. The dimensions are provided in the format (row col), indicating the number of rows and columns for each matrix.

## Algorithm
The algorithm used to solve the matrix chain multiplication problem is based on dynamic programming. It involves filling up a table with the minimum number of scalar multiplications needed to multiply each subchain of matrices together.

## Code Explanation

### Matrix Chain Order Function
```c
int MatrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;
    // Initialization
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    // Print cost array
    printf("Cost Array :\n");
    for(int i = 1; i<n;i++){
        for(int j = 1;j<n;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    // Print path array
    printf("\nPath Array :\n");
    for(int i = 1; i<n;i++){
        for(int j = 1;j<n;j++){
            printf("%d ",ki[i][j]);
        }
        printf("\n");
    }
    return m[1][n - 1];
}
```
- This function calculates the minimum number of scalar multiplications needed to multiply the matrices.
- It initializes a matrix `m` to store the results of subproblems.
- It iterates over all subchains of matrices and fills up the `m` matrix using the dynamic programming approach.
- It prints the cost array and path array for visualization.

### Main Function
```c
int main() {
    int numMatrices;
    printf("Enter the number of matrices: ");
    scanf("%d", &numMatrices);

    int dimensions[numMatrices + 1];
    // Input dimensions of matrices
    printf("Enter the dimensions of matrices in the format (row col):\n");
    for (int i = 0; i < numMatrices; i++) {
        printf("Matrix %d: ", i + 1);
        scanf("%d %d", &dimensions[i], &dimensions[i + 1]);
    }
    // Print dimensions
    for(int i = 0; i<numMatrices+1;i++){
        printf("%d,",dimensions[i]);
    }
    // Calculate minimum multiplications
    printf("\nThe minimum number of multiplications needed is %d\n", MatrixChainOrder(dimensions, numMatrices + 1));

    return 0;
}
```
- This function handles user input and calls the `MatrixChainOrder` function to calculate the minimum number of multiplications.
- It prompts the user to enter the number of matrices and their dimensions.
- It prints the dimensions entered by the user.
- It prints the minimum number of multiplications calculated by the `MatrixChainOrder` function.

```
