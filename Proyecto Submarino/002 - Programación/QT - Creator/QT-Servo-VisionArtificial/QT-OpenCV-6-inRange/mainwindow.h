#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void ftimer();


private slots:
    void on_pushButton_clicked();


    void on_barraCanal0Min_sliderMoved(int position);

    void on_barraCanal0Max_sliderMoved(int position);

    void on_barraCanal1Min_sliderMoved(int position);

    void on_barraCanal1Max_sliderMoved(int position);

    void on_barraCanal2Min_sliderMoved(int position);

    void on_barraCanal2Max_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
    bool arduino_esta_conectado = false;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_UNO = 66;
    static const quint16 arduino_MEGA = 67;

    void buscaYconectaArduino();
};

#endif // MAINWINDOW_H
