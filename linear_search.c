#include <stdio.h>

int search(int array[], int n, int x) {
  
  
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}

int main() {
    int n,x;
    printf("size : ");
    scanf("%d",& n);
     
    int array[n];
  for(int i=0;i<n;i++)
  {
    printf("input : ");
    scanf("%d",& array[i]);
  }
printf("item : ");
    scanf("%d",& x);
int result = search(array, n, x);

  (result == -1) ? printf("Element not found") : printf("Element found at index: %d", result);
}