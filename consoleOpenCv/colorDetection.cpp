// consoleOpenCv.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;

int hmin = 0, smin = 110, vmin = 153;
int hmax = 0, smax = 110, vmax = 153;

void main()
{
    int x_axis;//Declaring integer variables to store co-ordinate values//
    int y_axis;
    VideoCapture cap(1);
    Mat frame;
    Mat imgGray, imgHSV, mask;

    //CascadeClassifier face_cascade, eyes_cascade;//declaring a CascadeClassifier object//
    //face_cascade.load("C:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml");//loading the cascade classifier//
    //eyes_cascade.load("C:/opencv/sources/data/haarcascades/haarcascade_eye.xml");

    namedWindow("trackbars", (640, 200));
    createTrackbar("Hue Min", "trackbars", &hmin, 179);
    createTrackbar("Sat Min", "trackbars", &smin, 179);
    createTrackbar("Val Min", "trackbars", &vmin, 255);
    createTrackbar("Hue Max", "trackbars", &hmax, 255);
    createTrackbar("Sat Max", "trackbars", &smax, 255);
    createTrackbar("Val Max", "trackbars", &vmax, 255);

    while (true) {
        cap.read(frame);

        cvtColor(frame, imgHSV, COLOR_BGR2HSV);

        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lower, upper, mask);
       

        imshow("Video Live Capture", frame);
        imshow("Masked Color", mask);

        waitKey(1);
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
