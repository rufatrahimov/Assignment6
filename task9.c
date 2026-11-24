
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Check if no numbers were entered
    if (argc == 1) {
        printf("You must enter at least one number\n");
        return 1;
    }

    // Compare every number with the remaining numbers
    for (int i = 1; i < argc; i++) {

        for (int j = i + 1; j < argc; j++) {

            // Convert command-line arguments to integers
            if (atoi(argv[i]) == atoi(argv[j])) {

                printf("YES\n");
                return 0;
            }
        }
    }

    // No duplicate numbers found
    printf("NO\n");

    return 0;
}
