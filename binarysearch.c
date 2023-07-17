#include<stdio.h>
int search(int p[],int size,int item);
int main()
{
    int size=5,a[size],item,i,res;
    for(i=0;i<size;i++)
    {
        printf("element : ");
        scanf("%d",& a[i]);
    }
    printf("enter your item : ");
    scanf("%d",& item);
    res=search(a,size,item);
    (res!=-1)?printf("%d",res):printf("element not found");
}
int search(int p[],int size,int item)
{
    int lb=0,ub=size-1,mid;
    mid=(lb+ub)/2;
    int i,j;
    while(lb<=ub)
    {   
        
        if(p[mid]==item)
        {
            return mid;
            break;
        }
        else if(p[mid]>item)
        {

            ub=mid-1;
        }
        else
        {
            lb=mid+1;
        }
        mid=(ub+lb)/2;
    }
    return -1;
}