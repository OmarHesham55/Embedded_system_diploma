
#include <stdio.h>

int main(){
	int arr[15],n,i;
	int *p = arr;

	printf("how many numbers you will input:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	printf("Enter the numbers:\n");

	for(i=0;i<n;i++){
		printf("Element-%d: ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",&arr[i]);
	}

	printf("You Entered:\n");
	for(i=0;i<n;i++){
		printf("Element-%d:%d\n",i+1,arr[i]);
	}

	p = &arr[n-1];
	printf("Reversed array:\n");

	while(p != &arr[0]-1){
		printf("%d ",*p);
		p--;
	}

}