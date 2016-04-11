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
    if(index.isValid()) {
        //QMessageBox msgBox;
        //msgBox.setText("Igen: " + QString::number(index.column()) + " " + QString::number(index.row()));
        //msgBox.exec();
        Position p(index.column(), index.row());
        controller.placeObject(p);

    }
}
