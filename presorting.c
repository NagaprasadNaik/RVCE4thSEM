#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
/*void merge(int A[],int l, int m, int r )
{
    int B[r-l+1];
    int i = l, j = m+1, k = 0;
    while( i <= m &&  j <= r )
    {
        if(A[i] > A[j])
            B[k++] = A[j++];
        else
            B[k++] = A[i++];
    }
    while(i <= m)
        B[k++] = A[i++];
    while(j <= r)
        B[k++] = A[j++];
    for(i = l; i <= r; i++)
        A[i] = B[i-l];
    return;
}
void mergesort(int arr[], int l, int r)
{
    if(l >= r)
        return;    
    int m = l + (r-l)/2;
    mergesort(arr, l , m);
    mergesort(arr, m+1, r);
    merge(arr, l , m, r);
}
*/

void merge(int b[], int p, int c[], int q, int a[]) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
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
void mergesort(int a[],int n){
	if(n>1){
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

int main()
{
    int arr[SIZE],n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    mergesort(arr, n);
    printf("\n");
    for(int i = 0; i < n ; i++)
        printf("%d ",arr[i]);
    for(int i = 1; i < n; i++)
        if(arr[i-1] == arr[i])
        {
            printf("\nThe elements are not unique\n");
            exit(0);
        }
    printf("\nThe elements are unique\n");
    return 0;
}