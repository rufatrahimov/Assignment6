
#include <stdio.h>

#define SIZE 3

// Function to display the game board
void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// Function to check if a player has won
int checkWinner(char board[SIZE][SIZE], char player) {

    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player) {
            return 1;
        }
    }

    // Check main diagonal
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player) {
        return 1;
    }

    // Check opposite diagonal
    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Main function
int main() {

    // Initialize the 3x3 board
    char board[SIZE][SIZE] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    char player = 'X';
    int row, col;
    int moves = 0;

    // Continue until someone wins or the game is tied
    while (moves < 9) {

        displayBoard(board);

        printf("'%c', choose your location (row, column): ", player);

        // Check if input is valid
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input! Enter two numbers.\n");

            // Clear invalid input
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            continue;
        }

        // Check if indexes are within the board
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Invalid indexes! Choose numbers from 0 to 2.\n");
            continue;
        }

        // Check if the selected location is already occupied
        if (board[row][col] != '-') {
            printf("This location is already taken! Try again.\n");
            continue;
        }

        // Place the player's symbol
        board[row][col] = player;
        moves++;

        // Check if the current player has won
        if (checkWinner(board, player)) {
            displayBoard(board);
            printf("Player %c wins!\n", player);
            return 0;
        }

        // Switch players
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
    }

    // If all 9 cells are filled and nobody wins
    displayBoard(board);
    printf("The game is a tie!\n");

    return 0;
}
