#include <stdio.h>
#include <stdlib.h>

struct node;
struct node *CreateNode(int);
void Insert();
int Search(int);
struct node *Delete(struct node*,int);

struct node {
    struct node *lLink;
    int I;
    struct node *rLink;
};

struct node *Head = NULL;

struct node *CreateNode(int A){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->I = A;
    ptr->lLink = NULL;
    ptr->rLink = NULL;
    return ptr;
}

void Insert(){
    int Element;
    printf("Type Element :");
    scanf("%d",&Element);
    if (Head == NULL){
        Head = CreateNode(Element);
    }
    else{
        struct node *TempPtr;
        struct node *TempElmt;
        TempPtr = Head;
        while (1){
            if ((TempPtr->I) > Element){
                if ((TempPtr->lLink) != NULL){
                    TempPtr = TempPtr->lLink;
                }
                else{
                    TempElmt = CreateNode(Element);
                    TempPtr->lLink = TempElmt;
                    break;
                }
            }
            else if ((TempPtr->I) < Element){
                if ((TempPtr->rLink) != NULL){
                    TempPtr = TempPtr->rLink;
                }
                else{
                    TempElmt = CreateNode(Element);
                    TempPtr->rLink = TempElmt;
                    break;
                }
            }
        }
    }
}

struct node *Delete(struct node *Temp,int Element){
    if (Temp == NULL){
        return Temp;
    }
    else if ((Temp->I) > Element){
        Temp->lLink = Delete(Temp->lLink,Element);
    }
    else if ((Temp->I) < Element){
        Temp->rLink = Delete(Temp->rLink,Element);
    }
    else{
        if (((Temp->lLink) == NULL) && ((Temp->rLink) == NULL)){
            free(Temp);
            return NULL;
        }
        else if ((Temp->lLink) == NULL){
            struct node *TempSwift;
            TempSwift = Temp;
            Temp = Temp->rLink;
            free(TempSwift);
        }
        else if ((Temp->rLink) == NULL){
            struct node *TempSwift;
            TempSwift = Temp;
            Temp = Temp->lLink;
            free(TempSwift);
        }
        else{
            struct node *TempSwift = Temp->rLink;
            while ((TempSwift->lLink) != NULL){
                TempSwift = TempSwift -> lLink;
            }
            Temp->I = TempSwift->I;
            Temp->rLink = Delete(Temp->rLink,Temp->I);
        }
    }
    return Temp;
}

int Search(int Element){
    int Search_ProBability;
    Search_ProBability = 0;
    if (Head == NULL){
        printf("Empty Binary Search Tree.\n");
        return Search_ProBability;
    }
    else{
        struct node *Temp;
        Temp = Head;
        while (1){
            if ((Temp->I) > Element){
                if ((Temp->lLink) == NULL){
                    printf("Element %d Not Found\n",Element);
                    break;
                }
                else{
                    Temp = Temp->lLink;
                }
            }
            else if ((Temp->I) < Element){
                if ((Temp->rLink) == NULL){
                    printf("Element %d Not Found\n",Element);
                    break;
                }
                else{
                    Temp = Temp->rLink;
                }
            }
            else if ((Temp->I) == Element){
                printf("Element %d is Found\n",Element);
                Search_ProBability += 1;
                break;
            }
        }
        return Search_ProBability;
    }
}

void Inorder_Traversal(struct node *Temp){
    if (Temp == NULL){
        return ;
    }
    else{
        Inorder_Traversal(Temp->lLink);
        printf("%d -> ",Temp->I);
        Inorder_Traversal(Temp->rLink);
    }
}

void Preorder_Traversal(struct node *Temp){
    if (Temp == NULL){
        return ;
    }
    else{
        printf("%d -> ",Temp->I);
        Preorder_Traversal(Temp->lLink);
        Preorder_Traversal(Temp->rLink);
    }
}
void Postorder_Traversal(struct node *Temp){
    if (Temp == NULL){
        return;
    }
    else{
        Postorder_Traversal(Temp->lLink);
        Postorder_Traversal(Temp->rLink);
        printf("%d -> ",Temp->I);
    }
}
int main(){
    int Choice;
    int Element;
    do{
        printf("----------------------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Inorder Traversal\n");
        printf("7. Exit");
        printf("\nType Choice :");
        scanf("%d",&Choice);
        switch (Choice){
            case 1:
                Insert();
                break;
            case 2:
                printf("Type Element :");
                scanf("%d",&Element);
                Delete(Head,Element);
                break;
            case 3:
                printf("Type Element :");
                scanf("%d",&Element);
                Search(Element);
                break;
            case 4:
                Preorder_Traversal(Head);
                printf("NULL\n");
                break;
            case 5:
                Postorder_Traversal(Head);
                printf("NULL\n");
                break;
            case 6:
                Inorder_Traversal(Head);
                printf("NULL\n");
                break;
            case 7:
                break;
            default:
                printf("Please Type a Valid Choice.\n");
                break;
        }
    }while(Choice != 7);
    return 0;
}