#include <stdio.h>

void read_array(int n, int arr[]);
void print_array(int n, int arr[]);
void swap_array(int n, int a[n], int b[n]);

int main() {
    int n;
    printf("Enter the size of arrays: ");
    scanf("%d", &n);
    
    int a[n], b[n];
    
    printf("Enter elements of array a:\n");
    read_array(n, a);
    
    printf("Enter elements of array b:\n");
    read_array(n, b);
    
    printf("\nBefore swap:\n");
    printf("Array a: ");
    print_array(n, a);
    printf("Array b: ");
    print_array(n, b);
    
    swap_array(n, a, b);
    
    printf("\nAfter swap:\n");
    printf("Array a: ");
    print_array(n, a);
    printf("Array b: ");
    print_array(n, b);
    
    return 0;
}

void read_array(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void print_array(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap_array(int n, int a[n], int b[n]) {
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
