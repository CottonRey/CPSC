#include "TicTacToe.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor
TicTacToeGame::TicTacToeGame() {
    pp_cGrid = new char*[3];
    for (int i = 0; i < 3; i++) {
        pp_cGrid[i] = new char[3];
        for (int j = 0; j < 3; j++) {
            pp_cGrid[i][j] = '~';
        }
    }
    m_iTurnCount = 0;
    m_bGameOver = false;
    m_bHumanWon = false;
}

// Destructor
TicTacToeGame::~TicTacToeGame() {
    for (int i = 0; i < 3; i++) {
        delete[] pp_cGrid[i];
    }
    delete[] pp_cGrid;
}

// Displays the Tic Tac Toe grid
void TicTacToeGame::displayGrid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << pp_cGrid[i][j] << " ";
        }
        cout << endl;
    }
}

// Gets the user's move
void TicTacToeGame::getUserMove() {
    int row, col;
    do {
        cout << "Enter row number (0-2): ";
        cin >> row;
        cout << "Enter column number (0-2): ";
        cin >> col;
        if (row < 0 || row > 2) {
            cout << "Row number should be 0, 1, or 2" << endl;
        }
        else if (col < 0 || col > 2) {
            cout << "Column number should be 0, 1, or 2" << endl;
        }
        else if (pp_cGrid[row][col] != '~') {
            cout << "That square is already taken. Try again." << endl;
        }
    } while (row < 0 || row > 2 || col < 0 || col > 2 || pp_cGrid[row][col] != '~');

    pp_cGrid[row][col] = 'X';
}

// Determines the computer's counter move
void TicTacToeGame::getComputerMove() {
    // Generate random row and column until an empty square is found
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (pp_cGrid[row][col] != '~');

    pp_cGrid[row][col] = 'O';
}

// Checks if a player has won
bool TicTacToeGame::isWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (pp_cGrid[i][0] == player && pp_cGrid[i][1] == player && pp_cGrid[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (pp_cGrid[0][i] == player && pp_cGrid[1][i] == player && pp_cGrid[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (pp_cGrid[0][0] == player && pp_cGrid[1][1] == player && pp_cGrid[2][2] == player) {
        return true;
    }
    if (pp_cGrid[0][2] == player && pp_cGrid[1][1] == player && pp_cGrid[2][0] == player) {
        return true;
    }

    // No win condition found
    return false;
}

void TicTacToeGame::play() {

    // Display initial game board
    bool isGameOver = false;
    displayGrid();

    // Play until game is over
    while (!isGameOver) {
        // Player's turn
        getUserMove();
        displayGrid();

        // Check if player has won
        if (isWin('X')) {
            std::cout << "You won!" << std::endl;
            isGameOver = true;
            return;
        }

        // Computer's turn
        std::cout << "Computer's turn..." << std::endl;
        getComputerMove();
        displayGrid();

        // Check if computer has won
        if (isWin('O')) {
            std::cout << "Computer won!" << std::endl;
            isGameOver = true;
            return;
        }
    }

    // If no one won, it's a draw
    std::cout << "It's a draw!" << std::endl;
    isGameOver = true;
}
