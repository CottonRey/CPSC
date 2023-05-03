#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToeGame {
private:
    char **pp_cGrid; // pointer to pointer to char
    int m_iTurnCount;
    bool m_bGameOver;
    bool m_bHumanWon;
public:
    TicTacToeGame(); // constructor
    ~TicTacToeGame(); // destructor
    void play(); // game loop
    void displayGrid(); // displays the grid
    void getUserMove(); // gets the user's move
    void getComputerMove(); // gets the computer's move
    bool isWin(char cPlayer); // checks if the given player has won
};

#endif
