#include<stdio.h>
void count_sort(int a[],int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    
    int b[max+1];
    for(int i=0;i<max+1;i++)
    {
       b[i]=0;
       //printf("%d\t",b[i]);
    }
   // printf("\n");
    for(int i=0;i<n;i++)
    {
        int d=a[i];
        b[d]=b[d]+1;
        
    }
    int i=0,j=0;
    while(i<n && j<max+1)
    {
        if(b[j]!=0)
        {
            a[i]=j;
            i++;
            b[j]--;
        }
        else
        {
            j++;
        }
    }
    
}
int main()
{
    int n=5,a[n],i;
    for(i=0;i<n;i++)
    {
        printf("input : ");
        scanf("%d",& a[i]);
    }
    count_sort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}