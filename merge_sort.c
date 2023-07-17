#include<stdio.h>
void merge(int a[],int low,int mid,int high)
{
    int i,j,k;
    int b[high+1];
    i=k=low;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
            i++;
            k++;
    }
    while(j<=high)
    {
        b[k]=a[j];
            j++;
            k++;
    }
    for(i=low;i<high+1;i++)
    {
        a[i]=b[i];
    }
}
void merge_sort(int a[],int low,int high)
{   
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
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
    merge_sort(a,0,n-1);
    for(i=0;i<n;i++)
    {
    printf("%d\t",a[i]);
    }
}