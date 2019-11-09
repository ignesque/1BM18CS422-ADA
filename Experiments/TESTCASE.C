
#include <stdio.h>
int main(int argc, char **argv)
{
	int testcase,n,i,j,key,flag=-1;
	{
		printf("PLEASE ENTER THE NUMBER OF TESTCASES:");
		scanf("%d",&testcase);
		for(i=0;i<testcase;i++){
			printf("ENTER THE SIZE OF THE ARRAY\n");
			scanf("%d %d",&n,&key);
			int a[n];
			printf("ENTER THE ARRAY ELEMENTS\n");
			for(j=0;j<n;j++){
				scanf("%d",&a[j]);
			}
			for(j=0;j<n;j++){
				if(a[j]==key){
					flag=1;
				}
			}
			if(flag==1){
				printf("1\n");
			}
			else{
				printf("-1\n");
			}
			
				
		}
			
		
	}
}
