#include <iostream>
using namespace std;
void leastElement(int arr[],int n,int k){
	int i,j,temp,min;
	for(i=0;i<k;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[min])
				min=j;
	}
	temp=arr[i];
	arr[i]=arr[min];
	arr[min]=temp;
	}
	cout<<k<<"th smallest element is "<<arr[k-1]<<"\n";
}
int main(){
	int *arr,n,k;
	cout<<"Enter the range of array:";
	cin>>n;
	arr=new int[n];
	cout<<"Enter the elements\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Which smallest element to find?"<<"(Range="<<n<<")\n";
	cin>>k;
	if(k<=n)
	leastElement(arr,n,k);
	else
		cout<<"Index not found\n";
	return 0;
}


