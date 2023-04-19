#include<stdio.h>
#include<stdlib.h>

struct node {
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
void append(struct node * head_ref,int ndata)
{
    struct node * c = (struct node *)malloc(sizeof(struct node));
    c->data=ndata;
    c->link=0;

    while((head_ref)->link != 0)
    {
        head_ref = (head_ref)->link;
    }
    (head_ref)->link = c;
    c->link = 0;
}

int main()
{
    struct node * head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    append(head,25);
    append(head,2);
    append(head,5);

    struct node * ptr = head;
    int x,y;
    printf("Enter the data you want to enter.\n");
    scanf("%d", &y);
    struct node * c = (struct node*)malloc(sizeof(struct node));
    c->data = y;
    c->link = NULL;
    printf("Enter the position at which you want to enter the data.\n");
    scanf("%d", &x);
    for(int i=2; i<x; i++)
    {
        ptr = ptr->link;
    }
    if(x>1)
    {
        c->link = ptr->link;
        ptr->link = c;
    }
    else{
        c->link = head;
        head = c;
    }
    printlist(head);
}
