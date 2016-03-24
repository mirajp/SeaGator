import cv2
import numpy as np

#img = cv2.imread("eye0.jpg", 0)
#img = cv2.imread("screencap7eye0.jpg", 0)
img = cv2.imread("screencap7eye1.jpg", 0)
img = cv2.medianBlur(img,3)
img = cv2.equalizeHist(img)
cv2.imshow("img", img)
cv2.waitKey(0)

#param1 - refers to the edge threshold that will be used by the Canny edge detector
#(applied to a grayscale image). cvCanny() accepts two thresholds and is internally
#invoked by cvHoughCircles(). Therefore the higher (first) threshold is set to param1
#(passed as argument into cvHoughCircles()) and the lower (second) threshold is set
#to half of this value.

#param2- Is the value for accumulator threshold. This value is used in the accumulator
#plane that must be reached so that a line is retrieved.
#The smaller it is, the more false circles may be detected.

#Too many circles found on screencap7eye1

#dp = Inverse ratio of the accumulator resolution to the image resolution.
#For example, if dp=1 , the accumulator has the same resolution as the input image.

#minDist = Minimum distance between the centers of the detected circles. If the parameter
#is too small, multiple neighbor circles may be falsely detected in addition to a true one.
#If it is too large, some circles may be missed.

#cv2.HoughCircles(image, method, dp, minDist[, circles[, param1[, param2[, minRadius[, maxRadius]]]]]) 

#Works on eye0
#circles = cv2.HoughCircles(img,cv2.HOUGH_GRADIENT,1,10,param1=50,param2=20,minRadius=0,maxRadius=20)
#Works on screencap7eye0
#circles = cv2.HoughCircles(img,cv2.HOUGH_GRADIENT,1,10,param1=50,param2=20,minRadius=0,maxRadius=20)
#For screencap7eye1, change minDist to 50 to reduce number of false detections, radius 25 seems to work better
circles = cv2.HoughCircles(img,cv2.HOUGH_GRADIENT,1,50,param1=50,param2=20,minRadius=7,maxRadius=25)
if circles is not None:
        
    print circles
    #circles = np.uint16(np.around(circles))
    for i in circles[0,:]:
           cv2.circle(img,(i[0],i[1]),i[2],(0,255,0),1) # draw the outer circle
           cv2.circle(img,(i[0],i[1]),2,(0,0,255),1) # draw the center of the circle


    cv2.imshow("preview", img)
    cv2.waitKey(0)
else:
    print "No circle"