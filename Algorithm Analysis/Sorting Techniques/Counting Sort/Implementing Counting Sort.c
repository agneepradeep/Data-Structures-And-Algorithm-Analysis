/*Implementing Counting Sort*/

#include <stdio.h>
#include <stdlib.h>

/*Function Prototypes*/
void ReadElements(int [],int);
void DisplayArray(int [],int);
void CountingSort(int [],int);

int main(){
    int *ArrayPointer;
    int Size;

    printf("Type Array Size :");
    scanf("%d",&Size);

    ArrayPointer = (int *)malloc(sizeof(int)*Size);

    ReadElements(ArrayPointer,Size);

    printf("\nUnsorted Array :");
    DisplayArray(ArrayPointer,Size);

    CountingSort(ArrayPointer,Size);

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

void CountingSort(int A[],int S){
    int MaxElement,i,j,Sum;
    MaxElement = A[0];
    i = 1;
    while (i != S){
        if (MaxElement < A[i]){
            MaxElement = A[i];
        }
        i = i + 1;
    }

    int CountArray[MaxElement + 1];
    i = 0;
    while (i != MaxElement + 1){
        CountArray[i] = 0;
        i = i + 1;
    }

    i = 0;
    while (i != S){
        CountArray[A[i]] += 1;
        i = i + 1;
    }

    Sum = CountArray[0];
    i = 1;
    while (i != MaxElement + 1){
        Sum += CountArray[i];
        CountArray[i] = Sum;
        i = i + 1; 
    }

    int B[S];
    i = 0;
    while (i != S){
        CountArray[A[i]] -= 1;
        B[CountArray[A[i]]] = A[i];
        i = i + 1;
    }

    i = 0;
    while (i != S){
        A[i] = B[i];
        i = i + 1;
    }
}