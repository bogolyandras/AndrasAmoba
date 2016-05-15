#include <algorithm>
#include "board.h"

Board::Board(int sizeX, int sizeY)
    : sizeX(sizeX), sizeY(sizeY),
      boardState(BoardState::UnderProgress), winPosition()
{
    BoardData = new Field[sizeX * sizeY];
    for (int i = 0; i < sizeX * sizeY; ++i) {
        BoardData[i] = Field::Empty;
    }
}

Board::~Board()
{
    delete[] BoardData;
}

void Board::createNew(int sizeX, int sizeY)
{
    delete[] BoardData;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    BoardData = new Field[sizeX * sizeY];
    for (int i = 0; i < sizeX * sizeY; ++i) {
        BoardData[i] = Field::Empty;
    }
    boardState = BoardState::UnderProgress;
    winPosition.clear();
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
    for (int i = 0; i < sizeX * sizeY; ++i) {
        data[i] = BoardData[i];
    }
    return data;
}

Field* Board::translateForPlayer2()
{
    Field* data;
    data = new Field[sizeX * sizeY];
    for (int i = 0; i < sizeX * sizeY; ++i) {
        switch (BoardData[i]) {
        case Field::O:
            data[i] = Field::X;
            break;
        case Field::X:
            data[i] = Field::O;
            break;
        default:
            data[i] = BoardData[i];
        }

    }
    return data;
}

bool Board::placeForPlayer1(Position pos)
{
    if (BoardData[Position::TranslatePosition(pos, sizeX, sizeY)] == Field::Empty) {
        BoardData[Position::TranslatePosition(pos, sizeX, sizeY)] = Field::O;
        checkBoardState();
        return true;
    }
    return false;
}

bool Board::placeForPlayer2(Position pos)
{
    if (BoardData[Position::TranslatePosition(pos, sizeX, sizeY)] == Field::Empty) {
        BoardData[Position::TranslatePosition(pos, sizeX, sizeY)] = Field::X;
        checkBoardState();
        return true;
    }
    return false;
}

BoardState Board::getBoardState() const
{
    return boardState;
}

std::vector<Position> Board::getWinPosition() const
{
    return winPosition;
}

void Board::checkBoardState()
{
    checkForSpecificPlayer(Field::O);

    if (winPosition.size() > 0) {
        boardState =  BoardState::Player1Win;
        return;
    }

    checkForSpecificPlayer(Field::X);

    if (winPosition.size() > 0) {
        boardState =  BoardState::Player2Win;
        return;
    }

}

void Board::checkForSpecificPlayer(Field lookingFor)
{
    //Iterate over all the positions
    for (int i = 0; i < sizeX * sizeY; ++i) {
        Position p = Position::TranslatePosition(i, sizeX, sizeY);

        /*
         * XXXXX
         *
         *
         *
         *
         */
        if (p.X + 4 < sizeX) {
            for (int j = 0; j < 5; ++j) {
                Position p2 = p;
                p2.X += j;
                if (lookingFor != BoardData[Position::TranslatePosition(p2, sizeX, sizeY)])
                    break;
                if (j == 4) {
                    for (int j = 0; j < 5; ++j) {
                        Position p3 = p;
                        p3.X += j;
                        addWinPosition(p3);
                    }
                }
            }
        }

        /*
         * X
         *  X
         *   X
         *    X
         *     X
         */
        if (p.X + 4 < sizeX && p.Y + 4 < sizeY) {
            for (int j = 0; j < 5; ++j) {
                Position p2 = p;
                p2.X += j;
                p2.Y += j;
                if (lookingFor != BoardData[Position::TranslatePosition(p2, sizeX, sizeY)])
                    break;
                if (j == 4) {
                    for (int j = 0; j < 5; ++j) {
                        Position p3 = p;
                        p3.X += j;
                        p3.Y += j;
                        addWinPosition(p3);
                    }
                }
            }
        }

        /*
         * X
         * X
         * X
         * X
         * X
         */
        if (p.Y + 4 < sizeY) {
            for (int j = 0; j < 5; ++j) {
                Position p2 = p;
                p2.Y += j;
                if (lookingFor != BoardData[Position::TranslatePosition(p2, sizeX, sizeY)])
                    break;
                if (j == 4) {
                    for (int j = 0; j < 5; ++j) {
                        Position p3 = p;
                        p3.Y += j;
                        addWinPosition(p3);
                    }
                }
            }
        }

        /*
         *     X
         *    X
         *   X
         *  X
         * X
         */
        if (p.X - 4 >= 0 && p.Y + 4 < sizeY) {
            for (int j = 0; j < 5; ++j) {
                Position p2 = p;
                p2.X -= j;
                p2.Y += j;
                if (lookingFor != BoardData[Position::TranslatePosition(p2, sizeX, sizeY)])
                    break;
                if (j == 4) {
                    for (int j = 0; j < 5; ++j) {
                        Position p3 = p;
                        p3.X -= j;
                        p3.Y += j;
                        addWinPosition(p3);
                    }
                }
            }
        }
    }
}

void Board::addWinPosition(Position p)
{
    bool found = (std::find(winPosition.begin(), winPosition.end(), p) != winPosition.end());
    if (!found)
        winPosition.push_back(p);
}
