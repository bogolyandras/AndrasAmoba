#include "tictactoetablemodel.h"

TicTacToeTableModel::TicTacToeTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    Q_UNUSED(parent);
    sizeX = 11;
    sizeY = 11;
    BoardData = new char[sizeX * sizeY];
}

TicTacToeTableModel::~TicTacToeTableModel()
{
    delete[] BoardData;
}

int TicTacToeTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return sizeY;
}

int TicTacToeTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return sizeX;
}

QVariant TicTacToeTableModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role);
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
