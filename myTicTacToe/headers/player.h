#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    char symbol;

public:
    Player(char s);

    char getSymbol() const;
};

#endif //PLAYER_H
