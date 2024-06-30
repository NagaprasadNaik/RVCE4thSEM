#include <stdio.h>
#include <stdlib.h>

int count = 0;

void merge(int A[], int B[], int p, int C[], int q){
    int i=0, j=0, k=0;
    while(i<p && j<q){
        count++;
        if(B[i] <= C[j]){
            A[k++] = B[i++];
        }else{
            A[k++] = C[j++];
        }
    }

    while(i<p){
        A[k++] = B[i++];
    }
    while(j<q){
        A[k++] = C[j++];
    }
}

void mergesort(int A[], int n){
    if(n > 1){
        count++;
        int mid = n / 2;
        int B[mid];
        int C[n-mid];
        for(int i=0; i<mid; i++){
            B[i] = A[i];
        }
        for(int i=mid; i<n; i++){
            C[i-mid] = A[i];
        }
        mergesort(B, mid);
        mergesort(C, n-mid);
        merge(A, B, mid, C, n-mid);
    }
}

int main(){
    int n, a;
    printf("Enter the size of an array\n");
    scanf("%d", &n);
    // int arr[5] = {10, 7, 2, 9, 1};
    int arr[n];
    printf("Enter the array elememts: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        arr[i] = a;
    }
    printf("Array elements ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    mergesort(arr, 5);
    printf("\nArray elements ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n %d count", count);
}

