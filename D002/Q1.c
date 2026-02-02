#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int *arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter array elements: ");
    for (int k = 0; k < n; k++) {
        scanf("%d", &arr[k]);
    }

    int i;
    printf("Enter index to delete: ");
    scanf("%d", &i);

  
    for (int k = i; k < n - 1; k++) {
        arr[k] = arr[k + 1];
    }

    n--;  

    int *temp = realloc(arr, n * sizeof(int));
    if (temp != NULL || n == 0) {   
        arr = temp;
    }

    printf("Updated array: ");
    for (int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }

    free(arr);
    return 0;
}
