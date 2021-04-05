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
//VideoCapture camara1("http://192.168.100.2:8080/video");
VideoCapture camara1(1);
bool grabar = false;
bool pausar = false;
VideoWriter videoGrabado;
int segundos = 0;
int minutos = 0;
int horas = 0;
int contadorFrames = 0;

void MainWindow::funcionActivacionTimer(){
    //Aqui se captura la imagen de camara IP cada 30ms
    if(camara1.isOpened()){   //Paso # 1
        Mat IMAGEN;
        Mat IMAGENpequena;
        camara1 >> IMAGEN;     //Paso # 2
        cv::resize(IMAGEN,IMAGENpequena,Size(800,450));  //Paso # 3

        //Grabar el video
        if(grabar && !pausar){
            if(videoGrabado.isOpened()){
                //Guardar video
                videoGrabado << IMAGEN;
                contadorFrames++;
                ui->lcdNumber_4->display(contadorFrames);
            }
            else{
                //Abrir el archivo de video
                Size S = Size((int) camara1.get(CV_CAP_PROP_FRAME_WIDTH),
                              (int) camara1.get(CV_CAP_PROP_FRAME_HEIGHT));
                int ex = static_cast<int>(camara1.get(CV_CAP_PROP_FOURCC));

                videoGrabado.open("../video.mp4" , ex, camara1.get(CV_CAP_PROP_FPS),S, true);
            }
        }

        //Las siguientes 4 instrucciones representan al Paso # 4
        QImage qImage = Mat2QImage(IMAGENpequena);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        ui->label->clear();
        ui->label->setPixmap(pixmap);


    }
}

void MainWindow::ftimer2(){
    if(grabar){
        if(!pausar){
            //Cronometro
            segundos++;
            if(segundos>59){
                segundos = 0;
                minutos++;
                if(minutos>59){
                    minutos = 0;
                    horas++;
                    if(horas>23){
                        horas=0;
                    }
                }
            }
            ui->lcdNumber_3->display(segundos);
            ui->lcdNumber_2->display(minutos);
            ui->lcdNumber->display(horas);
        }
    }

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pixmap("../Imagenes/grabar-desactivo.png");
    QIcon ButtonIcon(pixmap);
    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(pixmap.rect().size());

    pixmap.load("../Imagenes/stop.png");
    ButtonIcon.addPixmap(pixmap);
    ui->pushButton_2->setIcon(ButtonIcon);
    ui->pushButton_2->setIconSize(pixmap.rect().size());

    pixmap.load("../Imagenes/pausa.png");
    ButtonIcon.addPixmap(pixmap);
    ui->pushButton_3->setIcon(ButtonIcon);
    ui->pushButton_3->setIconSize(pixmap.rect().size());


    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(100/3);

    QTimer *cronometro2 = new QTimer(this);
    connect(cronometro2,SIGNAL(timeout()),this,SLOT(ftimer2()));
    cronometro2->start(1000);

    if(!camara1.isOpened()) {
        camara1.open(1);

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    grabar = checked;
    if(checked){
        //Cambiar a imagen roja
        QPixmap pixmap("../Imagenes/grabar-activo.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton->setIcon(ButtonIcon);
        ui->pushButton->setIconSize(pixmap.rect().size());

    }
    else{
        //Cambiar a imagen gris
        QPixmap pixmap("../Imagenes/grabar-desactivo.png");
        QIcon ButtonIcon(pixmap);
        ui->pushButton->setIcon(ButtonIcon);
        ui->pushButton->setIconSize(pixmap.rect().size());

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    videoGrabado.release();
    segundos = 0;
    minutos = 0;
    horas = 0;
    ui->lcdNumber->display(0);
    ui->lcdNumber_2->display(0);
    ui->lcdNumber_3->display(0);

    grabar = false;
    //Botar el boton de grabar
    ui->pushButton->setChecked(false);

    //Cambiamos la imagen a la gris
    QPixmap pixmap("../Imagenes/grabar-desactivo.png");
    QIcon ButtonIcon(pixmap);
    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(pixmap.rect().size());

}

void MainWindow::on_pushButton_3_clicked(bool checked)
{
    pausar = checked;
}
