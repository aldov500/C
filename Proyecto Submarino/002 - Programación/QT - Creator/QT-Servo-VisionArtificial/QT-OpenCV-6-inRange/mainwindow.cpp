#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/video/background_segm.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/imgcodecs.hpp>
#include "mat2qimage.h"   //Nota2
#include <QFileDialog>
#include <QTimer>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

using namespace cv;
using namespace std;

RNG rng(12345);

Mat IMAGEN;
Mat IMAGENchica;
Mat ImagenHSV;
Mat ImagenDesenfoque;
Mat ImagenFiltrada;
int umbral = 1000;
bool primeraVez = true;
int contadorObjetos = 0;

VideoCapture camaraLocal(1);

void MainWindow::buscaYconectaArduino(){

    //Parte # 1, declaración inicial de las variables
    arduino_esta_conectado = false;
    arduino = new QSerialPort(this);
    //connect(arduino, &QSerialPort::readyRead, this, &MainWindow::recepcionSerialAsyncrona);

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
         ui->label_2->clear();
        qDebug() << "Producto: " << nombreProductID;
        if(nombreProductID == 67) ui->label_2->setText("Arduino UNO R3 conectado");
        else if(nombreProductID == 66) ui->label_2->setText("Arduino Mega conectado");
        else ui->label_2->setText("Error 3");

    }
    else{
        ui->label_2->clear();
        ui->label_2->setText("No hay arduino");
    }
}

void MainWindow::ftimer(){
    Point2f centro;
    Point2f centro2;
    if(ui->checkBox->isChecked()){

        if(camaraLocal.isOpened()){
            camaraLocal >> IMAGEN;
        }
        else{
            Mat errorMatriz(400,400,CV_8UC3,Scalar(255,255,255));
            IMAGEN = errorMatriz;
            camaraLocal.open(1);
        }


        //Paso # 1 - Adaptar la imagen a la etiqueta

        cv::resize(IMAGEN,IMAGENchica,Size(150,150));

        //Paso # 2 - Procesar la imagen chica para obtener un desenfoque

        GaussianBlur(IMAGENchica, ImagenDesenfoque, Size(3,3),0,0,0);

        //Paso # 3 - Procesar la imagen anterior para obtener HSV

        //cvtColor(ImagenDesenfoque,ImagenHSV,CV_BGR2HSV);
        cvtColor(ImagenDesenfoque,ImagenHSV,CV_BGR2HSV);



        //Paso # 4 - Mostrar las imagenes en sus respectivas etiquetas

        QImage qImage = Mat2QImage(IMAGENchica);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        ui->labelColor->clear();
        ui->labelColor->setPixmap(pixmap);

        qImage = Mat2QImage(ImagenDesenfoque);
        pixmap = QPixmap::fromImage(qImage);
        ui->labelGauss->clear();
        ui->labelGauss->setPixmap(pixmap);

        qImage = Mat2QImage(ImagenHSV);
        pixmap = QPixmap::fromImage(qImage);
        ui->labelHSV->clear();
        ui->labelHSV->setPixmap(pixmap);
    }



    //Paso # 1 - Procesar imagen anterior para filtro de ventana



    if(!ImagenHSV.empty()){
    int canal0Min = ui->barraCanal0Min->value();
    int canal0Max = ui->barraCanal0Max->value();
    int canal1Min = ui->barraCanal1Min->value();
    int canal1Max = ui->barraCanal1Max->value();
    int canal2Min = ui->barraCanal2Min->value();
    int canal2Max = ui->barraCanal2Max->value();





    inRange(ImagenHSV,Scalar(canal0Min,canal1Min,canal2Min),Scalar(canal0Max,canal1Max,canal2Max),ImagenFiltrada);

    vector<vector<Point>> contornos;
    vector<Vec4i> jerarquia;
    Mat copiaImagenFiltrada;
    copiaImagenFiltrada = ImagenFiltrada;
    //findContours(copiaImagenFiltrada, contornos, jerarquia, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    findContours(copiaImagenFiltrada, contornos, jerarquia, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    Mat drawing = Mat::zeros( copiaImagenFiltrada.size(), CV_8UC3 );
    int area = 0;
    int areaMax1 = 0;
    int areaMax2 = 0;
    int indiceI = -1;
    int indiceJ = -1;
    for( int i = 0; i< (int)contornos.size(); i++ ){
    //for( int i = 0; i< (int)contornos.size(); i++ ){

    Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    drawContours( drawing, contornos, i, color, 2, 8, jerarquia, 0, Point() );
    area = contourArea(contornos[i]);
    qDebug() << i << " - "<< area;
    if(area >areaMax1){
        areaMax2 = areaMax1;
        indiceJ = indiceI;

        areaMax1 = area;
        indiceI = i;
    }
    if(area>areaMax1 && area<areaMax2){
        areaMax2 = area;
        indiceJ = i;
    }




    if(area > umbral){
        qDebug() << "Jitomate verde detectado!!!!";
        qDebug() << "Area " << i << " : " << area;
    }
    else{
         //qDebug() << "No hay nada";
    }
    }

    //Si se encontro un contorno, encuentra el origen o el centro
    if(indiceI>=0 && indiceJ>=0){
        //Declarar clase Moments.
        Moments momento0;
        Moments momento1;
        //Encontrar el momento del contorno indiceJ.
        momento0 = moments(contornos[indiceI]);
        momento1 = moments(contornos[indiceJ]);

        //Calcular el centro del momento
        centro = Point2f( static_cast<float>(momento0.m10/momento0.m00) , static_cast<float>(momento0.m01/momento0.m00) );
        centro2 = Point2f( static_cast<float>(momento1.m10/momento1.m00) , static_cast<float>(momento1.m01/momento1.m00) );

        circle(drawing,centro,10,Scalar(255,255,255),2,8,0);
        circle(drawing,centro2,8,Scalar(255,255,255),2,8,0);
        line(drawing,centro,centro2,Scalar(255,255,255),2,8,0);

        double XX = centro2.x - centro.x;
        double YY = centro2.y - centro.y;
        //double HH = sqrt(XX^2+YY^2);
        double angulo = (atan(YY/XX))*180/3.1415;
        if(ui->checkBox_2->isChecked()){
            if(angulo>=0 && angulo<=90){
                int anguloArduino = (int)angulo;
                QString paqueteSerial = "@"+QString::number(anguloArduino)+"\n";
                if(arduino_esta_conectado && arduino->isWritable()){
                    arduino->write(paqueteSerial.toUtf8().constData());
                }
            }
        }

        ui->lcdNumber_2->display(angulo);

    }

    if(ui->checkBox_2->isChecked()){

        if(centro.y > 70){
            //Contar
            if(primeraVez == true){
                contadorObjetos++;
                ui->lcdNumber->display(contadorObjetos);
                primeraVez = false;
                ui->label->setText("PrimeraVez false");
            }

        }
        else{
            primeraVez = true;
             ui->label->setText("PrimeraVez true");
        }


    }















    /*
    if(ui->checkBox_2->isChecked()){
        if(centro.y < 70){
            primeraVez = true;
            ui->label->setText("PrimeraVez true");
        }
        else{
            if(primeraVez){
                contadorObjetos++;
                ui->lcdNumber->display(contadorObjetos);
                primeraVez = false;
                ui->label->setText("PrimeraVez false");

            }
        }
    }
*/
    line(drawing,Point(0,70),Point(149,70),Scalar(255,255,255),2,8,0);

    QImage qImage = Mat2QImage(ImagenFiltrada);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    ui->labelInrange_2->clear();
    ui->labelInrange_2->setPixmap(pixmap);

      qImage = Mat2QImage(drawing);
      pixmap = QPixmap::fromImage(qImage);
      ui->labelContornos->clear();
      ui->labelContornos->setPixmap(pixmap);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buscaYconectaArduino();
    QTimer *cronometro = new QTimer(this);
    connect(cronometro,SIGNAL(timeout()),this,SLOT(ftimer()));
    cronometro->start(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(!ui->checkBox->isChecked()){

        QString nombreImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), "/home/", tr("Imagenes (*.png *.jpg *.bmp)"));
        IMAGEN = imread(nombreImagen.toUtf8().constData());

        //Paso # 1 - Adaptar la imagen a la etiqueta

        cv::resize(IMAGEN,IMAGENchica,Size(150,150));

        //Paso # 2 - Procesar la imagen chica para obtener un desenfoque

        GaussianBlur(IMAGENchica, ImagenDesenfoque, Size(3,3),0,0,0);

        //Paso # 3 - Procesar la imagen anterior para obtener HSV

        //cvtColor(ImagenDesenfoque,ImagenHSV,CV_BGR2HSV);
        cvtColor(ImagenDesenfoque,ImagenHSV,CV_BGR2HSV);



        //Paso # 4 - Mostrar las imagenes en sus respectivas etiquetas

        QImage qImage = Mat2QImage(IMAGENchica);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        ui->labelColor->clear();
        ui->labelColor->setPixmap(pixmap);

        qImage = Mat2QImage(ImagenDesenfoque);
        pixmap = QPixmap::fromImage(qImage);
        ui->labelGauss->clear();
        ui->labelGauss->setPixmap(pixmap);

        qImage = Mat2QImage(ImagenHSV);
        pixmap = QPixmap::fromImage(qImage);
        ui->labelHSV->clear();
        ui->labelHSV->setPixmap(pixmap);




    }



}



void MainWindow::on_barraCanal0Min_sliderMoved(int position)
{
    ui->lcdCanal0Min->display(position);
}

void MainWindow::on_barraCanal0Max_sliderMoved(int position)
{
    ui->lcdCanal0Max->display(position);
}

void MainWindow::on_barraCanal1Min_sliderMoved(int position)
{
    ui->lcdCanal1Min->display(position);
}

void MainWindow::on_barraCanal1Max_sliderMoved(int position)
{
    ui->lcdCanal1Max->display(position);
}

void MainWindow::on_barraCanal2Min_sliderMoved(int position)
{
    ui->lcdCanal2Min->display(position);
}

void MainWindow::on_barraCanal2Max_sliderMoved(int position)
{
    ui->lcdCanal2Max->display(position);
}
