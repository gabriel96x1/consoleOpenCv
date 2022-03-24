#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#define OPENCV_VERSION CVAUX_STR(CV_VERSION_MAJOR)"" CVAUX_STR(CV_VERSION_MINOR)"" CVAUX_STR(CV_VERSION_REVISION)
#if NDEBUG 
#pragma comment(lib, "opencv_world" OPENCV_VERSION ".lib")
#else
#pragma comment(lib, "opencv_world" OPENCV_VERSION "d.lib")
#endif

using namespace cv;
using namespace std;

int main()
{

    VideoCapture cap(1);
    Mat frame;
    Mat imgGray, imgHSV, mask;


    while (true) {
        cap.read(frame);
        CascadeClassifier faceCascade;
        faceCascade.load("C:/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml");
        //cvtColor(frame, imgHSV, COLOR_BGR2HSV);

        if (faceCascade.empty()) {
            cout << "file not loaded" << endl;
        }
        
        vector<Rect> faces;
        faceCascade.detectMultiScale(frame, faces, 1.1, 10);


        for (int i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
        }

        imshow("Video Live Capture", frame);

        waitKey(1);
    }

    return 0;
}