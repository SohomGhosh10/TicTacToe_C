// Classroom Tech Intenship
// TicTacToe Game

#include <stdio.h>

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;  // Player has won
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;  // Player has won
    }

    return 0;  // No winner yet
}

// Function to check if the game is a draw
int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;  // Game is not a draw
            }
        }
    }
    return 1;  // Game is a draw
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int row, col;
    int gameResult = 0; // 0: ongoing, 1: draw, 2: X wins, 3: O wins

    do {
        // Display the current state of the board
        displayBoard(board);

        // Prompt the current player to enter their move
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the chosen cell is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            gameResult = (currentPlayer == 'X') ? 2 : 3;
            break;
        }

        // Check for a draw
        if (checkDraw(board)) {
            gameResult = 1;
            break;
        }

        // Switch players for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (1);  // Infinite loop for ongoing game

    // Display the final state of the board
    displayBoard(board);

    // Display the result of the game
    switch (gameResult) {
        case 1:
            printf("It's a draw!\n");
            break;
        case 2:
            printf("Player X wins!\n");
            break;
        case 3:
            printf("Player O wins!\n");
            break;
    }

    return 0;
}
