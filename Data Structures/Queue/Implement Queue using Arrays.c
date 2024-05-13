/*Assessment - 1
22BCI0198_Agneepradeep_Verma*/

#include <stdio.h>
void Enqueue(int [],int,int *,int *,int);
int Dequeue(int [],int *,int *,int);
int isfull(int ,int ,int);
int isempty(int ,int ,int);
int N;	
int front = -1,rear = -1,choice,Element,i;
int main(){
	printf("Type the size limit for queue :");
	scanf("%d",&N);
	int Queue[N];
	printf("\n--------Menu--------\n");
	printf("1.Enqueue an Element\n");
	printf("2.Dequeue an Element\n");
	printf("3.Display End Elements\n");
	printf("4.Display entire queue\n");
	printf("5.End All the operations\n");
	while (1){
	printf("\nType your choice :");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			printf("Type the Element :");
			scanf("%d",&Element);
			
			if ((rear == N - 1)&&(front == 0)){
				printf("\nQueue is Full.\nEnqueue operation is not possible.\n");
			}
			if ((front == -1)&&(rear == -1)){
				front = front + 1;
				rear = rear + 1;
			}
			else{
				rear = rear + 1;
			}
			Queue[rear] = Element;
			break;
		case 2:
			if (((rear == -1) && (front  = -1)) || (front > rear)){
				printf("\nQueue is Empty.\nDequeue operation is not possible.\n");
			}
			else{	
				printf("Element = %d is now out of Queue\n",Queue[front]);
				front = front + 1;
			}
			break;
		case 3:
			printf("\nPeek Element = %d\n",Queue[front]);
			break;
		case 4:
			printf("\n{");
			for(i=front;i<=rear;i++){
				if (i != rear){
					printf("%d, ",Queue[i]);
				}
				else{
					printf("%d",Queue[i]);
				}
			}
			printf("}");
			break;
		case 5:
			break;
	}
	if (choice == 5){
		break;
	}
	}
	return 0;
}
