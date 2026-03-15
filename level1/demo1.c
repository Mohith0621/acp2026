#include <stdio.h>

void input(int n, float arr[n]);
int find_max_index(int n, float arr[n]);
void output(float arr[], int max_index);

int main() {
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    if (n<=0) {
        printf("Invalid number of elements.");
        return 0;
    }
    float arr[n];
    printf("Enter the array elements:\n");
    input(n,arr);
    int max_index=find_max_index(n,arr);
    output(arr,max_index);
    return 0;
}

void input(int n, float arr[n]) {
    for(int i=0; i<n;i++){
        scanf("%f",&arr[i]);
    }
}

int find_max_index(int n, float arr[n]) {
    int max_index=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[max_index]){
            max_index=i;
        }
    }
   return max_index;
}

void output(float arr[], int max_index) {
    printf("Maximum element is %.2f\n",arr[max_index] );
    printf("Index of maximum element is %d\n", max_index);
}