#include <stdio.h>
#include <math.h>
#include <stdbool.h>
/**Function Header Files*/
void printHeap(int *, int);
void buildMaxHeap(int [], int);
void buildMinHeap(int [],int);
void maxHeapify(int [], int, int *);
void minHeapify(int [],int,int *);
int extractMax(int [],int *);
int extractMin(int [],int *);
void increaseKey(int [],int,int);
void decreaseKey(int [],int,int);
void insertElement(int [],int,int *);

const int arraySize = 30;
bool heapState = true; /**True for Max Heap and False for MinHeap*/
/**Main.c*/
int main()
{
    int heapExample[arraySize];
    
    /**Feeling Entries in Array*/
    //int heapExample[8] = {9, 6, 5, 0, 8, 2, 1, 3};
    heapExample[0] = 9;
    heapExample[1] = 6;
    heapExample[2] = 5;
    heapExample[3] = 0;
    heapExample[4] = 8;
    heapExample[5] = 2;
    heapExample[6] = 1;
    heapExample[7] = 3;
    
    int heapSize = 8;
    
    int choice = 1;
    do{
        printf("\nMENU\n");
        printf("1. Build Max Heap\n");
        printf("2. Build Min Heap\n");
        printf("3. Extract Max Element( Max Heap )\n");
        printf("4. Extract Min Element( Min Heap )\n");
        printf("5. Increase Key( Max Heap )\n");
        printf("6. Decrease Key( Min Heap )\n");
        printf("7. Insert Element\n");
        printf("0. Exit\n");
        
        scanf("%d",&choice);
        
        if(choice == 1){
            printf("Array Before MaxHeap :");
            printHeap(heapExample, heapSize);
            
            buildMaxHeap(heapExample, heapSize);
            printf("\nMax Heap :");
            printHeap(heapExample, heapSize);
            
        } else if(choice == 2){
            printf("Array Before MinHeap :");
            printHeap(heapExample, heapSize);
            
            buildMinHeap(heapExample, heapSize);
            printf("\nMin Heap :");
            printHeap(heapExample, heapSize);
            
        } else if(choice == 3){
            int maxElement = extractMax(heapExample,&heapSize);
            if(maxElement >= 0){
                printf("Maximum Element :%d",maxElement);
                printf("\nHeap :");
                printHeap(heapExample,heapSize);
            }
        } else if(choice == 4){
            int minElement = extractMin(heapExample, &heapSize);
            if(minElement >= 0){
                printf("Minimum Element :%d",minElement);
                printf("\nHeap :");
                printHeap(heapExample,heapSize);
            }
        } else if(choice == 5){
            int incrky;
            int index;
            printf("Index , IncreaseKey :");
            scanf("%d %d",&index,&incrky);
            
            printf("MaxHeap before Increasing Key :");
            printHeap(heapExample,heapSize);
            
            increaseKey(heapExample,index,incrky);
            printf("\nMax Heap :");
            printHeap(heapExample,heapSize);
            
        } else if(choice == 6){
            int decrky;
            int index;
            printf("Index , DecreaseKey :");
            scanf("%d %d",&index,&decrky);
            
            printf("MaxHeap before Increasing Key :");
            printHeap(heapExample,heapSize);
            
            decreaseKey(heapExample,index,decrky);
            printf("\nMax Heap :");
            printHeap(heapExample,heapSize);
            
        } else if(choice == 7){
            int element;
            scanf("%d",&element);
            
            printf("Heap before Insertion :");
            printHeap(heapExample,heapSize);
            
            insertElement(heapExample,element,&heapSize);
            printf("Heap after Insertion :");
            printHeap(heapExample,heapSize);
            
        }
    }while(choice != 0);
    return 0;
}

void buildMaxHeap(int A[], int size)
{
    int parentNodeIndex = floor(size / 2.0);
    for (int i = parentNodeIndex; i >= 0; i--)
    {
        maxHeapify(A, i, &size);
    }
    heapState = true;
}

void buildMinHeap(int A[],int size){
    int parentNodeIndex = floor(size/2.0);
    for(int i = parentNodeIndex;i>=0;i--){
        minHeapify(A,i,&size);
    }
    heapState = false;
}

void maxHeapify(int A[], int i, int* heapSize)
{
    int leftChildNode = 2 * i + 1;
    int rightChildNode = 2 * i + 2;
    int largest = i;

    if (leftChildNode < *heapSize && A[leftChildNode] > A[largest])
    {
        largest = leftChildNode;
    }

    if (rightChildNode < *heapSize && A[rightChildNode] > A[largest])
    {
        largest = rightChildNode;
    }

    if (largest != i)
    {
        /**Swapping the nodes*/
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        maxHeapify(A, largest, heapSize);
    }
}

void minHeapify(int A[],int i,int* heapSize){
    int leftChildNode = 2*i+1;
    int rightChildNode = 2*i+2;
    int smallest = i;

    if(leftChildNode < *heapSize && A[leftChildNode] < A[i]){
        smallest = leftChildNode;
    }
    
    if(rightChildNode < *heapSize && A[rightChildNode] < A[smallest]){
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

int extractMax(int A[],int* heapSize){
    if(*heapSize ==0){
        printf("Heap UnderFlow\n");
        return -1;
    } else{
        int Max = A[0];
        A[0] = A[*heapSize - 1];
        A[*heapSize - 1] = 0;
        *heapSize -= 1;
        maxHeapify(A,0,heapSize);
        return Max;
    }   
}

int extractMin(int A[],int* heapSize){
    if(*heapSize == 0){
        printf("Heap UnderFlow\n");
        return -1;
    } else {
        int Min = A[0];
        A[0] = A[*heapSize - 1];
        A[*heapSize - 1] = 0;
        *heapSize -= 1;
        minHeapify(A,0,heapSize);
        return Min;
    }
}

void increaseKey(int A[],int i,int key){
    if(A[i] > key){
        printf("Error\n");
        return;
    } else {
        A[i] = key;
        while(i >= 0 && A[(int)floor(i/2.0)] < A[i]){
            int temp = A[i];
            A[i] = A[(int)floor(i/2.0)];
            A[(int)floor(i/2.0)] = temp;
            i = floor(i/2.0);
        }
    }
}

void decreaseKey(int A[],int i,int key){
    if(A[i] < key){
        printf("Error\n");
        return;
    } else {
        A[i] = key;
        while(i >= 0 && A[(int)floor(i/2.0)] > A[i]){
            int temp = A[i];
            A[i] = A[(int)floor(i/2.0)];
            A[(int)floor(i/2.0)] = temp;
            i = floor(i/2.0);
        }
    }
}

void insertElement(int A[],int Element,int *heapSize){
    if(*heapSize == arraySize-1){
        printf("Heap Overflow\n");
    } else {
        A[*heapSize] = Element;
        *heapSize += 1;
        int i = *heapSize-1;
        if(heapState){ //for maxHeap
            while(i > 0 && A[(int)floor((i-1)/2.0)] < A[i]){
                int temp = A[i];
                A[i] = A[(int)floor((i-1)/2.0)];
                A[(int)floor((i-1)/2.0)] = temp;
                i = floor((i-1)/2.0);
            }
        } else { // for minHeap
            while(i > 0 && A[(int)floor((i-1)/2.0)] > A[i]){
                int temp = A[i];
                A[i] = A[(int)floor((i-1)/2.0)];
                A[(int)floor((i-1)/2.0)] = temp;
                i = floor((i-1)/2.0);
            }
        }
    }
    return;
}

void printHeap(int *heap, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            printf("%d ", *(heap + i));
        }
        else
        {
            printf("%d, ", *(heap + i));
        }
    }
    printf("]\n");
}

