/*Recursive Linear Search Algorithm*/

#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int [],int,int,int);

int main(){
    int S;

    printf("Type Size of Array :");
    scanf("%d",&S);

    int *ArrayPointer;
    ArrayPointer = (int *)malloc(sizeof(int)*S);

    printf("\n");
    int j,P;
    for (j = 0;j < S; j++){
        printf("Element At %d Position :",j);
        scanf("%d",&P);
        *(ArrayPointer + j) = P;
    }

    int E;
    printf("\nType Element To be Searched :");
    scanf("%d",&E);

    int i = 0;
    if (LinearSearch(ArrayPointer,E,S,i) == 0){
        printf("\nElement is Not in Array\n");
    }
    else{
        printf("\nElement is in Array\n");
    }
    return 0;
}

int LinearSearch(int A[],int Size,int Element,int I){
    if (I == (Size)){
        return 0;
    }
    else if (A[I] == Element){
        return 1;
    }
    else{
        I = I + 1;
        LinearSearch(A,Size,Element,I);
    }
}