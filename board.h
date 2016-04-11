#ifndef BOARD_H
#define BOARD_H
#include "field.h"
#include "position.h"

class Board
{
public:
    Board(int sizeX, int sizeY);
    ~Board();
    void createNew(int sizeX, int sizeY);
    int getSizeX() const;
    int getSizeY() const;
    Field* translateForPlayer1();
    Field* translateForPlayer2();
    bool placeForPlayer1(Position pos);
    bool placeForPlayer2(Position pos);
private:
    Field* BoardData;
    int sizeX;
    int sizeY;
};

#endif // BOARD_H
