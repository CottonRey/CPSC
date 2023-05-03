#include "TicTacToe.h"

int main() {
    TicTacToeGame* p_game = new TicTacToeGame();
    p_game->play();
    delete p_game;
    return 0;
}
