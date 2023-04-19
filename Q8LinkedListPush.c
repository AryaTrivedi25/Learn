#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * link;
};

void printlist(struct node * head)
{
    if(head == NULL)
    {
        printf("list is empty.");
    }
    else{
        struct node * ptr = head;
        while(ptr!=NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
    }
}

void in_atbeg(struct node ** head_ref, int ndata)
{
    struct node * n_node = (struct node *)malloc(sizeof(struct node));
    n_node->data = ndata;
    n_node->link = (*head_ref);
    (*head_ref) = n_node;
}
int main()
{
    struct node * head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    int x,y;
    printf("Enter the number of elements you want to enter at the begning.\n");
    scanf("%d",&x);
    for(int i=0; i<x; i++)
    {
        printf("Enter the element you want to enter at the begning.\n");
        scanf("%d",&y);
        in_atbeg(&head,y);
    }
    printlist(head);
}
