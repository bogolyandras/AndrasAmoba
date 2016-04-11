#include "controller.h"
#include "randomaiplayer.h"

Controller::Controller() : board(11, 11)
{
    ai = new RandomAIPlayer();
    Field* data = board.translateForPlayer1();
    dataModel.loadData(data, board.getSizeX(), board.getSizeY());
    delete[] data;
}

Controller::~Controller()
{
    delete ai;
}

TicTacToeTableModel *Controller::getDataModel()
{
    return &(this->dataModel);
}

void Controller::placeObject(Position pos)
{
    if (!board.placeForPlayer1(pos))
        return;
    board.placeForPlayer2(ai->place(board.translateForPlayer2(), board.getSizeX(), board.getSizeY()));

    Field* data = board.translateForPlayer1();
    dataModel.loadData(data, board.getSizeX(), board.getSizeY());
    delete[] data;
}
