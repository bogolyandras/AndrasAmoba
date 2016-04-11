#ifndef BOARD_H
#define BOARD_H


class Board
{
public:
    Board(int sizeX, int sizeY);
    ~Board();
    int getSizeX() const;
    int getSizeY() const;
private:
    char* BoardData;
    int sizeX;
    int sizeY;
};

#endif // BOARD_H
