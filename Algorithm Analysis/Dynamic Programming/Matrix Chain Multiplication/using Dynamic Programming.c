#include <limits.h>
#include <stdio.h>

int MatrixChainOrder(int p[], int n) {
    int m[n][n];

    int i, j, k, L, q;

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
	
	printf("\n");
    printf("Cost Array :\n");
    for(int i = 1; i<n;i++){
        for(int j = 1;j<n;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    printf("Path Array :\n");
    for(int i = 1; i<n;i++){
        for(int j = 1;j<n;j++){
            printf("%d ",ki[i][j]);
        }
        printf("\n");
    }
    
    return m[1][n - 1];
}

int main() {
    int numMatrices;

    printf("Enter the number of matrices: ");
    scanf("%d", &numMatrices);

    int dimensions[numMatrices + 1];

    printf("Enter the dimensions of matrices in the format (row col):\n");
    for (int i = 0; i < numMatrices; i++) {
        printf("Matrix %d: ", i + 1);
        scanf("%d %d", &dimensions[i], &dimensions[i + 1]);
    }
    
    for(int i = 0; i<numMatrices+1;i++){
        printf("%d,",dimensions[i]);
    }

    printf("\nThe minimum number of multiplications needed is %d\n", MatrixChainOrder(dimensions, numMatrices + 1));

    return 0;
}
