/*Implementing Insertion Sort*/

#include <stdio.h>
#include <stdlib.h>

/*Function Prototypes*/
void InsertionSort(int [],int);
void ReadElements(int [],int);
void DisplayArray(int [],int);
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

    InsertionSort(ArrayPointer,Size);

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

void InsertionSort(int A[],int S){
    int i = 1,j;
    while (i != S){
        j = i;
        while (A[j] < A[j - 1]){
            Swap(A+j,A+j - 1);
            j = j - 1;
        }
        i = i + 1;
    }
}

void Swap(int *A,int *B){
    *A = *A + *B;
    *B = *A - *B;
    *A = *A - *B;
}