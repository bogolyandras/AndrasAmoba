#include "controller.h"
#include "randomaiplayer.h"

Controller::Controller() : board(35, 25)
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

Position Controller::placeObject(Position pos)
{
    if (!board.placeForPlayer1(pos))
        return pos;
    Position aiMove = ai->place(board.translateForPlayer2(), board.getSizeX(), board.getSizeY());
    board.placeForPlayer2(aiMove);

    Field* data = board.translateForPlayer1();
    dataModel.loadData(data, board.getSizeX(), board.getSizeY());
    delete[] data;

    return aiMove;
}
