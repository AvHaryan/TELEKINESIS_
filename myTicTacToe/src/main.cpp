#include <iostream>
#include "board.h"
#include "player.h"
int main() {
   Board board;
   Player player1('X');
   Player player2('0');
   Player* currentPlayer = &player1;

   while(!board.gameOver()) {
       std::cout << "Current board:\n";
       board.display();
       int row{};
       int col{};
       std::cout << currentPlayer->getSymbol() << "'s turn. Enter row and column (0-2): ";
       std::cin >> row >> col;
       if (!board.makeMove(row, col, currentPlayer->getSymbol())) {
           std::cout << "invalid move Please try again.\n";
           continue;
       }

       currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;

   }

   std::cout << "Final board: \n";
   board.display();

   if (board.gameOver()) {
       std::cout << "Game Over. ";
   }
   else {
       std::cout << "It's a Draw. ";
   }
   std::cout << "Thank you for playing!\n";
  
}
