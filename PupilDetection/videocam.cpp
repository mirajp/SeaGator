#include "opencv2/opencv.hpp"
#include <sys/time.h>

using namespace cv;

cv::Mat processImage(Mat src) {
    cv::Mat gray;
    cvtColor(src, gray, CV_BGR2GRAY);

    //equalizeHist(img_gray, img_gray);
    cv::SimpleBlobDetector::Params glint; 
    glint.minDistBetweenBlobs = 1;  // minimum 10 pixels between blobs
    glint.filterByArea = true;         // filter blobs by area of blob
    glint.minArea = 10;              // min 20 pixels squared
    glint.maxArea = 15;             // max 500 pixels squared
    glint.filterByColor = true;
    glint.blobColor = 255;

    glint.filterByConvexity = false;

    glint.filterByCircularity = false;
    glint.minCircularity = 0.01;

    glint.filterByInertia = true;
    glint.minInertiaRatio = 0.01;

    cv::SimpleBlobDetector::Params pupil;
    pupil.minDistBetweenBlobs = 1;  // minimum 10 pixels between blobs
    pupil.filterByArea = true;         // filter blobs by area of blob
    pupil.minArea = 100;              // min 20 pixels squared
    pupil.maxArea = 200.0;             // max 500 pixels squared
    pupil.filterByColor = true;
    pupil.blobColor = 0;

    pupil.filterByConvexity = false;

    pupil.filterByCircularity = true;
    pupil.minCircularity = 0.01;

    pupil.filterByInertia = true;
    pupil.minInertiaRatio = 0.01;


    //Ver 2
    //SimpleBlobDetector glintDetector(glint);
    //SimpleBlobDetector pupilDetector(pupil);

    //Ver 3
    Ptr<SimpleBlobDetector> glintDetector = SimpleBlobDetector::create(glint);
    Ptr<SimpleBlobDetector> pupilDetector = SimpleBlobDetector::create(pupil);
    
    std::vector<cv::KeyPoint> myGlints;
    std::vector<cv::KeyPoint> myPupils;
    //inRange(img, Scalar(158, 158, 158), Scalar(255, 255, 255), img);
    //Ver2
    //glintDetector.detect(gray, myGlints);
    //pupilDetector.detect(gray,myPupils);
    //Ver3
    glintDetector->detect(gray, myGlints);
    pupilDetector->detect(gray,myPupils);
    //imshow("opencvtest",img);
        
    //glintDetector.detect(img, myGlints);
    cv::Mat blobImg,blobImg2;    
    //cv::drawKeypoints(img_gray, myGlints, blobImg, 1);
    cv::drawKeypoints(src, myGlints, blobImg, Scalar(0, 0, 255), 4); // make the glints blue
    cv::drawKeypoints(blobImg,myPupils,blobImg2, Scalar(0, 255, 0), 4); // make the pupils green


    //imshow("Video", img);
        
   // if(waitKey(30) >= 0)
     //   break;

    return blobImg2;

}

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    //VideoCapture cap2(1); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    struct timeval t1, t2;
    int numFrames = 0;
    gettimeofday(&t1, NULL);
    Mat img_gray;
    for(;;)
    {
        numFrames++;
        Mat frame, frame2;
        cap >> frame; // get a new frame from camera
        //cap2 >> frame2;
        /*
        cvtColor(frame, img_gray, CV_BGR2GRAY);

        //equalizeHist(img_gray, img_gray);
        cv::SimpleBlobDetector::Params glint; 
        glint.minDistBetweenBlobs = 1;  // minimum 10 pixels between blobs
        glint.filterByArea = true;         // filter blobs by area of blob
        glint.minArea = 10;              // min 20 pixels squared
        glint.maxArea = 15;             // max 500 pixels squared
        glint.filterByColor = true;
        glint.blobColor = 255;

        glint.filterByConvexity = false;

        glint.filterByCircularity = false;
        glint.minCircularity = 0.01;

        glint.filterByInertia = true;
        glint.minInertiaRatio = 0.01;

        cv::SimpleBlobDetector::Params pupil;
        pupil.minDistBetweenBlobs = 1;  // minimum 10 pixels between blobs
        pupil.filterByArea = true;         // filter blobs by area of blob
        pupil.minArea = 100;              // min 20 pixels squared
        pupil.maxArea = 200.0;             // max 500 pixels squared
        pupil.filterByColor = true;
        pupil.blobColor = 0;

        pupil.filterByConvexity = false;

        pupil.filterByCircularity = true;
        pupil.minCircularity = 0.01;

        pupil.filterByInertia = true;
        pupil.minInertiaRatio = 0.01;

        SimpleBlobDetector glintDetector(glint);
        SimpleBlobDetector pupilDetector(pupil);
        std::vector<cv::KeyPoint> myGlints;
        std::vector<cv::KeyPoint> myPupils;
        //inRange(img, Scalar(158, 158, 158), Scalar(255, 255, 255), img);
        glintDetector.detect(img_gray, myGlints);
        pupilDetector.detect(img_gray,myPupils);
        //imshow("opencvtest",img);
        
        //glintDetector.detect(img, myGlints);
        cv::Mat blobImg,blobImg2;    
        //cv::drawKeypoints(img_gray, myGlints, blobImg, 1);
        cv::drawKeypoints(frame, myGlints, blobImg, Scalar(0, 0, 255), 4); // make the glints blue
        cv::drawKeypoints(blobImg,myPupils,blobImg2, Scalar(0, 255, 0), 4); // make the pupils green
        
        */
        cv::Mat blobImg2 = processImage(frame);
        //cv::Mat fresh2 = processImage(frame2);
        cv::imshow("Blobs", blobImg2);
        //cv::imshow("Fresh", fresh2);
        gettimeofday(&t2, NULL);
        int microSeconds = (t2.tv_usec - t1.tv_usec);
        int milliSeconds = (t2.tv_sec - t1.tv_sec)*1000;
        int timeDiff = microSeconds/1000 + milliSeconds;
        int fps = numFrames/(timeDiff/1000);
        //std::cout << "Time diff (ms) = " << milliSeconds << std::endl;
        std::cout << "FPS = " << fps << std::endl;
        //imshow("Video", img);
        
        if(waitKey(30) == 'e')
            break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
