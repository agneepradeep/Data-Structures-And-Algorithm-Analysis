/*Implementing Quick Sort*/

#include <stdio.h>
#include <stdlib.h>

/*Function Prototypes*/
void ReadElements(int [],int);
void DisplayArray(int [],int);
void QuickSort(int [],int,int);
int Partition(int [],int,int);
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

    QuickSort(ArrayPointer,0,Size-1);

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

void QuickSort(int A[],int L,int H){
    int PI;
    if (L<H){
        PI = Partition(A,L,H);
        QuickSort(A,L,PI - 1);
        QuickSort(A,PI+1,H);
    }
}

int Partition(int A[],int S,int E){
    int Pivot = A[E];
    int I = S-1;
    int j;

    for(j = S;j<=E-1;j++){
        if (A[j] < Pivot){
            I = I + 1;
            Swap(A+I,A+j);
        }
    }
    Swap(A+I+1,A+E);
    return (I+1);
}

void Swap(int *A,int *B){
    int T = *A;
    *A = *B;
    *B = T;
}