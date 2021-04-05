#define CAM_STRING "http://192.168.1.101:8080/video"
#define LOOP_FRECMS 30

#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;

/*::::::::::::::::::::::::::::VARIABLES GLOBALES::::::::::::::::::::::::::::*/
QProcess qpTelnet;
QProcess qpWifiConexion;

QString sLectura;
QString sDir_adelante    = "{\"SERVO_01\":\"90\",\"SERVO_02\":\"90\",\"SERVO_03\":\"90\"}\n";
QString sDir_atras       = "{\"SERVO_01\":\"90\",\"SERVO_02\":\"90\",\"SERVO_03\":\"90\"}\n";
QString sDir_vuelta_Izq  = "{\"SERVO_01\":\"180\",\"SERVO_02\":\"90\",\"SERVO_03\":\"180\"}\n";
QString sDir_vuelta_Der  = "{\"SERVO_01\":\"90\",\"SERVO_02\":\"0\",\"SERVO_03\":\"0\"}\n";
QString sDir_neutro      = "{\"SERVO_01\":\"90\",\"SERVO_02\":\"90\",\"SERVO_03\":\"90\"}\n";
QString sAce_Brushless;
QString sPid_ControlOn   = "{\"PID\":\"ENCENDIDO\"}\n";
QString sPid_ControlOff  = "{\"PID\":\"APAGADO\"}\n";


VideoCapture vcCamara(CAM_STRING);

/*:::::::::::::::::::::::::::::PROTOTIPOS DE FUNCIONES ::::::::::::::::::::::::::::*/
QString EscribirTelnet(QString Mensaje);
QString LeerTelnet();
QString TelnetConexion();


/*:::::::::::::::::::::::::::: FUNCIONES QT-CREATOR ::::::::::::::::::::::::::::*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer* loop = new QTimer(this);

    ui->LBL_Respuesta->setText(TelnetConexion());

    if(!vcCamara.isOpened()) {
        vcCamara.open(CAM_STRING);
    }

    connect(loop, SIGNAL(timeout()), this, SLOT(funcionLoop()));
    loop->start(LOOP_FRECMS);

}

void MainWindow::funcionLoop(){
    sLectura = LeerTelnet();

    if(!sLectura.isEmpty()){
        ui->LBL_Respuesta->setText(sLectura);
    }

    if(vcCamara.isOpened()){
        Mat IMAGEN;
        Mat IMAGENpequena;
        QImage qImage;
        QPixmap pixmap;

        vcCamara >> IMAGEN;
        cv::resize(IMAGEN,IMAGENpequena,Size(640,480));

        qImage = Mat2QImage(IMAGENpequena);
        pixmap = QPixmap::fromImage(qImage);

        ui->LBL_Image->clear();
        ui->LBL_Image->setPixmap(pixmap);
    }
}

/*:::::::::::::::::::::::::::: FUNCIONES TELNET ::::::::::::::::::::::::::::*/
QString TelnetConexion(){
    qpTelnet.start("telnet 192.168.1.1 23");
    qpTelnet.waitForFinished(10);
    return qpTelnet.readAllStandardOutput();
}

QString EscribirTelnet(QString Mensaje){
    qpTelnet.write(Mensaje.toUtf8().constData());
    qpTelnet.waitForFinished(1);

    QString stdout = qpTelnet.readAllStandardOutput();
    QString stderr = qpTelnet.readAllStandardError();
    qDebug() << stdout;
    return stdout;
}

QString LeerTelnet(){
    QString stdout = qpTelnet.readAllStandardOutput();
    QString stderr = qpTelnet.readAllStandardError();

    if(!stdout.isEmpty()){
        qDebug() << stdout;
        return stdout;
    }
    return "";
}

void MainWindow::on_SB_Aceleracion_sliderMoved(int position)
{
    sAce_Brushless = "{\"BRUSH\":\"START\",\"BRUSH_VALUE\":\"";
    sAce_Brushless.append(QString::number(position));
    sAce_Brushless.append("\"}\n");

    qDebug() << sAce_Brushless;
    EscribirTelnet(sAce_Brushless);
}


/*:::::::::::::::::::::::::::: FUNCIONES CONTROLES ::::::::::::::::::::::::::::*/
void MainWindow::on_BTN_Adelante_clicked(bool checked)
{
    if(checked == true){
        EscribirTelnet(sDir_adelante);
        qDebug() << sDir_adelante;
    } else {
        EscribirTelnet(sDir_neutro);
        qDebug() << sDir_neutro;
    }
}

void MainWindow::on_BTN_Atras_clicked(bool checked)
{
    if(checked == true){
        EscribirTelnet(sDir_atras);
        qDebug() << sDir_atras;
    } else {
        EscribirTelnet(sDir_neutro);
        qDebug() << sDir_neutro;
    }
}

void MainWindow::on_BTN_Izquierda_clicked(bool checked)
{
    if(checked == true){
        EscribirTelnet(sDir_vuelta_Izq);
        qDebug() << sDir_vuelta_Izq;
    } else {
        EscribirTelnet(sDir_neutro);
        qDebug() << sDir_neutro;
    }
}

void MainWindow::on_BTN_Derecha_clicked(bool checked)
{
    if(checked == true){
        EscribirTelnet(sDir_vuelta_Der);
        qDebug() << sDir_vuelta_Der;
    } else {
        EscribirTelnet(sDir_neutro);
        qDebug() << sDir_neutro;
    }
}

void MainWindow::on_CBX_ControlPID_toggled(bool checked)
{
    if(checked == true){
       EscribirTelnet(sPid_ControlOn);
       qDebug() << sPid_ControlOn;
    }else{
       EscribirTelnet(sPid_ControlOff);
       qDebug() << sPid_ControlOff;
    }
}

void MainWindow::on_BTN_ConectarHotSPot_clicked()
{
    qpWifiConexion.start("nmcli c up ECOVAPO");

    qpWifiConexion.waitForFinished(-1);

    ui->LBL_Respuesta->setText(qpWifiConexion.readAllStandardOutput());
}

MainWindow::~MainWindow(){delete ui;}

