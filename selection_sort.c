#include<stdio.h>
void selection_sort(int a[],int n);
void swap(int *a,int *b);
int main()
{
    int n=5,a[n],i;
    for(i=0;i<n;i++)
    {
        printf("input : ");
        scanf("%d",& a[i]);
    }
  selection_sort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
void selection_sort(int a[],int n)
{
    int i,j,index;
    for(i=0;i<n;i++)
    {
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(a[index]>a[j])
            {
                index=j;
            }
        }
        if(index!=i)
        {
            swap(&a[index],&a[i]);
        }
    }
}
void swap(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}