
#include <stdio.h>

// Function to copy one array into another using pointers
void copy_array(int *source, int *destination, int size) {

    // Copy elements using pointers
    for (int i = 0; i < size; i++) {
        *(destination + i) = *(source + i);
    }
}

int main() {

    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[5];

    int size = 5;

    // Call the function
    copy_array(arr1, arr2, size);

    // Print the copied array
    printf("Copied array: ");

    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr2 + i));
    }

    return 0;
}
