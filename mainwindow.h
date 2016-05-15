#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_tableView_clicked(const QModelIndex &index);

    void on_actionNew_game_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    Controller controller;
    void markLastStepIfPossible();
};

#endif // MAINWINDOW_H
