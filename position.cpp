#include "position.h"

Position::Position()
{

}

Position::Position(int X, int Y) : X(X), Y(Y)
{

}

int Position::TranslatePosition(Position pos, int sizeX, int sizeY)
{
    return pos.Y * sizeX + pos.X;
}

Position Position::TranslatePosition(int i, int sizeX, int sizeY)
{
    return Position(i % sizeX, i / sizeX);
}
