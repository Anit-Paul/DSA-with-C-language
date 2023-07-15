#include<stdio.h>
void insertion_sort(int a[],int n);
int main()
{
    int n=5,a[n],i;
    for(i=0;i<n;i++)
    {
        printf("input : ");
        scanf("%d",& a[i]);
    }
   insertion_sort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
void insertion_sort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}