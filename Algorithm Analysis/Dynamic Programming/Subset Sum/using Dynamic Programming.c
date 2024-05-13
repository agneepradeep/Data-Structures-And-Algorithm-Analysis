#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**Function Header Declaration*/
bool SubsetSum(int [],int,int);

int main(){
    //int S[] = {6,3,2,1};
    //int Sum = 5;
    
    int S[] = { 3, 34, 4, 12, 5, 2 };
    int Sum = 9;
    
    int S_Length = sizeof(S)/sizeof(S[0]);
    
    bool Status_Check = SubsetSum(S,S_Length,Sum);
    
    printf("\nSubset Sum Value %d Possibility :%s\n",Sum,Status_Check?"True":"False");
    
    return 0;
}

bool SubsetSum(int S[],int Size,int Sum){
    bool Sum_Array[Size+1][Sum+1];
    
    for(int i = 0;i<Size+1;i++){
        Sum_Array[i][0] = true;
    }
    
    for(int j = 1;j<Sum+1;j++){
        Sum_Array[0][j] = false;
    }
    
    for(int i = 1;i<Size+1;i++){
        
        for(int j = 1;j<Sum+1;j++){
            
            int TempSum = j;
            
            if(S[i-1] > TempSum && i-1 == 0){
                Sum_Array[i][j] = false;
                
            } else{
                TempSum -= S[i-1];
                
                if(TempSum == 0){
                    Sum_Array[i][j] = true;
                } else {
                    Sum_Array[i][j] = Sum_Array[i-1][TempSum] || Sum_Array[i-1][TempSum+S[i-1]];
                }
            }
        }
    }
    
    printf("\n");
    for(int i = 0;i<Size+1;i++){
        for(int j =0;j<Sum+1;j++){
            printf("%s ",Sum_Array[i][j]?"T":"F");
        }
        printf("\n");
    }
    
    return Sum_Array[Size][Sum];
}
