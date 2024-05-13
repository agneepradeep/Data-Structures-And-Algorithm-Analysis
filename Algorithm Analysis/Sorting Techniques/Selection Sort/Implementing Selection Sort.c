/*Implementing Selection Sort*/

#include <stdio.h>
#include <stdlib.h>

/*Function Prototypes*/
void ReadElements(int [],int);
void DisplayArray(int [],int);
void SelectionSort(int [],int);
void Swap(int *,int *);

int main(){
    int *ArrayPointer;
    int Size;

    printf("Type Array Size :");
    scanf("%d",&Size);

    ArrayPointer = (int *)malloc(sizeof(int)*Size);

    ReadElements(ArrayPointer,Size);

    printf("\nUnsorted Array :");
    DisplayArray(ArrayPointer,Size);

    SelectionSort(ArrayPointer,Size);

    printf("\nSorted Array :");
    DisplayArray(ArrayPointer,Size);

    return 0;
}

void ReadElements(int A[],int S){
    int i,E;
    while (i != S){
        printf("%dth Element :",i);
        scanf("%d",&E);
        A[i] = E;
        i = i + 1;
    }
}

void DisplayArray(int A[],int S){
    int i;
    printf("{");
    while (i != S){
        if(i == S-1){
            printf("%d",A[i]);
        }
        else{
            printf("%d, ",A[i]);
        }
        i = i + 1;
    }
    printf("}");
}

void SelectionSort(int A[],int S){
    int i = 0,j,k;
    int Min;
    while (i != S){
        Min = A[i];
        j = i + 1;
        k = j;
        while (j != S){
            if (Min > A[j]){
                Min = A[j];
                k = j;
            }
            j = j + 1;
        }
        if (A[i] > A[k]){
            Swap(A+i,A+k);
        }
        i = i + 1;
    }
}

void Swap(int *A,int *B){
    *A = *A + *B;
    *B = *A - *B;
    *A = *A - *B;
}