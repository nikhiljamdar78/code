#include<stdio.h>
#include<stdlib.h>

void heapsort(int a[], int n);
void heapify(int a[], int  i, int last);
void buildheap(int a[], int n);
void display(int a[], int n);

void heapsort(int a[10], int n)
{
	int i,temp;
	buildheap(a,n);
	printf("\n   Initialize Heap");
	display(a,n);
	printf("\n");
	for(i=n-1; i>=1; i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		
		printf("\nAfter %d Iteration-->", n-i);
		display(a,n);
		//printf("\n");
		heapify(a, 0, i-1);	
	}
}
void buildheap(int a[], int n)
{
	int i;
	for(i=(n/2)-1; i>=0; i--)
		heapify(a,i, n-1);
}

void heapify(int a[], int i, int last)
{
	int j, temp, key;
	
	key=a[i];
	j=2*i+1;

	if((j<last )&&(a[j]<a[j+1]))
		j=j+1;
	if((j<=last)&&(key < a[j]))
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		heapify(a, j ,last);  
	}
}

void display(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
	printf(" %d ", a[i]);
}

int main()
{
	int a[20], n, i;
	printf("\n How many element you want to in array..?\t");
	scanf("%d",&n);
	printf("\n Enter %d Element In Array:\t",n);
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
		heapsort(a,n);
 	printf("\n\n The Sorted Element Are:");
	display(a,n);
	printf("\n");
	return 0;
}
