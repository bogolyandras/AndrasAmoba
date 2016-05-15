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
    //Check if game in progress
    if (controller.getBoardState() != BoardState::UnderProgress) {
        return;
    }

    //Check if it is clicked on the board
    if(index.isValid()) {
        Position p(index.column(), index.row());
        controller.placeObject(p);

        if(controller.getBoardState()==BoardState::UnderProgress) {
            //Mark last movement
            markLastStepIfPossible();
        } else {
            ui->tableView->clearSelection();

            std::vector<Position> winPositions = controller.getWinPosition();
            for (std::vector<Position>::iterator it = winPositions.begin();
                 it != winPositions.end();
                 ++it) {

                Position winningPosition = (*it);
                ui->tableView->selectionModel()->select(
                            ui->tableView->model()->index(winningPosition.Y, winningPosition.X), QItemSelectionModel::Select);

            }

            QMessageBox msgBox;
            msgBox.setWindowTitle("The game ends!");
            if (controller.getBoardState()==BoardState::Player1Win) {
                msgBox.setText("You win!");
            } else {
                msgBox.setText("You lost!");
            }
            msgBox.exec();
        }

    }
}

void MainWindow::on_actionNew_game_triggered()
{
    controller.reset(ui->actionI_am_starting_the_game->isChecked());
    markLastStepIfPossible();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("About Tic Tac Toe");
    msgBox.setText("Copyright © 2016\nAndrás Bögöly \nSome rights reserved, see LICENSE.md");
    msgBox.exec();
}

void MainWindow::markLastStepIfPossible()
{
    //Mark last movement
    if (controller.getLastMoveExists())
    {
        Position lastMove = controller.getLastMove();
        ui->tableView->clearSelection();
        ui->tableView->selectionModel()->select(
                    ui->tableView->model()->index(lastMove.Y, lastMove.X), QItemSelectionModel::Select);
    }
}
