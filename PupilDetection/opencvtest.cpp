#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <iostream>
#include <cstdio>

using namespace cv;

int main()
{
    //char img_str[] = "/home/cuee/justinpng.png";
    //char img_str[] = "/home/cuee/justinlarger.png";
    char img_str[] = "/home/cuee/noglassesUP.png";
    Mat img = imread(img_str,CV_LOAD_IMAGE_COLOR);
    Mat img_gray,img_bw;
    cvtColor( img, img_gray, CV_BGR2GRAY );
    threshold( img_gray, img_bw, 90, 255,3);
    imshow("opencvtest",img);
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
   // for(int i = 0; i < myBlobs.size(); i++) {
     //   std::cout << "Glint "<< myBlobs[i].pt << "\n";
      //  std::cout << "Pupil "<< myBlobs2[i].pt << "\n";
    //}
    //cv::imshow("Blobs2",blobImg2);
    waitKey(0);

    return 0;
}
