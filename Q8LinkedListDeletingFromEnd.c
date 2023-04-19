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
struct node* del_atend(struct node * head)
{
    struct node * p1 = head->link;
    struct node * p2 = head;
    while(p1->link !=0)
    {
        p1 = p1->link;
        p2 = p2->link;
    }
    free(p1);
    p1 = NULL;
    p2->link = NULL;
    p2 = NULL;
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
    printf("Enter the number of data you want to delete from the end.\n");
    scanf("%d", &x);
    for(int i=0; i<x; i++)
    {
        head = del_atend(head);
    }
    printlist(head);
}
