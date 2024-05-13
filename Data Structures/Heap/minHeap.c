#include <stdio.h>
#include <math.h>

/**Function Header Files*/
void printHeap(int [] ,int);
void buildMinHeap(int [],int);
void minHeapify(int [],int,int);

/**Main.c*/
int main(){
    int heapExample[8] = {9,6,5,0,8,2,1,3};
    int heapSize = sizeof(heapExample)/sizeof(heapExample[0]);
    printHeap(heapExample,heapSize);
    buildMinHeap(heapExample,heapSize);
    printHeap(heapExample,heapSize);
    return 0;
}

void buildMinHeap(int A[],int size){
	int i;
    int parentNodeIndex = floor(size/2.0);
    for(i = parentNodeIndex;i>=0;i--){
        minHeapify(A,i,size);
    }
}

void minHeapify(int A[],int i,int heapSize){
    int leftChildNode = 2*i+1;
    int rightChildNode = 2*i+2;
    int smallest = i;

    if(leftChildNode < heapSize && A[leftChildNode] < A[i]){
        smallest = leftChildNode;
    }
    
    if(rightChildNode < heapSize && A[rightChildNode] < A[smallest]){
        smallest = rightChildNode;
    }
    
    if(smallest != i){
        
        /**Swapping the nodes*/
        int temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
        
        minHeapify(A,smallest,heapSize);
    }
    
}

void printHeap(int heap[],int size){
	int i;
    printf("[");
    for(i = 0;i<size;i++){
        if(i == size-1){
            printf("%d ",heap[i]);
        } else{
            printf("%d, ",heap[i]);
        }
    }
    printf("]\n");
}
