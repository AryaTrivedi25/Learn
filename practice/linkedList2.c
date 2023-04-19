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
    head->data=10;
    head->link=0;
    append(head,25);
    append(head,10);
    append(head,2);
    append(head,25);
    append(head,1);
    print(head);


}
