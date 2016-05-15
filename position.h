#ifndef POSITION_H
#define POSITION_H


class Position
{
public:
    Position();
    Position(int X, int Y);
    int X, Y;
    bool operator==(const Position &otherPosition);
    static int TranslatePosition(Position pos, int sizeX, int sizeY);
    static Position TranslatePosition(int i, int sizeX, int sizeY);
};

#endif // POSITION_H
