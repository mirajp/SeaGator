#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat img_gray;
    namedWindow("Video",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, img_gray, CV_BGR2GRAY);
        
        cv::SimpleBlobDetector::Params glint; 
        glint.minDistBetweenBlobs = 1;  // minimum 10 pixels between blobs
        glint.filterByArea = true;         // filter blobs by area of blob
        glint.minArea = 0.1;              // min 20 pixels squared
        glint.maxArea = 20.0;             // max 500 pixels squared
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
        pupil.minArea = 10;              // min 20 pixels squared
        pupil.maxArea = 1000.0;             // max 500 pixels squared
        pupil.filterByColor = true;
        pupil.blobColor = 0;

        pupil.filterByConvexity = false;

        pupil.filterByCircularity = true;
        pupil.minCircularity = 0.01;

        pupil.filterByInertia = true;
        pupil.minInertiaRatio = 0.01;

        SimpleBlobDetector myBlobDetector(glint);
        SimpleBlobDetector myBlobDetector2(pupil);
        std::vector<cv::KeyPoint> myBlobs;
        std::vector<cv::KeyPoint> myBlobs2;
        //inRange(img, Scalar(158, 158, 158), Scalar(255, 255, 255), img);
        myBlobDetector.detect(img_gray, myBlobs);
        myBlobDetector2.detect(img_gray,myBlobs2);
        //imshow("opencvtest",img);
        
        //myBlobDetector.detect(img, myBlobs);
        cv::Mat blobImg,blobImg2;    
        cv::drawKeypoints(img_gray, myBlobs, blobImg, 1);
        cv::drawKeypoints(blobImg,myBlobs2,blobImg2,1);
        cv::imshow("Blobs", blobImg2);
        


        //imshow("Video", img);
        
        if(waitKey(30) >= 0)
            break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
