#include<stdio.h>


int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quick_sort(int a[],int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot=partition(a,low,high);
         quick_sort(a,low,pivot-1);
         quick_sort(a,pivot+1,high);
    }
}
int main()
{
    int n;
    printf("size : ");
    scanf("%d",& n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("element : ");
        scanf("%d",& a[i]);
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}