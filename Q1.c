#include <stdio.h>
struct student{
    char name[20];
    int marks;
    int roll;
};
void main(){
    struct student student1, *ptr;
    ptr = &student1;
    printf("entrer name of first student: \n");
    scanf("%s",&student1.name);
    printf("entrer marks of first student: \n");
    scanf("%d",&student1.marks);
    printf("entrer Roll number of first student: \n");
    scanf("%d",&student1.roll);
    printf("\nname of student 1 is -> %s\n",ptr->name);
    printf("marks of student 1 is -> %d\n",ptr->marks);
    printf("Roll number of student 1 is -> %d", ptr->roll);
    //hello world
}
