#include <stdio.h>
#include <stdlib.h>

struct node{
    int I;
    struct node *Link;
};
struct node *Top = NULL;
int Size;
int SizeCount = 0;
void Push(){
    int Element;
    printf("Type the Element: ");
    scanf("%d",&Element);
    if (Top == NULL){
        Top = (struct node *)malloc(sizeof(struct node));
        Top->I = Element;
        Top->Link = NULL;
        SizeCount += 1;
    }
    else{
        if (SizeCount == Size){
            printf("Overflow\n");
            return ;
        }
        else{
            struct node *Temp = (struct node *)malloc(sizeof(struct node));
            Temp->I = Element;
            Temp->Link = Top;
            Top = Temp;
        }
    SizeCount += 1;
    }
}

void Pop(){
    if (Top == NULL){
        printf("UnderFlow.\n");
        return ;
    }
    else{
        struct node *Temp;
        Temp = Top;
        Top = Top->Link;
        printf("%d is Pop\n",Temp->I);
        free(Temp);
        SizeCount -= 1;
    }
}

void Display(){
	if (Top == NULL){
		printf("No Elements.\n");
		return ;
	}
	else{
		struct node *Temp;
    	Temp = Top;
    	while ((Temp->Link) != NULL){
        	printf("%d <- ",Temp->I);
        	Temp = Temp->Link;
    	}
    	printf("%d\n",Temp->I);
	}	
}

int main(){
    printf("Type the Size of Stack :");
    scanf("%d",&Size);
    int Choice;
    do{
        printf("----------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("\nType Your Choice :");
        scanf("%d",&Choice);
        switch (Choice){
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
            case 3:
            	if (Top == NULL){
            		printf("No Peek.\n");
				}
                else{
					printf("Peek -> %d\n",Top->I);
				}
                break;
            case 4:
                Display();
                break;
            case 5:
                break;
            default:
                printf("Type A valid Choice.\n");
                break;
        }
    }while (Choice != 5);
    return 0;
}
