#include <iostream>
#include "tic_tac_toe.h"

using namespace std;

char board[3][3];
char currentMarker;
int currentPlayer;

void setup() {
    currentPlayer = 1;
    currentMarker = 'X';

    // Initialize the board with empty spaces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void drawBoard() {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -----" << endl;
    }
}

bool placeMarker(int row, int col) {
    if (board[row][col] != ' ') {
        return false;
    }
    board[row][col] = currentMarker;
    return true;
}

int winner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return currentPlayer;
    }
    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return currentPlayer;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return currentPlayer;

    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X')
        currentMarker = 'O';
    else
        currentMarker = 'X';

    if (currentPlayer == 1)
        currentPlayer = 2;
    else
        currentPlayer = 1;
}

void game() {
    setup();
    drawBoard();
    int playerWon;

    for (int i = 0; i < 9; i++) {
        cout << "It's player " << currentPlayer << "'s turn. Enter row and column: ";
        int row, col;
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid position! Try again." << endl;
            i--;
            continue;
        }

        if (!placeMarker(row, col)) {
            cout << "This spot is already taken! Try again." << endl;
            i--;
            continue;
        }

        drawBoard();
        playerWon = winner();

        if (playerWon == 1) {
            cout << "Player one wins! Congratulations!" << endl;
            break;
        } else if (playerWon == 2) {
            cout << "Player two wins! Congratulations!" << endl;
            break;
        }

        swapPlayerAndMarker();
    }

    if (playerWon == 0) {
        cout << "It's a tie!" << endl;
    }
}
