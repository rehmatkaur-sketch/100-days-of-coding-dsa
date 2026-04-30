//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.
#include <stdio.h>
int main() {
int n,i;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements of array: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}