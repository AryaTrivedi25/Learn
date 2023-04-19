#include<stdio.h>

int main()
{
    int arr[3]={4,3};
    //inserting:
    printf("enter the third value of array:\n");
    scanf("%d", &arr[2]);

    //deleting  and searching;
    int n;
    printf("enter the value to delete:\n");
    scanf("%d", &n);

    int i;
    for( i =0 ;i<3;i++)
    {
        if(arr[i]==n)
        break;
    }

    for(int j=i ;j<3-1;j++ )
    {
     arr[j] = arr[j+1];
    }

     //update:
     arr[0]=1;

     //traverse:

     for(int k =0 ;k<2 ; k++)
     {
        printf("%d index contains : %d\n",k,arr[k]);
     }
}
