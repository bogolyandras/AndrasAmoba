#include "tictactoetablemodel.h"

TicTacToeTableModel::TicTacToeTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    Q_UNUSED(parent);
}

int TicTacToeTableModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 0;
}

int TicTacToeTableModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 0;
}

QVariant TicTacToeTableModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role);
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
