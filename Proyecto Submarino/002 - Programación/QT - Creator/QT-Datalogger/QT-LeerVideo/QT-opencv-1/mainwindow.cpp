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
#include<QFileDialog>

using namespace cv;
//VideoCapture camara1("http://192.168.100.2:8080/video");
VideoCapture camara1(1);
QString nombreVideo = "";
bool videoAbierto = false;
Mat IMAGEN, IMAGENpequena;

void MainWindow::funcionActivacionTimer(){
        //Las siguientes 4 instrucciones representan al Paso # 4

    if(videoAbierto){
        if(camara1.isOpened()){
            camara1 >> IMAGEN;
            if(!IMAGEN.empty()){
                cv::resize(IMAGEN,IMAGENpequena,Size(800,450),0,0,0);
                QImage qImage = Mat2QImage(IMAGENpequena);
                QPixmap pixmap = QPixmap::fromImage(qImage);
                ui->label->clear();
                ui->label->setPixmap(pixmap);
                int frameActual = camara1.get(CAP_PROP_POS_FRAMES);
                ui->horizontalSlider->setValue(frameActual);
                ui->lcdNumber->display(frameActual);
            }

            }
        }

    }




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(30);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    nombreVideo = QFileDialog::getOpenFileName(this, tr("Abrir video"), "/home/rem", tr("Imagenes (*.mp4)"));
       camara1.open(nombreVideo.toUtf8().constData());
       int temp = camara1.get(CAP_PROP_FRAME_COUNT);
       ui->horizontalSlider->setMaximum(temp);
       ui->label_3->setText(QString::number(temp));
}

void MainWindow::on_pushButton_2_clicked(bool checked)
{
    videoAbierto = checked;
    if(videoAbierto){
        ui->pushButton_2->setText("Pausar");
        camara1.set(CAP_PROP_POS_FRAMES,ui->horizontalSlider->value());

    }
    else{
        ui->pushButton_2->setText("Play");
    }
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    videoAbierto = false;
    ui->pushButton_2->setChecked(false);
    ui->pushButton_2->setText("Play");

    camara1.set(CAP_PROP_POS_FRAMES,position);
    camara1 >> IMAGEN;
    cv::resize(IMAGEN,IMAGENpequena,Size(800,450),0,0,0);


    QImage qImage = Mat2QImage(IMAGENpequena);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    ui->label->clear();
    ui->label->setPixmap(pixmap);

}
