#include<stdio.h>


struct node{
    int data;
    struct node*next;
};

struct node* create_ll(struct node*start)
{
    int n;
  printf("enter -1 to end\n");
  printf("\nenter data:");
  scanf("%d", &n);

  while(n!=-1)
  {
    struct node* new= (struct node*)malloc(sizeof(struct node));

    if(start == NULL)
    {
        start = new;
        new->data = n;
        new->next =start;
    }

    else{
        struct node* ptr = start;
        while(ptr->next != start)
        ptr= ptr->next;

        ptr->next = new;
        new->data =n;
        new->next = start;

    }
    printf("\nenter data:");
  scanf("%d", &n);
  }

  printf("\nLinked List Created!!");
  return start;

}

void print_ll(struct node*start)
{
    printf("\nLinked List :");
   struct node* ptr = start;
   struct node* adr;
   while(ptr->next!=start)
   {
    adr = ptr;
    printf("\nData at Address %d : %d", adr, ptr->data);
    ptr = ptr->next;
   }

   adr =ptr;
    printf("\nData at Address %d : %d", adr, ptr->data);

}

struct node* add_begin(struct node*start)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the value to add at begin:");
    int val;
    scanf("%d", &val);

   struct node* ptr = start;
   while(ptr->next != start)
   ptr = ptr->next;

   ptr->next = new;
   new->next = start;
   start = new;
   new->data = val;

  printf("\nnode added successfully!!");
    return start;
}

void add_last(struct node* start)
{
    int val;
    struct node* new=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the value to add at last:");
    scanf("%d", &val);

    struct node* ptr =start;
    while(ptr->next !=start)
    ptr = ptr->next;

   new->data = val;
    new->next =start;
    ptr->next = new;

  printf("\nnode added successfully!!");

}

void add_after(struct node* start)
{
   int val, hint;
  printf("\nenter the value(existing) after which the  new value is to be added:");
  scanf("%d", &hint);
  printf("\nenter the value that is to be added:");
  scanf("%d", &val);

struct node* new=(struct node*)malloc(sizeof(struct node));
struct node* ptr = start;
while(ptr->data !=hint)
{
    ptr=ptr->next;
}

struct node* temp = ptr->next;
ptr->next = new;
new->data = val;
new->next = temp;


  printf("\nnode added successfully!!");

}

struct node* add_before( struct node*start)
{
   int val, hint;
  printf("\nenter the value(existing) before which the new value is to be added: ");
  scanf("%d", &hint);
  printf("\nenter the value that is to be added:");
  scanf("%d", &val);

  struct node* new= (struct node*) malloc(sizeof(struct node));
  struct node* ptr = start;

  if(ptr->data == val)
  {
    start = new;
    new->next = start;
    new->data = val;

  }
  else{
  while((ptr->next)->data !=hint)
  ptr = ptr->next;

  new->data = val;
  new->next = ptr->next;
  ptr->next = new;

  }


  printf("\nnode added successfully!!");
  return start;
}

struct node* del_begin( struct node* start)
{
  struct node* ptr1=start->next;
  struct node* ptr = start;

  while(ptr->next !=start)
  ptr = ptr->next;

  ptr->next = ptr1;
  free(start);

  start = ptr1;
/*
   printf("\ndeleting the first node");
   for(int i =0 ;i<4;i++)
   {
    printf(".");
    Beep(0,500);
   }
   printf("\nDone!!!\n");
*/
   return start;
}

void del_last(struct node* start)
{
   struct node* ptr=start;
   while(((ptr->next)->next)!=start)
    ptr = ptr->next ;

   struct node* temp = ptr->next;
   free(temp);
   ptr->next= start;

   printf("\ndeleting the last node");
   for(int i =0 ;i<4;i++)
   {
   printf(".");
   Beep(0,500);
   }
   printf("\nDone!!!\n");



}

struct node* del_interMed(struct node * start)
{
  int val;
  printf("enter the value to delete: \n");
  scanf("%d", &val);

  struct node* ptr = start;

  int count= 0;
  while(count!=2)
  {
    if(ptr == start)
    count++;

    if((ptr->next)->data == val)
    break;

    ptr = ptr->next;

  }

  if(count==2)
  printf("value is not present in list!!\n");

else{
   struct node* temp=(ptr->next)->next ;

   free(ptr->next);

   if(ptr->next == start)
   start = temp;

   ptr->next=temp;

   printf("\ndeleting the node");
   for(int i =0 ;i<4;i++)
   {
   printf(".");
   Beep(0,500);
   }
   printf("\nDone!!!\n");

  }

  return start;
}

struct node* reverse_ll(struct node* start)
{
   struct node *ptr1 = NULL;
   struct node *ptr2 = NULL;
   struct node *ptr = start;

   while(ptr->next != start)
   ptr = ptr->next ;

  struct node* temp = start;
    ptr2 = temp ->next ;
    temp -> next = ptr1;
    ptr1 = temp;
    temp = ptr2;
   while(temp!=start)
   {
    ptr2 = temp ->next ;
    temp ->next = ptr1;
    ptr1 = temp;
    temp = ptr2;
   }

   start = ptr;

   printf("\nLinked List is reversed!");
   return start;
}

int main()
{

struct node* start=NULL;
 int opt;

do{

 printf("\n\nMENU :\n\n");
 printf("1.create a linked list\n");
 printf("2.add a node at begin\n");
 printf("3.add a node at end\n");
 printf("4.add a node after a particular node\n");
 printf("5.add a node before a particular node\n");
 printf("6.delete a node at begin\n");
 printf("7.delete a node at end\n");
 printf("8.delete a particular node\n");
 printf("9.reverse the linked list\n");
 printf("10.print the linked list\n");
 printf("11.EXIT\n");

 printf("your option:\n");
 scanf("%d", &opt);

 switch(opt)
 {
  case 1: start = create_ll(start);
          break;
  case 2: start = add_begin(start);
          break;
  case 3:  add_last(start);
          break;
  case 4:  add_after(start);
          break;
  case 5: start = add_before(start);
          break;
  case 6:  start = del_begin(start);
          break;
  case 7:  del_last(start);
          break;
  case 8: start = del_interMed(start);
          break;
  case 9: start = reverse_ll(start);
          break;
  case 10: print_ll(start);
           break;
 }

}while(opt!=11);

}

