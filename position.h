#ifndef POSITION_H
#define POSITION_H


class Position
{
public:
    Position();
    Position(int X, int Y);
    int X, Y;
    static int TranslatePosition(Position pos, int sizeX, int sizeY);
};

#endif // POSITION_H
