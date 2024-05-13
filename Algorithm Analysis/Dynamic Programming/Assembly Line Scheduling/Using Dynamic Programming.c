#include <stdio.h>
#include <math.h>

struct Cost_Path_Info{
    int Cost;
    int Path;
};

/**Function Header Declaration*/
struct Cost_Path_Info min(int,int);
void printAssemblyLinePathRecursive(int[][6], int[][6], int, int);

int main(){
    
    /**Question*/
    int Q[4][6] = {{7,9,3,4,8,4},{2,3,1,3,4,3},{2,1,2,2,1,2},{8,5,6,4,5,7}};
    
    struct Cost_Path_Info CPI;
    
    int SolutionArray[2][6];
    int PathArray[2][6];
    
    int e1 = 2; //Entry Time At Station 1
    int e2 = 4; //Entry Time At Station 2
    
    SolutionArray[0][0] = e1 + Q[0][0]; //Base Case
    SolutionArray[1][0] = e2 + Q[3][0]; //Base Case
    PathArray[0][0] = 0;
    PathArray[1][0] = 1;
    
    for(int i = 1;i<6;i++){
        
        /**For Assembly Line 1*/
        CPI = min(SolutionArray[0][i-1] + Q[0][i], SolutionArray[1][i-1] + Q[2][i-1] + Q[0][i]);
        
        SolutionArray[0][i] = CPI.Cost;
        PathArray[0][i] = (CPI.Path == 0) ? 0 : 1;
        
        /**For Assembly Line 2*/
        CPI = min(SolutionArray[1][i-1] + Q[3][i],SolutionArray[0][i-1] + Q[1][i-1] + Q[3][i]);
        
        SolutionArray[1][i] = CPI.Cost;
        PathArray[1][i] = (CPI.Path == 0) ? 1 : 0;
        
    }
    
    SolutionArray[0][5] += Q[1][5]; //Adding the Exit Time
    SolutionArray[1][5] += Q[2][5]; //Adding the Exit Time
    
    for(int i = 0;i<2;i++){
        for(int j = 0;j<6;j++){
            printf("%d ",SolutionArray[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    for(int i = 0;i<2;i++){
        for(int j = 0;j<6;j++){
            printf("%d ",PathArray[i][j]);
        }
        printf("\n");
    }
    int minTime = SolutionArray[0][5];
    int minPath = 0;
    if (SolutionArray[1][5] < minTime) {
        minTime = SolutionArray[1][5];
        minPath = 1;
    }
    
    printf("\nMinimum time: %d\n", minTime);
    
    printf("\nAssembly Line Path:\n");
    printAssemblyLinePathRecursive(PathArray, Q, minPath, 5);
    return 0;
}

struct Cost_Path_Info min(int a,int b){
    struct Cost_Path_Info Ptr;
    if(a<b){
        Ptr.Cost = a;
        Ptr.Path = 0;
    } else {
        Ptr.Cost = b;
        Ptr.Path = 1;
    }
    return Ptr;
}

void printAssemblyLinePathRecursive(int PathArray[][6], int Q[][6], int assemblyLine, int station) {
    if (station >= 0) {
        printAssemblyLinePathRecursive(PathArray, Q, PathArray[assemblyLine][station], station - 1);
        printf("Station %d, Assembly Line %d\n", station + 1, assemblyLine + 1);
    }
}
