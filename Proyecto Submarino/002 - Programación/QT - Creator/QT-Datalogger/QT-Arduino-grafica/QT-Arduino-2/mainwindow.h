#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>


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
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
    bool arduino_esta_conectado = false;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_UNO = 66;
    static const quint16 arduino_MEGA = 67;

    void recepcionSerialAsyncrona();
    void buscaYconectaArduino();
    void graficar(int dato);
    QString obtenerFecha();
    void guardarEvento(QString evento);
    int contador = 0;


};

#endif // MAINWINDOW_H
