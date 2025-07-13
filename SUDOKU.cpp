#include <iostream>
using namespace std;

#define N 9

// Sample Sudoku puzzle (0 = empty)
int board[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

void printBoard() {
    cout << "\nSudoku Board:\n";
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0)
            cout << "---------------------\n";
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0)
                cout << "| ";
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num)
            return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;
    return true;
}

bool solveSudoku() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku())
                            return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void userInput() {
    int row, col, num;
    cout << "Enter row (1-9), col (1-9), and number (1-9): ";
    cin >> row >> col >> num;
    row--; col--;
    if (board[row][col] == 0 && isValid(row, col, num)) {
        board[row][col] = num;
        cout << "Move accepted!\n";
    } else {
        cout << "Invalid move!\n";
    }
}

int main() {
    int choice;
    while (true) {
        printBoard();
        cout << "\n1. Enter a number\n2. Solve the puzzle\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                userInput();
                break;
            case 2:
                if (solveSudoku())
                    cout << "Solved successfully!\n";
                else
                    cout << "No solution exists!\n";
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
