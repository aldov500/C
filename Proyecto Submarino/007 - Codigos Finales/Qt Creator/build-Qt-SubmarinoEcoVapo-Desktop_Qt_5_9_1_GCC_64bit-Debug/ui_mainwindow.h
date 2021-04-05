/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QScrollBar *SB_Aceleracion;
    QPushButton *BTN_Derecha;
    QPushButton *BTN_Atras;
    QPushButton *BTN_Izquierda;
    QPushButton *BTN_Adelante;
    QLabel *LBL_Image;
    QLabel *LBL_Respuesta;
    QLineEdit *EDT_ComandoTelnet;
    QPushButton *BTN_ConectarHotSPot;
    QCheckBox *CBX_ControlPID;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(742, 411);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SB_Aceleracion = new QScrollBar(centralWidget);
        SB_Aceleracion->setObjectName(QStringLiteral("SB_Aceleracion"));
        SB_Aceleracion->setGeometry(QRect(590, 110, 141, 251));
        SB_Aceleracion->setMinimum(0);
        SB_Aceleracion->setMaximum(100);
        SB_Aceleracion->setPageStep(10);
        SB_Aceleracion->setOrientation(Qt::Vertical);
        SB_Aceleracion->setInvertedAppearance(true);
        BTN_Derecha = new QPushButton(centralWidget);
        BTN_Derecha->setObjectName(QStringLiteral("BTN_Derecha"));
        BTN_Derecha->setGeometry(QRect(100, 210, 91, 51));
        BTN_Derecha->setCheckable(true);
        BTN_Atras = new QPushButton(centralWidget);
        BTN_Atras->setObjectName(QStringLiteral("BTN_Atras"));
        BTN_Atras->setGeometry(QRect(60, 260, 81, 61));
        BTN_Atras->setCheckable(true);
        BTN_Izquierda = new QPushButton(centralWidget);
        BTN_Izquierda->setObjectName(QStringLiteral("BTN_Izquierda"));
        BTN_Izquierda->setGeometry(QRect(10, 210, 91, 51));
        BTN_Izquierda->setCheckable(true);
        BTN_Adelante = new QPushButton(centralWidget);
        BTN_Adelante->setObjectName(QStringLiteral("BTN_Adelante"));
        BTN_Adelante->setGeometry(QRect(60, 150, 81, 61));
        BTN_Adelante->setCheckable(true);
        LBL_Image = new QLabel(centralWidget);
        LBL_Image->setObjectName(QStringLiteral("LBL_Image"));
        LBL_Image->setGeometry(QRect(210, 110, 361, 251));
        LBL_Image->setFrameShape(QFrame::Box);
        LBL_Image->setFrameShadow(QFrame::Sunken);
        LBL_Respuesta = new QLabel(centralWidget);
        LBL_Respuesta->setObjectName(QStringLiteral("LBL_Respuesta"));
        LBL_Respuesta->setGeometry(QRect(10, 50, 721, 41));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        LBL_Respuesta->setFont(font);
        LBL_Respuesta->setFrameShape(QFrame::Box);
        EDT_ComandoTelnet = new QLineEdit(centralWidget);
        EDT_ComandoTelnet->setObjectName(QStringLiteral("EDT_ComandoTelnet"));
        EDT_ComandoTelnet->setGeometry(QRect(90, 10, 641, 31));
        BTN_ConectarHotSPot = new QPushButton(centralWidget);
        BTN_ConectarHotSPot->setObjectName(QStringLiteral("BTN_ConectarHotSPot"));
        BTN_ConectarHotSPot->setGeometry(QRect(10, 10, 81, 31));
        CBX_ControlPID = new QCheckBox(centralWidget);
        CBX_ControlPID->setObjectName(QStringLiteral("CBX_ControlPID"));
        CBX_ControlPID->setGeometry(QRect(60, 110, 91, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 742, 18));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        BTN_Derecha->setText(QApplication::translate("MainWindow", "Derecha", Q_NULLPTR));
        BTN_Atras->setText(QApplication::translate("MainWindow", "Atras", Q_NULLPTR));
        BTN_Izquierda->setText(QApplication::translate("MainWindow", "Izquierda", Q_NULLPTR));
        BTN_Adelante->setText(QApplication::translate("MainWindow", "Adelante", Q_NULLPTR));
        LBL_Image->setText(QApplication::translate("MainWindow", "IMAGE", Q_NULLPTR));
        LBL_Respuesta->setText(QString());
        BTN_ConectarHotSPot->setText(QApplication::translate("MainWindow", "Conectar HotSpot", Q_NULLPTR));
        CBX_ControlPID->setText(QApplication::translate("MainWindow", "Equilibrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
