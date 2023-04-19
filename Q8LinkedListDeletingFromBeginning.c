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
struct node* del_atbeg(struct node * head)
{
    struct node * p = head;
    head = head->link;
    free(p);
    p=NULL;
    return head;
}
int main(){
    struct node * head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    append(head,25);
    append(head,2);
    append(head,5);
    printlist(head);
    printf("\n");

    int x;
    printf("Enter the number of data you want to delete from the beginning.\n");
    scanf("%d", &x);
    for(int i=0; i<x; i++)
    {
        head = del_atbeg(head);
    }
    printlist(head);
}
