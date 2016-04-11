#include "board.h"

Board::Board(int sizeX, int sizeY)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    BoardData = new Field[sizeX * sizeY];
    for (int i = 0; i < sizeX * sizeY; ++i) {
        BoardData[i] = Field::Empty;
    }
}

Board::~Board()
{
    delete[] BoardData;
}

int Board::getSizeX() const
{
    return sizeX;
}

int Board::getSizeY() const
{
    return sizeY;
}

Field* Board::translateForPlayer1()
{
    Field* data;
    data = new Field[sizeX * sizeY];
    for (int i = 0; i < sizeX + sizeY; ++i) {
        data[i] = BoardData[i];
    }
    return data;
}
