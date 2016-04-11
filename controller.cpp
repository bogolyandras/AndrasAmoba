#include "controller.h"

Controller::Controller() : board(11, 11)
{

}

TicTacToeTableModel *Controller::getDataModel()
{
    return &(this->dataModel);
}

void Controller::placeObject(int positionX, int positionY)
{

}
