#include <stdio.h>
#include <math.h>

/**Function Header Files*/
void printHeap(int [] ,int);
void buildMaxHeap(int [],int);
void minHeapify(int [],int,int);

/**Main.c*/
int main(){
    int heapExample[8] = {9,6,5,0,8,2,1,3};
    int heapSize = sizeof(heapExample)/sizeof(heapExample[0]);
    printHeap(heapExample,heapSize);
    buildMaxHeap(heapExample,heapSize);
    printHeap(heapExample,heapSize);
    return 0;
}

void buildMaxHeap(int A[],int size){
	int i;
    int parentNodeIndex = floor(size/2.0);
    for(i = parentNodeIndex;i>=0;i--){
        maxHeapify(A,i,size);
    }
}

void maxHeapify(int A[],int i,int heapSize){
    int leftChildNode = 2*i+1;
    int rightChildNode = 2*i+2;
    int largest = i;

    if(leftChildNode < heapSize && A[leftChildNode] > A[largest]){
        largest = leftChildNode;
    }
    
    if(rightChildNode < heapSize && A[rightChildNode] > A[largest]){
        largest = rightChildNode;
    }
    
    if(largest != i){
        
        /**Swapping the nodes*/
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        
        maxHeapify(A,largest,heapSize);
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
