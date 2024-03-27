#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    char board[3][3];
    
public:
    Board();

    void display() const;

    bool makeMove(int row, int col, char symbol);

    bool gameOver() const;
};

#endif // BOARD_H
