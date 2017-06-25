#include<stdio.h>

void quickSort(int a[], int beg, int end);
int partition(int a[], int beg, int end);
void swap(int *x, int *y);

int main()
{
  int a[20], n, i;
  //Enter Number of Elements
  scanf("%d", &n);

  //Enter Elements
  for(i=0;i<n;i++)
    scanf("%d", &a[i]);

	quickSort(a,0,n-1);

  printf("Sorted array :");
	for(i=0;i<n;i++)
	printf(" %d",a[i]);

	printf("\n");
	return 0;
}


void quickSort(int a[], int beg, int end){
  if(beg<end){
    int p = partition(a, beg, end);
    quickSort(a, beg, p-1);
    quickSort(a, p+1, end);
  }
}
int partition(int a[], int beg, int end){
  int i;
  int pivot = a[end];
  int j = beg - 1;
  for(i=beg; i<end; i++){
    if(a[i] <= pivot){
      j++;
      swap(&a[j], &a[i]);
    }
  }
  swap(&a[j+1], &a[end]);
  return j+1;
}

void swap(int *x, int *y)
{
  int t = *x;
  *x = *y;
  *y = t;
}
