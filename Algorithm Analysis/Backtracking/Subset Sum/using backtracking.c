#include <stdio.h>

struct modifiedArray{
    int x;
    int s;
};

/**Function Header Declaration*/
void SubsetSum(struct modifiedArray [],int,int,int,int);
void printSubset(struct modifiedArray [],int);

int main(){
    struct modifiedArray Test[6];
    
    Test[0].x = 2;
    Test[1].x = 3;
    Test[2].x = 4;
    Test[3].x = 5;
    Test[4].x = 12;
    Test[5].x = 34;
    
    int TestArray_Length = sizeof(Test)/sizeof(Test[0]);
    
    int SumRequired = 9;
    int Sum = 0;
    int StartIndex = 0;
    
    SubsetSum(Test,SumRequired, Sum, StartIndex,TestArray_Length);
    return 0;
}

void SubsetSum(struct modifiedArray R[], int M,int Sum,int index,int Size){
    if(index == Size){
        if(Sum == M){
            printSubset(R,Size);
        }
        return;
    }
    else{
        if(Sum < M){
            //Including Current Element
            R[index].s = 1;
            SubsetSum(R, M, Sum + R[index].x, index + 1, Size);
    
            //Excluding Current Element
            R[index].s = 0;
            SubsetSum(R, M, Sum, index+1, Size);
            
        } else if(Sum > M){
            return;
        } else{
            printSubset(R,Size);
            return;
        }
    }
}

void printSubset(struct modifiedArray P[], int size) {
    int hasElement = 0; // To check if there is at least one element in the subset

    printf("{");
    for (int i = 0; i < size; i++) {
        if (P[i].s == 1) {
            if (hasElement == 1) {
                printf(", ");
            }
            printf("%d", P[i].x);
            hasElement = 1;
        }
    }
    printf("}\n");
}
