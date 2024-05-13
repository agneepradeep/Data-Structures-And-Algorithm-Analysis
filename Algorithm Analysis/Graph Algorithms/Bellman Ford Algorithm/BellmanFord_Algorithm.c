/**Importing Basic Header Files*/
#include <stdio.h> /**For Printing the Graph and Other Variables*/
#include <math.h>  /**For Defining Infinity as a value*/
#include <string.h> /**For Defining Vertex By Their Names*/
#include <stdbool.h> /**For Identifying Whether Vertex Path Vakue Updated or not*/

/**Defininig Node Data Structure*/
struct Node{
    int shortestPath; /**Shortest Path*/
    char vertexName; /**Vertex Name*/
};

/**Function Header Declaration*/
bool bellmanFord(int* ,int , struct Node []);

/**Defining The Main Function*/
int main(){
    int vertex = 5;
    char vertexNameArray[5] = {'A','B','C','D','E','\0'};
    
    int graph[5][5] = {{0,10,0,0,3},{0,0,2,0,4},{0,0,0,9,0},{0,0,7,0,0},{0,1,8,2,0}};
    
    /**Defining Graph Vertices in Array*/
    struct Node vertexArray[5];
    vertexArray[0].shortestPath = 0; /**Source Vertex*/
    vertexArray[0].vertexName = 'A'; /**Source Vertex Name*/
    
    vertexArray[1].shortestPath = (int)INFINITY;
    vertexArray[1].vertexName = 'B';
    
    vertexArray[2].shortestPath = (int)INFINITY;
    vertexArray[2].vertexName = 'C';
    
    vertexArray[3].shortestPath = (int)INFINITY;
    vertexArray[3].vertexName = 'D';
    
    vertexArray[4].shortestPath = (int)INFINITY;
    vertexArray[4].vertexName = 'E';
    
    bool negativeCycle = bellmanFord((int *)graph, vertex, vertexArray);
    
    if(!negativeCycle){
        printf("Negative Cycle Detected\n");
    } else {
        for(int i = 1;i<vertex;i++){
            printf("%c-%c : %d\n",vertexArray[0].vertexName,vertexArray[i].vertexName,vertexArray[i].shortestPath);
        }
    }
    
}

bool bellmanFord(int* M,int N, struct Node VA[]){
    bool updateShortestPath = false;
    
    for(int k = 0;k<=N;k++){
        updateShortestPath = false;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(*((M+i*N)+j) != 0){
                    if(VA[j].shortestPath > (*((M+i*N)+j) + VA[i].shortestPath)){
                        updateShortestPath = true;
                        VA[j].shortestPath = *((M+i*N)+j) + VA[i].shortestPath;
                    }
                }
            }    
        }
        if(updateShortestPath == false){
            return true;
        } else if(k == N && updateShortestPath == true){
            return false;
        }
    }
}
