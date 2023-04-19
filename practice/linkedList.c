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

void at_beg(struct node ** head_ref, int ndata)
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

   /* struct node * current = (struct node*)malloc(sizeof(struct node));
    current->data = 13;
    current->link = NULL;
    head->link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current->data = 69;
    current->link = NULL;
    head->link->link = current;*/


    /*printf("%d\n", head->data);
    printf("%d\n", head->link->data);
    printf("%d\n", head->link->link->data);
    printf("%d\n", current->data);*/

   /* //traversing through linked list
    struct node * ptr = head;
    int count=0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("size of linked list is %d\n", count);*/

  /* //inserting data into list at the end of linked list
    struct node *temp, *p=head;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = 29;
    temp->link = NULL;

    while(p->link != NULL)
    {
        p = p->link;
    }
    p->link = temp;
    //printf("%d\n", head->link->link->link->data);*/

    //inserting data into list at the begning of the linked list
  /*  struct node * tem1 = (struct node*)malloc(sizeof(struct node));
    tem1->data = 61;
    tem1->link = head;
    head = tem1;*/

    /*printf("\n the new linked list is : \n");
    printf("%d\n", head->data);
    printf("%d\n", head->link->data);
    printf("%d\n", head->link->link->data);
    printf("%d\n", head->link->link->link->data);
    printf("%d\n", head->link->link->link->link->data);*/

    at_beg(&head, 5);


    printlist(head);
    printf("\n");


    // deleting from linked-list
  /*  struct node * p = head;
    while(p->link->link != NULL)
    {
        p = p->link;
    }
    p->link = NULL;
    printlist(head);*/
}
