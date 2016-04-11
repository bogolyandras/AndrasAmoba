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
    TicTacToeTableModel* getDataModel();
    void placeObject(Position pos);
private:
    TicTacToeTableModel dataModel;
    Board board;
    AiPlayer* ai;
};

#endif // CONTROLLER_H
