// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*prev;
    struct node*next;

};

void print( struct node* start)
{
    printf("\nlinked List :\n");
  struct node* ptr = start;
  struct node *adr ;
  while(ptr !=NULL)
  {
    adr =ptr;
    printf("Data at the Address %d : %d\n",adr,ptr->data );
    ptr = ptr->next;
  }

}

struct node* add_begin(struct node* start)
{
    int val;
  printf("\nenter the data to be added at begin:\n");
  scanf("%d", &val);

   struct node*temp = start;
  struct node *new  = (struct node*)malloc(sizeof(struct node));

  if(new == NULL)
  printf("no memory allocated!!\n\n");

  start = new;
  new->data = val;
  new->next = temp;
  new->prev = NULL;
  temp->prev = new;

  printf("node added successfully!!\n\n");
  return start;
}

void add_last(struct node* start)
{
   int val;
   printf("\nEnter the data to be added at end:\n\n");
   scanf("%d", &val);

   struct node* new  = (struct node*)malloc(sizeof(struct node));
   if(new==NULL)
   printf("\nmemory not allocated!!\n\n");

  struct node*ptr = start;
   while(ptr->next!=NULL)
   ptr = ptr -> next;

   ptr->next = new;
   new->prev = ptr;
   new->data = val;
   new -> next  = NULL;

   printf("\nnode added successfully!!\n\n");

}

 void add_after(struct node* start)
{

    int hint;
    printf("\n\nenter the data after which the node is to be added:");
    scanf("%d" , &hint);

   int val;
   printf("\nEnter the data to be added:");
   scanf("%d", &val);

   struct node* new  = (struct node*)malloc(sizeof(struct node));
   if(new==NULL)
   printf("\nmemory not allocated!!\n\n");

   struct node*ptr = start;
   struct node* temp;


   while(ptr->data != hint)
   {
     ptr = ptr->next;
   }
   temp =ptr->next;


    ptr->next = new;
    new ->data =val;
    new->prev = ptr;
    new->next = temp;
    temp->prev = new;

    printf("node added successfully!!\n\n");
}

struct node* add_before(struct node* start)
{
    int hint;
    printf("enter the data before which the node is to be added:\n\n");
    scanf("%d" , &hint);

   int val;
   printf("\nEnter the data to be added:\n\n");
   scanf("%d", &val);

   struct node* new  = (struct node*)malloc(sizeof(struct node));
   if(new==NULL)
   printf("\nmemory not allocated!!\n\n");

   struct node*ptr = start;
   struct node*temp ;
   if(ptr->data != hint)
   {
    temp = ptr->next;
    start = new;
    new->data =val;
    new->next = temp;
    new ->prev = NULL;
    temp->prev = new;
   }

   else{
    while((ptr->next)->data != hint)
    ptr = ptr->next;

    temp = ptr->next;

    ptr->next =new;
    new->data =val;
    new->prev = ptr;
    new->next = temp;
    temp->prev = new;
   }
  printf("node added successfully!!\n\n");
  return start;
}

struct node* del_begin(struct node*start)
{
    struct node*temp = start;
    start = start->next;
    start->prev =NULL;

   free(temp);

   printf("\n\nnode deleted successfully!!\n\n");
   return start;
}

void del_last(struct node*start)
{
  struct node*ptr = start;
  while((ptr->next)->next != NULL)
  ptr = ptr->next;

  ptr->next =NULL;

struct node* temp = ptr->next;
 free(temp);

printf("\n\nnode deleted successfully!!\n\n");
}
struct node* del_interMed( struct node*start)
{
   int val;
   printf("\nEnter the data to be deleted:\n\n");
   scanf("%d", &val);

   struct node* ptr =start;

   while(ptr->data !=val)
   ptr = ptr->next;

   if(ptr == start)
   start = ptr->next;
   else
   (ptr->prev)->next = ptr->next;

   if(ptr->next != NULL)
   (ptr->next)->prev = ptr->prev;
   free(ptr);
   printf("node deleted successfully!!\n\n");
   return start;
}
int main()
{
struct node* start=NULL;
 int o;

printf("\nEnter -1 to end the list\n");
    int n;
    printf("enter the data:\n");
    scanf("%d", &n);

    while(n!=-1)
    {
        struct node *new  = (struct node*)malloc(sizeof(struct node));
        struct node *ptr = start;
        if(start==NULL)
        {
          start = new;
          new->data = n;
          new->next = NULL;
          new ->prev = NULL;
        }

        else{
        while(ptr->next!=NULL)
        ptr= ptr->next;

        ptr->next = new;
        new->prev=ptr;
        new->data = n;
        new->next = NULL;
        }
          printf("enter the data:\n");
          scanf("%d", &n);

    }

printf("Linked List created!!!\n");

do{
 printf("1.add a node at begin\n");
 printf("2.add a node at end\n");
 printf("3.add a node after a particular node\n");
 printf("4.add a node before a particular node\n");
 printf("5.delete a node at begin\n");
 printf("6.delete a node at end\n");
 printf("7.delete a particular node\n");
 printf("8.print the linked list\n");
 printf("9.EXIT\n");

 printf("your option:\n");
 scanf("%d", &o);

 switch(o)
 {

  case 1: start = add_begin(start);
          break;
  case 2:  add_last(start);
          break;
  case 3:  add_after(start);
          break;
  case 4: start = add_before(start);
          break;
  case 5:  start = del_begin(start);
          break;
  case 6:  del_last(start);
          break;
  case 7: start = del_interMed(start);
          break;
  case 8: print(start);
           break;
 }

}while(o!=9);

}

