#include "controller.h"
#include "randomaiplayer.h"

Controller::Controller() :
    board(35, 25), lastMoveExists(false), lastMove(0, 0)
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

void Controller::reset()
{
    board.createNew(35, 25);
    Field* data = board.translateForPlayer1();
    dataModel.loadData(data, board.getSizeX(), board.getSizeY());
    delete[] data;
    lastMoveExists = false;
}

TicTacToeTableModel *Controller::getDataModel()
{
    return &(this->dataModel);
}

void Controller::placeObject(Position pos)
{
    //Attempt placement for human player
    if (!board.placeForPlayer1(pos))
    {
        lastMoveExists = true;
        lastMove = pos;
        return; //If not succesful, return...
    }

    //Place for the AI
    Position aiMove = ai->place(board.translateForPlayer2(), board.getSizeX(), board.getSizeY());
    lastMoveExists = true;
    lastMove = aiMove;
    board.placeForPlayer2(aiMove);

    //Update the model
    Field* data = board.translateForPlayer1();
    dataModel.loadData(data, board.getSizeX(), board.getSizeY());
    delete[] data;
}

bool Controller::getLastMoveExists() const
{
    return lastMoveExists;
}

Position Controller::getLastMove() const
{
    return lastMove;
}
