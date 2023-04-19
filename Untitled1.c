#include <stdio.h>

struct student {
        int rollno;
        float marks;
    }s;
int main()
{
    struct student s = {10,100};
    struct student * sp = &s;
    //printf("Enter the Roll_number, Marks of student: \n");
    //scanf("%d %f ", &sp->rollno, &sp->marks);
    printf("Roll_number: %d\n Marks: %f",sp->rollno, sp->marks);
   // printf("Marks: %f",sp->marks);
}
