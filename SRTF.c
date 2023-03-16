#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int pId,arrT, burstT;
    struct Node *next;
};
struct Node *head; // declaring head global

struct Node *createnode()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->pId = NULL;
    temp->arrT = NULL;
    temp->burstT = NULL;
    temp->next = NULL;
    return temp;
}

void createlist(int n)
{
    struct Node *temp, *new;
    head = temp = NULL;
    while (n > 0)
    {
        new = createnode();
        printf("Enter process Id: ");
        scanf("%d", &new->pId);
        printf("Enter arrival Time ");
        scanf("%d", &new->arrT);
        printf("Enter burst Time: ");
        scanf("%d", &new->burstT);
        if (head == NULL)
        {
            head = new;
            temp = new;
        }
        else
        {
            temp->next = new;
            temp = new;
        }
        n--;
    }
}

void swap(struct Node *a, struct Node *b){
    int temp = a->pId;
    int temp1 = a->arrT;
    int temp2 = a->burstT;
    a->pId = b->pId;
    a->arrT = b->arrT;
    a->burstT = b->burstT;
}

void bubbleSort(struct Node *start) 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL;
    if (start == NULL) 
        return; 
    do
    { 
        swapped = 0; 
        ptr1 = start; 
        while (ptr1->next != lptr) 
        { 
            if (ptr1->arrT > ptr1->next->arrT) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

void printList(struct Node *start) 
{ 
    struct Node *temp = start; 
    printf("\n"); 
    while (temp!=NULL) 
    { 
        printf("%d ", temp->pId); 
        printf("%d ", temp->arrT); 
        printf("%d ", temp->burstT); 
        temp = temp->next; 
    } 
} 

void main(){

}

