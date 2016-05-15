#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "field.h"
#include "position.h"
#include "boardstate.h"

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
    BoardState getBoardState() const;
private:
    Field* BoardData;
    int sizeX;
    int sizeY;
    BoardState boardState;
    std::vector<Position> winPosition;
    void checkBoardState();
};

#endif // BOARD_H
