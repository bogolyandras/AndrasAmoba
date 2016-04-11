#include <QPixmap>
#include "tictactoetablemodel.h"

TicTacToeTableModel::TicTacToeTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    Q_UNUSED(parent);
    sizeX = 11;
    sizeY = 11;
    BoardData = new char[sizeX * sizeY];
    for (int i = 0; i < sizeX * sizeY; ++i) {
        BoardData[i] = 0;
    }
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
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DecorationRole) {
        if (index.row() == 5 && index.column() == 5)
            return QPixmap(":/x.png");
        if (index.row() == 6 && index.column() == 7)
            return QPixmap(":/o.png");
    }
    return QVariant();
}
