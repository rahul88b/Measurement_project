#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "t_test.h"
#include "chi_test.h"

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

void MainWindow::on_pushButton_clicked()
{
    t_test t;
    t.setModal(true);
    t.exec();
}



void MainWindow::on_pushButton_3_clicked()
{
    chi_test chi;
    chi.setModal(true);
    chi.exec();
}
