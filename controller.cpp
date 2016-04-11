#include "controller.h"

Controller::Controller()
{

}

TicTacToeTableModel *Controller::getDataModel()
{
    return &(this->dataModel);
}
