#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{

}

void MainWindow::on_actionSave_as_triggered()
{

}

void MainWindow::on_actionQuit_triggered()
{

}

void MainWindow::on_actionAdd_triggered()
{

}

void MainWindow::on_actionRemove_triggered()
{

}

void MainWindow::on_actionAbout_Qt_triggered()
{

}
