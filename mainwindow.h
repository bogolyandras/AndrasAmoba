#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <controller.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setController(Controller *controller);

private slots:
    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;
    Controller *controller;
};

#endif // MAINWINDOW_H
