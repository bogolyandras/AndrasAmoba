#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "tictactoetablemodel.h"

class Controller
{
public:
    Controller();
    TicTacToeTableModel* getDataModel();
private:
    TicTacToeTableModel dataModel;
};

#endif // CONTROLLER_H
