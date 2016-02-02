#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/features2d/features2d.hpp>
using namespace cv;

int main()
{
    //char img_str[] = "/home/cuee/justinpng.png";
    //char img_str[] = "/home/cuee/justinlarger.png";
    char img_str[] = "/home/cuee/noglassesUP_bigger.png";
    Mat img = imread(img_str,CV_LOAD_IMAGE_COLOR);
    //Mat img_gray,img_bw;
    //cvtColor( img, img_gray, CV_BGR2GRAY );
    //threshold( img_gray, img_bw, 90, 255,3);
    imshow("opencvtest",img);
    cv::SimpleBlobDetector::Params params; 
    //params.minDistBetweenBlobs = 10;  // minimum 10 pixels between blobs
    //params.filterByArea = true;         // filter blobs by area of blob
    //params.minArea = 20.0;              // min 20 pixels squared
    //params.maxArea = 500.0;             // max 500 pixels squared
    params.filterByColor = true;
    params.blobColor = 255;
    SimpleBlobDetector myBlobDetector(params);
    std::vector<cv::KeyPoint> myBlobs;
    inRange(img, Scalar(158, 158, 158), Scalar(255, 255, 255), img);
    myBlobDetector.detect(img, myBlobs);
    //imshow("opencvtest",img);
    
    myBlobDetector.detect(img, myBlobs);
    cv::Mat blobImg;    
    cv::drawKeypoints(img, myBlobs, blobImg);
    cv::imshow("Blobs", blobImg);
    waitKey(0);

    return 0;
}
