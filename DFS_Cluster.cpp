#include <iostream>
using namespace std;

void dfs(int vertex,int isVisited[],int n,int *arr){
    isVisited[vertex]=1;
    cout<<vertex<<" ";
    for(int i=0;i<n;i++){
        if(arr[vertex*n+i]==1 && isVisited[i]==0)
        dfs(i,isVisited,n,arr);
    }
}

int main() {
    int n,count=0;
    cout<<"Enter the number of vertices:";
    cin>>n;
    int arr[n][n],isVisited[n];
    cout<<"Enter the adjacency matrix\n";
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
    cin>>arr[i][j];
    cout<<"Adjacency matrix is \n";
    for (int i=0;i<n;i++){
        isVisited[i]=0;
    for (int j=0;j<n;j++){
    cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        if(isVisited[i]==0){
            count++;
            cout<<"Cluster "<<count<<":";
            dfs(i,isVisited,n,(int *)arr);
            cout<<"\n";
        }

    }
    cout<<"Number of Islands in the graph are "<<count;
	return 0;
}
