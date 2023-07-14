#include<stdio.h>
void swap(int *a,int *b);
void bubble_sort(int a[],int n);
void bubble_sort(int a[],int n)
{
    int i,j,flag=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
}
void swap(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
int main()
{
    int n=5,a[n],i;
    for(i=0;i<n;i++)
    {
        printf("input : ");
        scanf("%d",& a[i]);
    }
    bubble_sort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}