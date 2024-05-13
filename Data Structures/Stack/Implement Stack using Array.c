#include <stdio.h>
int Push(int,int *,int);
int Pop();
int isEmpty();
int isFull();
int Peek();
int Count();
int Change(int);
int Display();

int Size,Top = -1,Status = 0;

int main(){
	printf("Type Stack Size :");
	scanf("%d",&Size);
	
	int Stack[Size],i;
	printf("\n--------Menu--------");
	printf("\n1.Push Element.");
	printf("\n2.Pop Element.");
	printf("\n3.Display Peek Element.");
	printf("\n4.Display No. of Elements in Stack.");
	printf("\n5.Change Element at Given Position.");
	printf("\n6.Display Entire Stack.");
	printf("\n7.Exit.\n");
	
	int Element;
	while (1){
	printf("Type Choice :");
	scanf("%d",&i);
		switch(i){
			case 1:
				printf("\nType Element :");
				scanf("%d",&Element);
				Status = push(Element,Stack,Top);
				((Status == 0)?printf("Stack is Full"):printf("Push Operation Successfull"));
			case 2:
				Status = pop(Stack,Top);
				((Status == 0)?printf("Stack Empty"):printf("Element Popped"));
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				break;
		}
		if (i == 7){
			break;
		}
	}
	return;
}
