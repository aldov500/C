#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mat2qimage.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/videoio.hpp>
#include <qdebug.h>

#include <QMainWindow>
#include <opencv2/objdetect.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

public slots:
    void fTimer();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
