#include<stdio.h>
#include<stdlib.h>

int count=0;

void merge(int b[], int p, int c[], int q, int a[]) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
          count++;   //because comparison is Basic Operation
        if (b[i] <= c[j]) {
            a[k++] = b[i++];
        } else {
            a[k++] = c[j++];
        }
    }
    while (i < p) {
        a[k++] = b[i++];
    }
    while (j < q) {
        a[k++] = c[j++];
    }
}
int mergesort(int a[],int n){
	if(n>1){
	   count++;
		int mid=n/2;
		int b[mid];
		int c[n-mid];
		for (int i = 0; i < mid; i++) {
            b[i] = a[i];
        }
        for (int i = mid; i < n; i++) {
            c[i - mid] = a[i];
        }
		mergesort(b,mid);
		mergesort(c,n-mid);
		merge(b,mid,c,n-mid,a);
	}
}
int main(){
	int n, c1,c2,c3;
	int a[4000],b[4000],c[4000];
	printf("Enter no of array elements:\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter array elements:\n");
	int r;
	for(int i=0;i<n;i++){
		scanf("%d",&r);
		arr[i]=r;
	}
	mergesort(arr,n);
	for(int m=0;m<n;m++)
		printf("%d\t",arr[m]);
		
	
	printf("\n Total basic operations: %d\n",count);
	
	printf("\nSize\t Ascend Descend  Random\n");
	for(int i=4;i<=2048; i=i*2)
	 {
	    for(int j=0;j<i;j++)
	    {
	       a[j]=j;
	       b[j]=i-j;
	       c[j]=rand();
	       
	       count=0;
	       mergesort(a,i);
	       c1=count;
	       
	       count=0;
	       mergesort(b,i);
	       c2=count;
	       
	       count=0;
	       mergesort(c,i);
	       c3=count;
        }     
        printf("%d\t %d\t %d\t %d\n", i,c1,c2,c3);	       
}
}
