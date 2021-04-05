#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

QProcess* pro;
QString program = "/home/aldo/Escritorio/QT-opencv-1";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pro = new QProcess();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    pro->start(program);
}


void MainWindow::on_pushButton_2_clicked()
{
    pro->kill();
}
