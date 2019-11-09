#include <stdio.h>
	void bubbleSort(int arr[],int n){
	int temp,i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void getLarge(int arr[],int n,int k){
	int i;
	printf("\n%d largest elements in the array are ",k);
	for(i=n-1;i>=n-k;i--){
		printf("%d",arr[i]);
		printf(" ");
	}
}
int main(){
	int n,k,i;
	int arr[30];
	printf("Enter the range of array:");
	scanf("%d",&n);
	printf("Enter the elements to be inserted in the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\nHow many largest elements to be fetched?(Range=%d):",n);
	scanf("%d",&k);
	if(k<=n){
	bubbleSort(arr,n);
	getLarge(arr,n,k);
	}
	else
		printf("Invalid Index");
	printf("\n");
	return 0;
}
