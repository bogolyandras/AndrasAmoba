#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "position.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(controller.getDataModel());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    //Check if it is clicked on the board
    if(index.isValid()) {
        Position p(index.column(), index.row());
        controller.placeObject(p);

        //Mark last movement
        if (controller.getLastMoveExists())
        {
            Position lastMove = controller.getLastMove();
            ui->tableView->clearSelection();
            ui->tableView->selectionModel()->select(
                        ui->tableView->model()->index(lastMove.Y, lastMove.X), QItemSelectionModel::Select);
        }

    }
}

void MainWindow::on_actionNew_game_triggered()
{
    controller.reset();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("About Tic Tac Toe");
    msgBox.setText("Copyright © 2016\nAndrás Bögöly \nSome rights reserved, see LICENSE.md");
    msgBox.exec();
}
