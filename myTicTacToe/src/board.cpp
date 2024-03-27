#include "board.h"
#include <iostream>

Board::Board() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void Board::display() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
                if (j < 2) {
                    std::cout << " | ";
                }
            }
        std::cout << std::endl;
        if (i < 2){
            std::cout <<"---------" << std::endl;
        }
    }
}

bool Board::makeMove(int row, int col, char symbol) {
    if (row < 0 || row >= 3 
     || col < 0 || col >=3 
     || board[row][col] != ' ') {
        return false;
    }
    board[row][col] = symbol;
    return true;
}

bool Board::gameOver() const {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' '
            && board[i][0] == board[i][1]
            && board[i][1] == board[i][2]){
            return true;
        }
    }

    for (int j = 0; j < 3; ++j) {
        if (board[0][j] != ' '
            && board[0][j] == board[1][j]
            && board[1][j] == board[2][j]) {
            return true;
        }
    }

    if (board[0][0] != ' ' 
        && board[0][0] == board[1][1]
        && board[1][1] == board[2][2]) {
        return true;
    }

    if (board[0][2] != ' '
        && board[0][2] == board[1][1]
        && board[1][1] == board[2][0]) {
        return true;
    }

   for (int i = 0; i < 3; ++i) {
       for (int j = 0; j < 3; ++j) {
           if (board[i][j] == ' ') {
               return false;
           }
       }
   }
   return true;
}
