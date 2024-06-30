#include <stdio.h>
#include <stdlib.h>

int partition(int A[], int l, int r){
    int pivot = A[l];
    int i = l + 1;
    int j = r;

    while (1) {
        while (i <= r && A[i] <= pivot) 
            i++;
        while (j >= l && A[j] > pivot) 
            j--;

        if (i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        } else {
            int temp = A[j];
            A[j] = A[l];
            A[l] = temp;
            return j;
        }
    }
}

void quicksort(int A[], int l, int r){
    if(l < r){
        int s = partition(A, l, r);
        quicksort(A, l, s-1);
        quicksort(A, s+1, r);
    }
}

int main(){
    int n, a;
    printf("Enter the size of an array\n");
    scanf("%d", &n);
    // int arr[5] = {100, 7, 2, 9, 1};
    int arr[n];
    int l=0, r=n-1;
    printf("Enter the array elememts: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        arr[i] = a;
    }
    printf("Array elements ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    quicksort(arr, 0, n-1);
    printf("\nArray elements ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}