#include <stdio.h>
#include <string.h>

/**Function Header Declaration*/
void Longest_Common_Subsequence(char [],char [],int ,int);
int max(int ,int);

struct character_State{
    char direction;
    int max_occurance;
};

int main() {
    //char A[] = {'A','L','G','O','M','O','N','S','T','E','R','\0'};
    //char B[] = {'A','L','M','O','S','T','\0'};
    
    char A[] = {'Q','P','Q','R','R','\0'};
    char B[] = {'P','Q','P','R','Q','R','P','\0'};
    
    int A_Length = sizeof(A)/sizeof(A[0]) - 1;
    int B_Length = sizeof(B)/sizeof(B[0]) - 1;
    
    Longest_Common_Subsequence(A,B,A_Length,B_Length);
    
    return 0;
}

void Longest_Common_Subsequence(char A[],char B[],int X,int Y){
    struct character_State LCS_Table[Y+1][X+1];
    char Com_SubSeq[Y+1];
    
    for (int i = 0;i<Y+1;i++){
        LCS_Table[i][0].max_occurance = 0;
    }
    
    for (int j = 0;j<X+1;j++){
        LCS_Table[0][j].max_occurance = 0;
    }
    
    for(int i = 1;i<Y+1;i++){
        for(int j = 1;j<X+1;j++){
            if(B[i-1] == A[j-1]){
                LCS_Table[i][j].max_occurance = 1 + LCS_Table[i-1][j-1].max_occurance;
                LCS_Table[i][j].direction = 's';
            } else if (LCS_Table[i-1][j].max_occurance >= LCS_Table[i][j-1].max_occurance){
                LCS_Table[i][j].max_occurance = LCS_Table[i-1][j].max_occurance;
                LCS_Table[i][j].direction = 'u';
            } else {
                LCS_Table[i][j].max_occurance = LCS_Table[i][j-1].max_occurance;
                LCS_Table[i][j].direction = 'l';
            }
        }
    }
    printf("\n\n");
    for(int i = 0;i<Y+1;i++){
        for(int j = 0;j<X+1;j++){
            printf("%d, ",LCS_Table[i][j].max_occurance);
        }
        printf("\n");
    }
    
    printf("\nLength of Longest Common Subsequence :%d\n",LCS_Table[Y][X].max_occurance);
    
    int i = Y;
    int j = X;
    int index = LCS_Table[Y][X].max_occurance;
    char LCS[index + 1];
    LCS[index] = '\0';
    index -= 1;
    
    while (i > 0 && j > 0 && index >= 0) {
        if (LCS_Table[i][j].direction == 's') {
            LCS[index] = A[j-1];
            index--;
            i--;
            j--;
        } else if (LCS_Table[i][j].direction == 'u') {
            i--;
        } else {
            j--;
        }
    }
    
    printf("LCS Value :%s\n",LCS);
    
    return;
}
    
int max(int a,int b){
    return (a>b)?a:b;
}
