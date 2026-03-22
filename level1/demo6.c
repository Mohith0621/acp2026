#include <stdio.h>
#include <stdlib.h>

int* create_array(int n);
void initialize_array(int *arr, int n);
void print_array(int *arr, int n);
void delete_array(int **arr);

int main()
{
    int n;
    int *arr = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = create_array(n);
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }


    printf("Enter %d elements:\n", n);
    initialize_array(arr, n);

    printf("Array elements:\n");
    print_array(arr, n);

    delete_array(&arr);

    if (arr == NULL)
    {
        printf("Memory successfully freed and pointer set to NULL.\n");
    }

    return 0;
}


int* create_array(int n)
{
    return (int*)malloc(n * sizeof(int));
}

void initialize_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}


void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_array(int **arr)
{
    if (*arr != NULL)
    {
        free(*arr);     
        *arr = NULL;    
    }
}