#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tictactoetablemodel.h"
#include "board.h"

class Controller
{
public:
    Controller();
    TicTacToeTableModel* getDataModel();
    void placeObject(int positionX, int positionY);
private:
    TicTacToeTableModel dataModel;
    Board board;
};

#endif // CONTROLLER_H
