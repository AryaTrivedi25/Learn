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
int main()
{
    struct node * head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;
    append(head,25);
    append(head,2);
    append(head,5);
    printlist(head);
    printf("\n");

    struct node * ptr = head;
    int count=0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("size of linked list is %d\n", count);
}
