#include<stdio.h>
void heap_sort(int a[],int n);
void swap(int *p,int *q);
void heapify(int a[],int n);
void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}
int main()
{
    int n,a[n],i;
    printf("size : ");
    scanf("%d",& n);
    for(i=0;i<n;++i)
    {
        printf("input : ");
        scanf("%d",& a[i]);
    }
    heap_sort(a,n);
    for(i=0;i<n;++i)
    {
        //printf("input : ");
        printf("%d\t",a[i]);
    }
    return 0;
}
void heapify(int a[],int n)
{
    int p,c,i;
    for(i=n/2-1;i>=0;--i)
    {
        p=i; 
        while(p<n)
        {
            c=2*p+1;
            if(c>=n)
            break;
            if(c<n-1 &&a[c]<a[c+1])
            {
                c=c+1;
            }
            if(a[p]<a[c])
            {
                swap(&a[p],&a[c]);
                p=c;
            }
            else
            break;
        }
    }
}
void heap_sort(int a[],int n)
{
    int j;
    heapify(a,n);
    for(j=n-1;j>0;--j)
    {
        swap(&a[j],&a[0]);
        heapify(a,j);
    }
}