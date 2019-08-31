#include<stdio.h>
#include<stdlib.h>

void merge(int A[],int i1,int j1,int i2,int j2);

int selectioncount=0,mergecount=0;
int i,j,temp;
void bubbleSort(int A[],int n)
{
	int bubblecount=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n-i-1;j++)
		{  
                        bubblecount++
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}

	}
		printf("Bubble sort : %d comparisions\n",bubblecount);
}
void selectionSort(int A[],int n)
{
	int min;
	for(i=0;i<=n-2;i++)
	{	min=i;
		for(j=i+1;j<=n-1;j++)
		{
                        selectioncount++;
			if(A[min]>A[j])
			{	
				min=j;
			}
		}
		temp=A[min];
		A[min]=A[i];
		A[i]=temp;
	}

}
void mergeSort(int A[],int i,int j)
{
	int mid;
	if(i<j)
	{
		mid=(i+j)/2;
		mergeSort(A,i,mid);
		mergeSort(A,mid+1,j);
		merge(A,i,mid,mid+1,j);
	}

}
void merge(int A[],int i1,int j1,int i2,int j2)
{
	int temp[100];
	int k;
	i=i1;
	j=i2;
	k=0;
	while(i<=j1 && j<=j2)
	{
                mergecount++;
		if(A[i]<A[j])
			{
			temp[k++]=A[i++];}
		else
			{
			temp[k++]=A[j++];}
	}
	while(i<=j1)
	{temp[k++]=A[i++];}
	while(j<=j2)
	{temp[k++]=A[j++];}
	for(i=i1,j=0;i<=j2;i++,j++)
	{A[i]=temp[j];}

}
int main()
{
	int n,arr[200],i;
	printf("How many elements? ");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Elements in the array are\n");
	for(i=0;i<n;i++)
	{printf("%d ",arr[i]);}
	selectionSort(arr,n);
	printf("\n\nSelection sort : %d comparisions\n",selectioncount);
	mergeSort(arr,0,n-1);
	printf("Merge sort : %d comparisions\n",mergecount);
	bubbleSort(arr,n);
	return 0;
}
