#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tictactoetablemodel.h"
#include "board.h"
#include "position.h"
#include "aiplayer.h"

class Controller
{
public:
    Controller();
    ~Controller();
    TicTacToeTableModel* getDataModel();
    void placeObject(Position pos);
    bool getLastMoveExists() const;
    Position getLastMove() const;
    BoardState getBoardState() const;
    const std::vector<Position>& getWinPosition() const;
    void reset();
private:
    TicTacToeTableModel dataModel;
    Board board;
    bool lastMoveExists;
    Position lastMove;
    AiPlayer* ai;
};

#endif // CONTROLLER_H
