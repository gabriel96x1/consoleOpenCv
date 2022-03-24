#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;


void getContours(Mat imgDil, Mat img) {


    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);


    for (int i = 0; i < contours.size(); i++) {
        int area = contourArea(contours[i]);
        vector<vector<Point>> conPoly(contours.size());
        vector<Rect> boundRect(contours.size());

        if (area > 500) {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02*peri, true);
            drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
            
            boundRect[i] = boundingRect(conPoly[i]);

            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
        }
    }

}

void main()
{
    int x_axis;//Declaring integer variables to store co-ordinate values//
    int y_axis;
    VideoCapture cap(1);
    Mat frame;
    Mat imgGray, imgCanny, imgBlur, imgDil;


    while (true) {
        cap.read(frame);

        cvtColor(frame, imgGray, COLOR_BGR2GRAY);
        GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
        Canny(imgBlur, imgCanny, 25, 75);

        Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

        dilate(imgCanny, imgDil, kernel);

        getContours(imgDil, frame);


        imshow("Video Live Capture", frame);
        //imshow("Forms", imgDil);

        waitKey(1);
    }
}
