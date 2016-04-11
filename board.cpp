#include "board.h"

Board::Board(int sizeX, int sizeY)
{
    BoardData = new char[sizeX * sizeY];
    for (int i = 0; i < sizeX * sizeY; ++i) {
        BoardData[i] = 0;
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
