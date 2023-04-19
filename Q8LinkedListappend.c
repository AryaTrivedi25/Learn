#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define NULL 0
struct node{
    int data;
    struct node * link;
};

void print(struct node * head)
{
        struct node * ptr = head;
        while(ptr!=0)
        {
            printf("%d\t",ptr->data);
            ptr = ptr->link;
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
    head->data=0;
    head->link=0;
    int x,y;
    printf("Enter the number of data you want to append.\n ");
    scanf("%d", &x);
    for(int i=0; i<x; i++)
    {
        printf("Enter the data you want to append.\n");
        scanf("%d", &y);
        append(head,y);
    }
    print(head);
}
