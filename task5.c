
#include <stdio.h>
#include <stdarg.h>

// Function to find the maximum age
int max(int count, ...) {

    va_list args;
    int age;
    int maximum;

    // Start reading variable arguments
    va_start(args, count);

    // Read the first age
    maximum = va_arg(args, int);

    // Check the remaining ages
    for (int i = 1; i < count; i++) {

        age = va_arg(args, int);

        // Update maximum if a greater age is found
        if (age > maximum) {
            maximum = age;
        }
    }

    // End variable arguments
    va_end(args);

    return maximum;
}

int main() {

    // Example 1
    int m = max(5, 30, 1, 29, 5, 19);
    printf("Max age is: %d.\n", m);

    // Example 2
    int n = max(3, 12, 12, 11);
    printf("Max age is: %d.\n", n);

    return 0;
}
