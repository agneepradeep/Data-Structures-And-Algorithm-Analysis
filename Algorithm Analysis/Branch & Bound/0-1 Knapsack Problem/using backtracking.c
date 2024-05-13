#include <stdio.h>

struct modifiedArray{
    int weight;
    int profit;
    int status;
};

/**Function Header Declaration*/
void knapsack(struct modifiedArray [],int,int,int,int);
void printItemCombination(struct modifiedArray [],int);

int main(){
    struct modifiedArray Test[6];
    
    Test[0].weight = 7;
    Test[1].weight = 4;
    Test[2].weight = 3;
    Test[3].weight = 5;
    Test[4].weight = 2;
    Test[5].weight = 9;
    
    Test[0].profit = 7;
    Test[1].profit = 4;
    Test[2].profit = 3;
    Test[3].profit = 5;
    Test[4].profit = 2;
    Test[5].profit = 9;
    
    int TestArray_Length = sizeof(Test)/sizeof(Test[0]);
    
    int sackCapacity = 15;
    int StartIndex = 0;
    
    knapsack(Test, sackCapacity, 0, StartIndex,TestArray_Length);
    return 0;
}

void knapsack(struct modifiedArray R[], int M,int Sum,int index,int Size){
    if(index == Size){
        if(Sum == M){
            printItemCombination(R,Size);
        }
        return;
    }
    else{
        if(Sum < M){
            //Including Current Element
            R[index].status = 1;
            knapsack(R, M, Sum + R[index].weight, index + 1, Size);
    
            //Excluding Current Element
            R[index].status = 0;
            knapsack(R, M, Sum, index+1, Size);
            
        } else if(Sum > M){
            return;
        } else{
            printItemCombination(R,Size);
            return;
        }
    }
}

void printItemCombination(struct modifiedArray P[], int size) {
    int hasElement = 0; // To check if there is at least one element in the subset
    int sum = 0;
    printf("{");
    for (int i = 0; i < size; i++) {
        if (P[i].status == 1) {
            if (hasElement == 1) {
                printf(", ");
            }
            printf("%d", P[i].weight);
            sum += P[i].profit;
            hasElement = 1;
        }
    }
    printf("} - %d\n",sum);
}
