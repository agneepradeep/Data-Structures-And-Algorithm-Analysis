/**Importing Basic Header Files*/
#include <stdio.h> /**For Printing the Graph and Other Variables*/
#define MAX 100 /**For Defining Infinity as a value*/

/**Function Header Declaration*/
int min(int,int);

/**Defining The Main Function*/
int main(){
    int V = 5;
    
    int G[5][5] = {{0,3,8,MAX,-4},{MAX,0,MAX,1,7},{MAX,4,0,MAX,MAX},{2,MAX,-5,0,MAX},{MAX,MAX,MAX,6,0}};
    
    /**Floyd Warshall Algorithm*/
    {
        for(int k = 0;k<V;k++){
            printf("\nMATRIX A%d - {%d as Intermediate Node}\n",k+1,k+1);
            for(int i = 0;i<V;i++){
                for(int j = 0;j<V;j++){
                    G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
                    printf("%d ",G[i][j]);
                }
                printf("\n");
            }
        }
        
        /**Print All Pair Shortest Path Array*/
        printf("\nPrinting All Pair Shortest Path Array\n");
        for(int i = 0;i<V;i++){
            for(int j = 0;j<V;j++){
                printf("%d ",G[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

int min(int x,int y){
    return (x > y)? y : x ; 
}
