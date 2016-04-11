#include <QPixmap>
#include "tictactoetablemodel.h"

TicTacToeTableModel::TicTacToeTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    Q_UNUSED(parent);
    sizeX = 0;
    sizeY = 0;
    BoardData = new Field[sizeX * sizeY];
    for (int i = 0; i < sizeX * sizeY; ++i) {
        BoardData[i] = Field::Empty;
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
        switch (BoardData[index.row() * sizeX + index.column()])
        {
        case Field::X:
            return QPixmap(":/x.png");
        case Field::O:
            return QPixmap(":/o.png");
        }
    }
    return QVariant();
}

void TicTacToeTableModel::loadData(Field* data, int sizeX, int sizeY)
{
    layoutAboutToBeChanged();
    delete[] BoardData;
    BoardData = new Field[sizeX * sizeY];
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    for (int i = 0; i < sizeX * sizeY; ++i) {
        BoardData[i] = data[i];
    }
    layoutChanged();
}
