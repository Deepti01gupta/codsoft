#include<bits/stdc++.h>
using namespace std;

char board[3][3];
char Player;

void initializeBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
    Player = 'X';
}

void displayBoard() {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << ' ';
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << '|';
        }
        cout << '\n';
        if (i < 2) cout << "  -+-+-\n";
    }
}

bool isWin() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == Player && board[i][1] == Player && board[i][2] == Player) return true;
        if (board[0][i] == Player && board[1][i] == Player && board[2][i] == Player) return true;
    }
    // Check diagonals
    if (board[0][0] == Player && board[1][1] == Player && board[2][2] == Player) return true;
    if (board[0][2] == Player && board[1][1] == Player && board[2][0] == Player) return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void switchPlayer() {
    Player = (Player == 'X') ? 'O' : 'X';
}

void playerMove() {
    int row, col;
    while (true) {
        cout<<"Player "<<Player<<", enter your move (row and column): ";
        cin >> row >> col;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = Player;
            break;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

int main() {
    char playAgain;
    do {
        initializeBoard();
        bool gameOver = false;
        while (!gameOver) {
            displayBoard();
            playerMove();
            if (isWin()) {
                displayBoard();
                cout << "Player " << Player << " wins!\n";
                gameOver = true;
            } else if (isDraw()) {
                displayBoard();
                cout << "The game is a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}


