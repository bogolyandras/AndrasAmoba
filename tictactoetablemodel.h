#ifndef TICTACTOETABLEMODEL_H
#define TICTACTOETABLEMODEL_H

#include <QAbstractTableModel>

class TicTacToeTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TicTacToeTableModel(QObject *parent = 0);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // TICTACTOETABLEMODEL_H
