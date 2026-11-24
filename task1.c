
#include <stdio.h>
#include <stdbool.h>

#define N 5

// Function to check if the matrix is cool
bool isCoolMatrix(int arr[N][N]) {

    int leftSum = 0;
    int rightSum = 0;

    // Loop through the matrix diagonals
    for (int i = 0; i < N; i++) {

        // Calculate left diagonal sum
        leftSum += arr[i][i];

        // Calculate right diagonal sum
        rightSum += arr[i][N - 1 - i];
    }

    // Check if both averages are equal
    return leftSum == rightSum;
}

int main() {

    // Create and initialize a 5x5 matrix
    int matrix2[N][N] = {
        {0, 5, 9, 7, 3},
        {1, 5, 6, 8, 3},
        {4, 7, 5, 9, 3},
        {3, 2, 1, 6, 0},
        {4, 2, 6, 7, 9}
    };

    // Display the result
    if (isCoolMatrix(matrix2)) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }

    return 0;
}
