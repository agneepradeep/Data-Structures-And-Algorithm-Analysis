#include <stdio.h>
#include <stdlib.h>

struct node{
    int I;
    struct node *Link;
};
struct node *Front = NULL;
struct node *Rear = NULL;
int Size;
int SizeCount = 0;

void Enqueue(){
    int Element;
    printf("Type the Element: ");
    scanf("%d",&Element);
    if ((Front == NULL) && (Rear == NULL)){
        Front = (struct node *)malloc(sizeof(struct node));
        Front -> I = Element;
        Front ->Link = NULL;
        Rear = Front;
        SizeCount += 1;
    }
    else if (SizeCount == Size){
        printf("Overflow.\n");
        return;
    }
    else{
        struct node *Temp = (struct node *)malloc(sizeof(struct node));
        Temp->I = Element;
        Temp->Link = NULL;
        Rear->Link = Temp;
        Rear = Temp;
        SizeCount += 1;
    }
};
void Dequeue(){
    if (SizeCount == 0){
        printf("Underflow.\n");
        return;
    }
    else if (SizeCount == 1){
        struct node *Temp;
        Temp = Front;
        printf("%d is Dequeued.\n",Temp->I);
        Front = Front->Link;
        Rear = Rear->Link;
        free(Temp);
        SizeCount -= 1;
    }
    else{
        struct node *Temp;
        Temp = Front;
        Front = Front->Link;
        printf("%d is Dequeued.\n",Temp->I);
        free(Temp);
        SizeCount -= 1;
    }
};
void Display(){
    if(Front == NULL){
        printf("No Element.\n");
        return ;
    }
    else{
        struct node *Temp;
        Temp = Front;
        while ((Temp->Link)!= NULL){
            printf("%d -> ",Temp->I);
            Temp = Temp -> Link;
        }
        printf("%d\n",Temp -> I);
    }
};

int main(){
    printf("Type the Size of Queue :");
    scanf("%d",&Size);
    int Choice;
    do{
        printf("----------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("\nType Your Choice :");
        scanf("%d",&Choice);
        switch (Choice){
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                break;
            default:
                printf("Type A valid Choice.\n");
                break;
        }
    }while (Choice != 4);
    return 0;
}
