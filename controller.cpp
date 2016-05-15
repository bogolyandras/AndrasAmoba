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
    //Check if game in progress
    if (board.getBoardState()!=BoardState::UnderProgress)
        return;

    //Attempt placement for human player
    bool lastMoveSuccess = board.placeForPlayer1(pos);
    lastMoveExists = true;
    lastMove = pos;
    if (!lastMoveSuccess)
        return; //If not succesful, return with the unsuccesful position

    //Place for the AI if game still in progress
    if (board.getBoardState()==BoardState::UnderProgress) {
        Position aiMove = ai->place(board.translateForPlayer2(), board.getSizeX(), board.getSizeY());
        lastMoveExists = true;
        lastMove = aiMove;
        board.placeForPlayer2(aiMove);
    }

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

BoardState Controller::getBoardState() const
{
    return board.getBoardState();
}

std::vector<Position> Controller::getWinPosition() const
{
    return board.getWinPosition();
}
