#include <stdio.h>

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int move, player = 1, row, col, i;
    char mark;

    while (1) {
        // Display board
        printf("\n");
        for (i = 0; i < 3; i++) {
            printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
            if (i < 2) printf("---|---|---\n");
        }

        // Player input
        player = (player % 2 == 1) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d, enter a number (1-9): ", player);
        scanf("%d", &move);

        // Convert move to board index
        if (move < 1 || move > 9) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        row = (move - 1) / 3;
        col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Spot already taken! Try another.\n");
            continue;
        }

        board[row][col] = mark;

        // Check win conditions
        for (i = 0; i < 3; i++) {
            if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
                (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
                goto win;
            }
        }
        if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
            (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
            goto win;
        }

        if (player == 9) break; // Max 9 moves (full board)

        player++;
    }

    printf("It's a draw!\n");
    return 0;

win:
    // Final display
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("🎉 Player %d (%c) wins!\n", player, mark);
    return 0;
}
