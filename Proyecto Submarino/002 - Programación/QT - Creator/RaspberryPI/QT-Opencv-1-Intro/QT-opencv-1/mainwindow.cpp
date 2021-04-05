#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/video/background_segm.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/imgcodecs.hpp>
#include"mat2qimage.h"

using namespace cv;
VideoCapture camara1(0);


void MainWindow::funcionActivacionTimer(){
    //Aqui se captura la imagen de camara IP cada 30ms
    if(camara1.isOpened()){   //Paso # 1
        Mat IMAGEN;
        Mat IMAGENpequena;
        camara1 >> IMAGEN;     //Paso # 2
        cv::resize(IMAGEN,IMAGENpequena,Size(800,450));  //Paso # 3

        //Las siguientes 4 instrucciones representan al Paso # 4
        QImage qImage = Mat2QImage(IMAGENpequena);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        ui->label->clear();
        ui->label->setPixmap(pixmap);


    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(30);


    if(!camara1.isOpened()) {
        camara1.open("http://192.168.100.2:8080/video");

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
