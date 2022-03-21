// consoleOpenCv.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

void main()
{
    VideoCapture cap(1);
    Mat img;
    Mat imgGray, imgHSV, mask;

    namedWindow("Trackbars", (600, 200));


    while (true) {
        cap.read(img);
        createTrackbar("min", "tracbars", 0, 179);

        cvtColor(img, imgHSV, COLOR_BGR2HSV);

        Scalar lower(0,110,153);
        Scalar upper(19, 240, 255);

        inRange(imgHSV, lower, upper, mask);

        imshow("Video Live Capture", mask);
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
