#include "controller.h"

Controller::Controller() : board(11, 11)
{
    Field* data = board.translateForPlayer1();
    dataModel.loadData(data, board.getSizeX(), board.getSizeY());
    delete[] data;
}

TicTacToeTableModel *Controller::getDataModel()
{
    return &(this->dataModel);
}

void Controller::placeObject(Position pos)
{
    board.placeForPlayer1(pos);
    Field* data = board.translateForPlayer1();
    dataModel.loadData(data, board.getSizeX(), board.getSizeY());
    delete[] data;
}
