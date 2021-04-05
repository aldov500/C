#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include<QDate>
#include<QFile>
#include<QFileInfo>
#include<QProcess>

QVector<double> XX(100), YY(100);

void MainWindow::guardarEvento(QString evento){
    QString nombreArchivo = "datalogger.csv";
    QFile errorArchivo(nombreArchivo);
   // errorArchivo.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    errorArchivo.open(QIODevice::WriteOnly | QIODevice::Append  | QIODevice::Text);
    QTextStream textoError(&errorArchivo);
    textoError <<evento.toUtf8().constData() << ";"<<  obtenerFecha().toUtf8().constData() << "\n\r";
    errorArchivo.close();
}

QString MainWindow::obtenerFecha(void){
    int diaInt = QDate::currentDate().day();
    int mesInt = QDate::currentDate().month();
    int anioInt = QDate::currentDate().year();

    QDateTime  tiempo1UTC = QDateTime::currentDateTime();
    QString dia;
    QString mes;
    QString anio;

    if(diaInt <= 9) dia = "0" + QString::number(diaInt);
    else dia = QString::number(diaInt);

    if(mesInt <= 9) mes = "0" + QString::number(mesInt);
    else mes = QString::number(mesInt);

    anio = QString::number(anioInt);

    QString fecha;
    fecha = anio + "-";
    fecha += mes + "-";
    fecha += dia;
    fecha += "-" + tiempo1UTC.toString();
    return fecha;

}


void MainWindow::graficar(int dato){
       QCustomPlot *graficando = ui->grafica;
       graficando->addGraph();
       YY[contador] = dato;
       XX[contador] = contador;
       graficando->graph(0)->setData(XX, YY);
       contador++;
       if(contador>=99) { contador=0;
           for(int i=0; i<=99; i++){
               YY[i] = 0;
               XX[i] = 0;
           }
       }
       graficando->xAxis->setLabel("Eje X");
       graficando->yAxis->setLabel("Eje Y");
       graficando->xAxis->setRange(0, 100);
       graficando->yAxis->setRange(0, 1023);
       ui->grafica->replot();
}

void MainWindow::recepcionSerialAsyncrona(){
    if(arduino_esta_conectado && arduino->isReadable()){
        //QByteArray datosLeidos = arduino->readAll();
        QByteArray datosLeidos = arduino->readLine();
        int indice0 = datosLeidos.indexOf("\n");
        int indice1 = datosLeidos.indexOf("@");
        QString infoExtraida = datosLeidos.mid(indice1+1,(indice0-indice1));
        int datoEntero = infoExtraida.toInt();
        guardarEvento(QString::number(datoEntero));
        ui->lcdNumber->display(datoEntero);
        if(indice0>=0 && indice1>=0) {
                qDebug() << "Datos extraidos: " << infoExtraida.toUtf8().constData();
                qDebug() << "Datos leidos: " << datosLeidos << endl;
                graficar(datoEntero);

        }


    }
}

void MainWindow::buscaYconectaArduino(){

    //Parte # 1, declaración inicial de las variables
    arduino_esta_conectado = false;
    arduino = new QSerialPort(this);
    connect(arduino, &QSerialPort::readyRead, this, &MainWindow::recepcionSerialAsyncrona);

    QString nombreDispositivoSerial = "";
    int nombreProductID = 0;

    //Parte # 2,buscar puertos con los identificadores de Arduino
    qDebug() << "Puertos disponibles: " << QSerialPortInfo::availablePorts().length();
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Identificador del fabricante (VENDOR ID): " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "ID Vendedor " << serialPortInfo.vendorIdentifier();
            qDebug() << "ID Producto: " << serialPortInfo.productIdentifier();

            if(serialPortInfo.productIdentifier() == arduino_UNO || serialPortInfo.productIdentifier() == arduino_MEGA){
                arduino_esta_conectado = true;
                nombreDispositivoSerial = serialPortInfo.portName();
                nombreProductID = serialPortInfo.productIdentifier();
            }
        }

    }

    //Parte # 3, conexión del puerto encontrado con Arduino

    if(arduino_esta_conectado){

        arduino ->setPortName(nombreDispositivoSerial);
        arduino->open(QIODevice::ReadWrite);
        arduino->setDataBits(QSerialPort::Data8);
        arduino ->setBaudRate(QSerialPort::Baud115200);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
         ui->label->clear();
        qDebug() << "Producto: " << nombreProductID;
        if(nombreProductID == 66) ui->label->setText("Arduino UNO R3 conectado");
        else if(nombreProductID == 67) ui->label->setText("Arduino Mega conectado");
        else ui->label->setText("Error 3");

    }
    else{
        ui->label->clear();
        ui->label->setText("No hay arduino");
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buscaYconectaArduino();


}

MainWindow::~MainWindow()
{
    delete ui;
    arduino->close();

}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if(arduino_esta_conectado && arduino->isWritable()){
        QString datoParaEnviar = QString::number(arg1)+"\n";
        arduino->write(datoParaEnviar.toUtf8().constData());

    }
}
