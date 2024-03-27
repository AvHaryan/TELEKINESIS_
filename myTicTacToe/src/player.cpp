#include "player.h"

Player::Player(char s) : symbol(s) {}

char Player::getSymbol() const {
    return symbol;
}
