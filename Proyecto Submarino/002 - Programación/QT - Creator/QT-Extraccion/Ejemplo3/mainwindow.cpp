#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mat2qimage.h"

#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/video/background_segm.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/imgcodecs.hpp>
#include<qdebug.h>
#include<QTimer>
#include <QMouseEvent>

cv::VideoCapture camara(1);
bool camaraIPHay =  false;

using namespace cv;
using namespace std;
//QString IP = "http://192.168.43.243:8080/video";
//cv::VideoCapture camara("http://192.168.43.243:8080/video");
//cv::VideoCapture camara(IP.toUtf8().constData());
//cv::VideoCapture camara;

Point p0;
Mat IMAGEN;
Mat IMAGEN2;
 Rect Rectangulo;
  Mat Invertida;
  Mat Fondo;
   int ventana = 50;
void MainWindow::mousePressEvent(QMouseEvent *event){
      int x;
      int y;
      int xlocal;
      int ylocal;

      if(event->MouseButtonPress){
          x = event->x();
          y = event->y();
          //ui->lcdNumber->display(x);
          //ui->lcdNumber_2->display(y);
          xlocal = x-30;
          ylocal = y-20;

          if(xlocal >= 0 && ylocal >=0 && xlocal <=179 && ylocal<=179){
              ui->lcdNumber->display(xlocal);
              ui->lcdNumber_2->display(ylocal);
              p0.x=xlocal;
              p0.y=ylocal;



          }

      }
}


void MainWindow::fTimer(){

    //Mat IMAGEN(300,400,CV_8UC3,Scalar(150,255,25));
    ventana = ui->verticalSlider->value();
    if(camaraIPHay){
    if(camara.isOpened()){
    camara >> IMAGEN;
    }
    }
    else{
        IMAGEN = cv::imread("../img4.jpg",1);
    }
    cv::resize(IMAGEN,IMAGEN2,Size(180,180),0,0,0);
    Mat IMAGEN22;
   //cv::GaussianBlur(IMAGEN2,IMAGEN22,Size(15,15),0,0,0);
    IMAGEN2.copyTo(IMAGEN22);

    Mat ycrcb;
    cvtColor(IMAGEN22,ycrcb,CV_BGR2HSV);
    vector<Mat> canales;
    split(ycrcb,canales);
    equalizeHist(canales[0],canales[0]);
    merge(canales,ycrcb);
    cvtColor(ycrcb,IMAGEN22,CV_HSV2BGR);

    Mat IMAGEN222;
    cv::cvtColor(IMAGEN22,IMAGEN222,CV_BGR2HSV);



    Vec3b intensity = IMAGEN22.at<Vec3b>(p0.y, p0.x);
    uchar blue = intensity.val[0];
    uchar green = intensity.val[1];
    uchar red = intensity.val[2];

    int bluei = blue;
    int greeni = green;
    int redi = red;

    ui->lcdNumber_3->display(bluei);
    ui->lcdNumber_4->display(greeni);
    ui->lcdNumber_5->display(redi);
    int blueMin = bluei - ventana;
    int blueMax = bluei + ventana;
    int greenMin = greeni - ventana;
    int greenMax = greeni + ventana;
    int redMin = redi-ventana;
    int redMax = redi+ventana;
    if(blueMin < 0) blueMin = 0;
    if(blueMax > 255) blueMax = 255;
    if(greenMin < 0) greenMin = 0;
    if(greenMax > 255) greenMax = 255;
    if(redMin < 0) redMin = 0;
    if(redMax > 255) redMax = 255;

     Mat IMAGEN2222;

     cv::inRange(IMAGEN22,Scalar(blueMin,greenMin,redMin),Scalar(blueMax, greenMax, redMax),IMAGEN2222);

     /*
      * Mat copiaInvertida;
     IMAGEN2222.copyTo(copiaInvertida);
     vector<vector<Point> > contornos;
     vector<Vec4i> jerarquia;
     findContours(copiaInvertida, contornos, jerarquia, RETR_LIST, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
     int areaMaxima = 0;
     int indiceAreaMax = 0;
     int areaMaxima2 = 0;
     int indiceAreaMax2 = 0;

     int area=0;
     for( int i = 0; i< (int)contornos.size(); i++ ){
          area = contourArea(contornos[i]);
          if(area >areaMaxima){
              areaMaxima2 = areaMaxima;
              indiceAreaMax2 = indiceAreaMax;

              areaMaxima = area;
              indiceAreaMax = i;
          }
          if(area>areaMaxima && area<areaMaxima2){
              areaMaxima2 = area;
              indiceAreaMax2 = i;
          }
     }
     Mat mascara = Mat::zeros( IMAGEN2222.size(), CV_8UC3 );
     drawContours( mascara, contornos, indiceAreaMax,Scalar(255,255,255), CV_FILLED );

      */


     cv::bitwise_not(IMAGEN2222,Invertida);
     QImage qImage = Mat2QImage(Invertida);
     QPixmap pixmap = QPixmap::fromImage(qImage);
     ui->label_11->clear();
     ui->label_11->setPixmap(pixmap);
      Mat fondo1 = cv::imread("../img5.jpg");
      cv::resize(fondo1,Fondo,Size(180,180),0,0,0);

      qImage = Mat2QImage(Fondo);
      pixmap = QPixmap::fromImage(qImage);
     ui->label_5->clear();
     ui->label_5->setPixmap(pixmap);


    Mat IMAGEN3;
    //IMAGEN3 = IMAGEN2;
    IMAGEN2.copyTo(IMAGEN3);

    Rect Rectangulo(p0.x, p0.y, 50, 50);

    //IMAGEN2.at()


    cv::rectangle(IMAGEN3,Rectangulo.tl(), Rectangulo.br(),Scalar(255,0,0),2,8,0);

    QImage qImage2 = Mat2QImage(IMAGEN3);
    QPixmap pixmap2 = QPixmap::fromImage(qImage2);
    ui->label->clear();
    ui->label->setPixmap(pixmap2);

    IMAGEN2.copyTo(Fondo,Invertida);
    QImage qImage3 = Mat2QImage(Fondo);
    QPixmap pixmap3 = QPixmap::fromImage(qImage3);
    ui->label_6->clear();
    ui->label_6->setPixmap(pixmap3);

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    p0.x = 1;
    p0.y = 1;

    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(fTimer()));
    cronometro->start(100);


    //if(!camara.isOpened()) camara("http://192.168.43.243:8080/video");

      if(!camara.isOpened()) { camara.open(1);


      }


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


}

void MainWindow::on_horizontalScrollBar_sliderMoved(int position)
{
    ventana = position;
}
