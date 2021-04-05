#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>

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
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
    bool arduino_esta_conectado = false;

    void conectarArduino();
    void recepcionSerialAsyncrona();
};

#endif // MAINWINDOW_H
