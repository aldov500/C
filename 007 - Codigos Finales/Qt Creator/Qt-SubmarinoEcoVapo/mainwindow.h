#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QProcess>
#include <QTcpSocket>
#include <QTimer>
#include <stdlib.h>

#include <QMainWindow>
#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/video/background_segm.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/imgcodecs.hpp>
#include"mat2qimage.h"

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
    void funcionLoop();

private slots:
    void on_BTN_Adelante_clicked(bool checked);

    void on_BTN_Atras_clicked(bool checked);

    void on_BTN_Izquierda_clicked(bool checked);

    void on_BTN_Derecha_clicked(bool checked);


    void on_BTN_ConectarHotSPot_clicked();

    void on_SB_Aceleracion_sliderMoved(int position);

    void on_CBX_ControlPID_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
