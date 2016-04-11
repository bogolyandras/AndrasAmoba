#ifndef BOARD_H
#define BOARD_H
#include "field.h"

class Board
{
public:
    Board(int sizeX, int sizeY);
    ~Board();
    int getSizeX() const;
    int getSizeY() const;
    Field* translateForPlayer1();
private:
    Field* BoardData;
    int sizeX;
    int sizeY;
};

#endif // BOARD_H
