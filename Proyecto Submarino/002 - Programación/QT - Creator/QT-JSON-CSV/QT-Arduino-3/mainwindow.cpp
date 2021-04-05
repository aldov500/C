#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtNetwork>

QString cadenaJSON;
QString vectorData[100];
QString informacionComponentes[100]; //Guarda toda la linea
QString informacionX[100];
QString informacionY[100];
QString informacionS[100];
QString informacionH[100];
QString informacionJSON[100];
QString informacionNumComponentes[100];
int numeroComponentes = 0;
bool componentesDetectados = false;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);
    conectarArduino();
}

void MainWindow::recepcionSerialAsyncrona()
{
    if (arduino_esta_conectado && arduino->isReadable()) {
        //QByteArray datosLeidos = arduino->readAll();
        QByteArray datosLeidos = arduino->readLine();
        int indice0 = datosLeidos.indexOf("\n");
        int indice1 = datosLeidos.indexOf("@");
        QString infoExtraida = datosLeidos.mid(indice1 + 1, (indice0 - indice1));
        int datoEntero = infoExtraida.toInt();

        qDebug() << "Dato: " << datoEntero << endl;

        // ui->lcdNumber->display(datoEntero);
        if (indice0 >= 0 && indice1 >= 0) {
            qDebug() << "Datos extraidos: " << infoExtraida.toUtf8().constData();
            qDebug() << "Datos leidos: " << datosLeidos << endl;
            ui->progressBar->setValue(datoEntero);
            //graficar(datoEntero);
        }
    }
}

void MainWindow::conectarArduino()
{

    //Parte # 1, declaración inicial de las variables
    arduino_esta_conectado = false;
    arduino = new QSerialPort(this);
    connect(arduino, &QSerialPort::readyRead, this, &MainWindow::recepcionSerialAsyncrona);

    QString nombreDispositivoSerial = "";
    int nombreProductID = 0;

    //-2 buscar puertos con los identificadores de Arduino
    qDebug() << "Puertos disponibles: " << QSerialPortInfo::availablePorts().length();
    foreach (const QSerialPortInfo& serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Identificador del fabricante (VENDOR ID): " << serialPortInfo.hasVendorIdentifier();
        if (serialPortInfo.hasVendorIdentifier()) {
            qDebug() << "ID Vendedor " << serialPortInfo.vendorIdentifier();
            qDebug() << "ID Producto: " << serialPortInfo.productIdentifier();

            if (serialPortInfo.productIdentifier() == 66 || serialPortInfo.productIdentifier() == 67 || serialPortInfo.productIdentifier() == 29987) {
                arduino_esta_conectado = true;
                nombreDispositivoSerial = serialPortInfo.portName();
                nombreProductID = serialPortInfo.productIdentifier();
            }
        }
    }

    //3-Conexion
    if (arduino_esta_conectado) {

        arduino->setPortName(nombreDispositivoSerial);
        arduino->open(QIODevice::ReadWrite);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setBaudRate(QSerialPort::Baud115200);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        ui->label->clear();
        qDebug() << "Producto: " << nombreProductID;
        if (nombreProductID == 67)
            ui->label->setText("Arduino UNO R3 conectado");
        else if (nombreProductID == 66)
            ui->label->setText("Arduino Mega conectado");
        else if (nombreProductID == 29987)
            ui->label->setText("Arduino Nano conectado");
        else
            ui->label->setText("Error 3");

    } else {
        ui->label->clear();
        ui->label->setText("No hay arduino");
    }
}


void MainWindow::on_pushButton_clicked()
{
    QString t1x = ui->lineEdit->text();
    double t1xi = t1x.toDouble();
    QString t1x1 = QString::number(t1xi);

    QString t1y = ui->lineEdit_2->text();
    double t1yi = t1y.toDouble();
    QString t1y1 = QString::number(t1yi); //Validacion

    QString t2 = ui->comboBox->currentText();
    //int t2i = t2.toInt();

    QString t3 = ui->comboBox_2->currentText();
    //int t3i = t3.toInt();

    cadenaJSON = "{\"X\":\"" + t1x1 + "\",\"Y\":\"" + t1y1 + "\",\"Stack\":\"" + t3 + "\",\"Head\":\"" + t2 + "\"}";
    ui->label_6->setText(cadenaJSON);
}

void MainWindow::on_pushButton_3_clicked()
{
    QByteArray response_data = cadenaJSON.toUtf8().constData();
    QJsonDocument json = QJsonDocument::fromJson(response_data);
    QJsonObject sett2 = json.object();
    QJsonValue value = sett2.value(QString("X"));
    QString variable1Json = "X: " + value.toString();

    value = sett2.value(QString("Y"));
    QString variable2Json = "Y: " + value.toString();

    value = sett2.value(QString("Stack"));
    QString variable3Json = "Stack: " + value.toString();

    value = sett2.value(QString("Head"));
    QString variable4Json = "Head: " + value.toString();

    ui->label_8->setText(variable1Json);
    ui->label_9->setText(variable2Json);
    ui->label_10->setText(variable3Json);
    ui->label_11->setText(variable4Json);
}

void MainWindow::on_pushButton_2_clicked()
{
    if (arduino_esta_conectado && arduino->isWritable()) {
        arduino->write(cadenaJSON.toUtf8().constData());
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString nombreArchivo = QFileDialog::getOpenFileName(this, tr("Abrir Archivo"), "/home/", tr("Archivos (*.csv)"));
    QFile archivo(nombreArchivo.toUtf8().constData());

    if (!archivo.open(QFile::ReadOnly | QFile::Text)) {
        //No se pudo abrir el archivo
    } else {

        QTextStream in3(&archivo);
        int ii = 0;
        int jj = 0;

        do {
            vectorData[ii] = in3.readLine();
            int tamanioFila = vectorData[ii].length();

            int indice1 = vectorData[ii].indexOf(",", tamanioFila - 1);
            //qDebug() << ii+1 << " - " << tamanioFila << " " << indice1 ;
            if (indice1 < 0) {
                //Es una linea que nos interesa
                //Guardar las lineas

                //Extraer el numero de componente
                int posicionComma1 = vectorData[ii].indexOf(",");
                QString temporal = vectorData[ii].mid(0, posicionComma1);
                int temporal2 = temporal.toInt();

                //qDebug() << temporal2;
                if (temporal2 > 0) {
                    int posicionComma2 = vectorData[ii].indexOf(",", posicionComma1 + 1);

                    informacionNumComponentes[jj] = temporal;
                    temporal = vectorData[ii].mid(posicionComma1 + 1, (posicionComma2 - posicionComma1) - 1);
                    //qDebug() << posicionComma1 << "-" << posicionComma2 << "-" << temporal;
                    //
                    informacionComponentes[jj] = vectorData[ii];
                    informacionH[jj] = temporal;

                    //Encontrar Stack
                    int posicionComma3 = vectorData[ii].indexOf(",", posicionComma2 + 1);
                    temporal = vectorData[ii].mid(posicionComma2 + 1, (posicionComma3 - posicionComma2) - 1);
                    informacionS[jj] = temporal;

                    //Encontrar X
                    int posicionComma4 = vectorData[ii].indexOf(",", posicionComma3 + 1);
                    temporal = vectorData[ii].mid(posicionComma3 + 1, (posicionComma4 - posicionComma3) - 1);
                    informacionX[jj] = temporal;

                    //Encontrar Y
                    int posicionComma5 = vectorData[ii].indexOf(",", posicionComma4 + 1);
                    temporal = vectorData[ii].mid(posicionComma4 + 1, (posicionComma5 - posicionComma4) - 1);
                    informacionY[jj] = temporal;

                    jj++;
                }
            }

            ii++;
        }while (!in3.atEnd());

        numeroComponentes = jj;
        QStringList temp;
        for (int j = 0; j < numeroComponentes; j++) {
            temp.append(informacionNumComponentes[j]);
            qDebug() << informacionNumComponentes[j];
        }
        ui->comboBox_3->addItems(temp);
        componentesDetectados = true;
    }
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    if (componentesDetectados) {
        ui->label_8->setText("X: " + informacionX[index]);
        ui->label_9->setText("Y: " + informacionY[index]);
        ui->label_10->setText("Stack: " + informacionS[index]);
        ui->label_11->setText("Header: " + informacionH[index]);

        cadenaJSON = "{\"X\":\"" + informacionX[index] + "\",\"Y\":\"" + informacionY[index] + "\",\"Stack\":\"" + informacionS[index] + "\",\"Head\":\"" + informacionH[index] + "\"}";
        ui->label_6->setText(cadenaJSON);
    }
}

MainWindow::~MainWindow()
{
    arduino->close();
    delete ui;
}

