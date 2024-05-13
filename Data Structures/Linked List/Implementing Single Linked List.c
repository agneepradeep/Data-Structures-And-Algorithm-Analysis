#include <stdio.h>
#include <stdlib.h>
void InsertBeg();
void InsertMid();
void InsertEnd();
void DeleteBeg();
void DeleteMid();
void DeleteEnd();
void Search();
void Display();
struct node{
    int I;
    struct node *link;   
};

struct node *head;
int main(){
    int Choice;
    do{
        printf("\n----------MENU----------\n");
        printf("1. Insert at Begining\n");
        printf("2. Insert in Between\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Begining\n");
        printf("5. Delete in Between\n");
        printf("6. Delete at End\n");
        printf("7. Search a Element\n");
        printf("8. Display Linked List\n");
        printf("9. Exit\n");

        printf("Type your Choie :");
        scanf("%d",&Choice);

        switch (Choice){
            case 1:
                InsertBeg();
                break;
            case 2:
                InsertMid();
                break;
            case 3:
                InsertEnd();
                break;
            case 4:
                DeleteBeg();
                break;
            case 5:
                DeleteMid();
                break;
            case 6:
                DeleteEnd();
                break;
            case 7:
                Search();
                break;
            case 8:
                Display();
                break;
            case 9:
                break;
            default:
                printf("Please Type a valid Choice!\n");
                break;
        }
    }while (Choice != 9);
    return 0;
}

void InsertBeg(){
    struct node *temp;
    temp = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->link = head;
    head = new;
    int F;
    printf("Type the Element :");
    scanf("%d",&F);
    head->I = F;
}

void InsertMid(){
    int S;
    printf("Type the Element after which you want to place the new node :");
    scanf("%d",&S);
    struct node *temp;
    temp = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    while (temp->I != S){
        temp = temp->link;
    }
    if (temp->link != NULL){
    new->link = temp->link;
    temp->link = new;
    int K;
    printf("Type the Element :");
    scanf("%d",&K);
    new->I = K;
	}
	else{
		InsertEnd();
	}
}

void InsertEnd(){
    struct node *temp;
    temp = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    while ((temp->link) != NULL){
        temp = temp->link;
    }
    temp->link = new;
    new->link = NULL;
	int U;
	printf("Type the Element :");
	scanf("%d",&U);
	new->I = U;    
}

void DeleteBeg(){
    if (head != NULL){
        struct node *temp;
        temp = head;   
        if(head->link != NULL){
            head = head->link;
            free(temp);
        }
        else{
            free(head);
            head = NULL;
        }
    }
    else{
        printf("\nDeletion is not possible, because no node is present.\n");
    }
}

void DeleteMid(){
    if ((head != NULL)&&((head->link->link) != NULL)){
    int G;
    printf("Type the Element to be Deleted :");
    scanf("%d",&G);
    struct node *temp;
    temp = head;
    while (temp->link->I != G){
        temp = temp->link;
    }
    struct node *temp1;
    temp1 = temp->link;
    temp->link = temp1->link;
    free(temp1);
    }
    else if ((head->link->link == NULL)){
        DeleteEnd();
    }
    if (head == NULL){
        printf("\nDeletion is not possible, because no node is present.\n");
    }
}

void DeleteEnd(){
    struct node *temp;
    temp = head;
    while ((temp->link->link) != NULL){
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
}

void Search(){
	if ((head->link) != NULL){
    	int SearchElement;
    	int Search = 0;
    	printf("Type the Element :");
    	scanf("%d",&SearchElement);
    	struct node *temp;
    	temp = head;
    	while (temp != NULL){
        	if ((temp->I) == SearchElement){
        		Search++;
            	printf("Element %d Found in Linked List\n",SearchElement);
            	break;
        	}
        	else{
            	temp = temp->link;
        	}
    	}
    	if(Search == 0){
    		printf("\nElement %d Is not in Linked List\n",SearchElement);
		}
	}
	else{
		printf("\nSearching is Impossible, because linked List is empty\n");
	}
}

void Display(){
    if (head != NULL){
        struct node *temp;
        temp = head;
        do{
            printf("%d -> ",temp->I);
            temp = temp->link;
        }while(temp != NULL);
        printf("NULL\n");
    }
    else{
        printf("\nPrinting is not possible, because no node is present.\n");
    }
}
