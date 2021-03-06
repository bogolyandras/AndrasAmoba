#ifndef TICTACTOETABLEMODEL_H
#define TICTACTOETABLEMODEL_H

#include <QAbstractTableModel>
#include "field.h"

class TicTacToeTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TicTacToeTableModel(QObject *parent = 0);
    ~TicTacToeTableModel();

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void loadData(Field* data, int sizeX, int sizeY);

private:
    Field* BoardData;
    int sizeX;
    int sizeY;
};

#endif // TICTACTOETABLEMODEL_H
