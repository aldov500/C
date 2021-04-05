#include "mainwindow.h"

/* Utilizacion de nombre de espacio CV */
using namespace cv;

/* Variables Globales */
VideoCapture camara(0);
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
QString face_cascade_name = "../haarcascade_frontalface_alt_tree.xml";
QString eyes_cascade_name = "../haarcascade_eye_tree_eyeglasses.xml";

/* Funcion principal */
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    /* Creación de Timer con una funcion iterativa cada 20 ms */
    QTimer* cronometro = new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(fTimer()));
    cronometro->start(1);

    /* Abre la camara o verifica que ya ha sido abierta */
    if (!camara.isOpened())
        camara.open(0);
    else
        qDebug() << "Cámara Activada.";

    /* Comprueba que archivos de clasificador de cascada sean correctamente cargados */
    if (!face_cascade.load(face_cascade_name.toUtf8().constData())) {
        qDebug() << "Error al cargar el detector de rostros";
    }
    if (!eyes_cascade.load(eyes_cascade_name.toUtf8().constData())) {
        qDebug() << "Error al cargar el detector de ojos";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fTimer()
{

    /* Creacion de matrices para images */
    Mat IMAGEN;
    Mat IMAGEN2;

    if (camara.isOpened()) {
        /* Camara guarda una imagen en la matriz y la ajusta al tamaño de la ventana */
        camara >> IMAGEN;
        cv::resize(IMAGEN, IMAGEN2, Size(800, 450), 0, 0, 0);

        /* Se crea un vector de ares de interés y una matriz para el marco aplicando filtro de grises*/
        std::vector<Rect> faces;
        Mat frame_gray;
        cv::cvtColor(IMAGEN2, frame_gray, COLOR_BGR2GRAY);
        /* Equalizador de histograma para obtener un mejor contraste y brillo al analizar la imagen*/
        cv::equalizeHist(frame_gray, frame_gray);
        face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
        /* Ciclo para recorrer en la imagen y dectectar rostros */
        /* Si es detectado un rostro, se circula en un elipse y se captura una fotografía que se guarda localmente*/
        for (size_t i = 0; i < faces.size(); i++) {
            Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
            ellipse(IMAGEN2, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 255, 255), 4, 8, 0);

            Mat faceROI = frame_gray(faces[i]);
            QString nombreImagen = "img" + QString::number(i) + ".jpg";
            cv::imwrite(nombreImagen.toUtf8().constData(), faceROI);

        }

        /* Muestra la imgen en una etiqueta */
        QImage qImage = Mat2QImage(IMAGEN2);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        ui->label->clear();
        ui->label->setPixmap(pixmap);
    }
}

