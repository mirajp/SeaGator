from __future__ import division
import numpy as np
import cv2
import os.path
import time
import sys
import pyautogui
import mapping
import matplotlib.pyplot as plt
from sklearn.tree import DecisionTreeRegressor
from sklearn.ensemble import ExtraTreesRegressor



img_cnt = 0

#leftRegressorX = DecisionTreeRegressor(max_depth=5)
#leftRegressorY = DecisionTreeRegressor(max_depth=5)

leftRegressorX = ExtraTreesRegressor(n_estimators=10)
leftRegressorY = ExtraTreesRegressor(n_estimators=10)


pyautogui.FAILSAFE = False


eyeXYFrames = []

# multiple cascades: https://github.com/Itseez/opencv/tree/master/data/haarcascades
#https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_frontalface_default.xml
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
#face_cascade = cv2.CascadeClassifier('trained_cascade.xml')
#cv2gpu.init_cpu_detector('haarcascade_eye_tree_eyeglasses.xml')
#https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_eye.xml
eye_cascade = cv2.CascadeClassifier('haarcascade_eye_tree_eyeglasses.xml')
#eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')
pupil_params = cv2.SimpleBlobDetector_Params()
glint_params = cv2.SimpleBlobDetector_Params()

cap = cv2.VideoCapture(0)

eye0x = 0
eye0y = 0
eye1x = 0
eye1y = 0
global emptypupils
emptypupils = [[0,0],[0,0]]

def getLeftPupil(oldPupils):
    global cap
    pupilXYs = []
    while 1:
        ret, imgCap = cap.read()
        img = imgCap.copy()
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        faces = face_cascade.detectMultiScale(gray, 1.3, 5)
        
        circles = None
        for (x,y,w,h) in faces:
            #Select region of interest by cropping image
            halfwidth = w/2
            facecenterX = x+halfwidth
            facecenterY = y+h/2

            #roi_gray = gray[y:y+h, x:x+w]
            roi_color = img[y:y+h, x:x+w]
            #savedFace = roi_color.copy()
            #gceye0 = img

            #eye_cascade.detectMultiScale() returns an array of detected eye rectangles
            #   -- rectangles are returned by 4 parameters: top-left x, top-left y, box width, box height
            #eyes = eye_cascade.detectMultiScale(roi_color, 1.1, 2, 0, (30,30), (70, 70))
            eyes = eye_cascade.detectMultiScale(roi_color, 1.1, 2, 0, (50,50), (65,65))

            if len(eyes) > 0:
                for i in range(0, len(eyes)):
                    (ex0, ey0, ew0, eh0) = eyes[i]
                    if ex0 + ew0 < halfwidth:# and ex0 + ew0/2 < halfwidth:
                        break
                if len(eyes) == 1 and ex0 + ew0 > halfwidth:# and ex0 + ew0/2 > halfwidth:
                    return oldPupils
                    break
                ceye0 = roi_color[ey0+eh0/8:ey0+eh0,ex0+2*ew0/5:ex0+ew0]

                gceye0 = cv2.cvtColor(ceye0, cv2.COLOR_BGR2GRAY)
                gceye0 = cv2.fastNlMeansDenoising(gceye0,None,10,7)
                cv2.bitwise_not(gceye0, gceye0)
                gceye0 = cv2.medianBlur(gceye0, 1)
                gceye0 = cv2.equalizeHist(gceye0)
                ret, gceye0 = cv2.threshold(gceye0,253,255,cv2.THRESH_BINARY)
                kernel = np.ones((1,1),np.uint8)
                gceye0 = cv2.erode(gceye0,kernel,iterations = 2)
                gceye0 = cv2.dilate(gceye0,kernel,iterations = 2)
                cv2.imshow('end', gceye0)


                dp = 2
                minDist = 5
                p1 = 100
                p2 = 4
                minrad = 1
                maxrad = minrad + 4
                circles0 = cv2.HoughCircles(gceye0,cv2.HOUGH_GRADIENT,dp,minDist,param1=p1,param2=p2,minRadius=minrad,maxRadius=maxrad)
                if circles0 is None:
                    cv2.imshow("anything",img)
                    return oldPupils
                if circles0 is not None:
                    for i in circles0[0,:]:
                        eye0x = x+ex0+i[0]+2*ew0/5
                        eye0y = y+ey0+i[1]+eh0/8
                        cv2.circle(ceye0,(i[0],i[1]),2,(0,255,255),1) # draw the outer circle
                        cv2.circle(ceye0,(i[0],i[1]),1,(0,255,255),1) # draw the center of the circle
                        oldPupils = [[eye0x, eye0y]]
                        pupilXYs.append([eye0x, eye0y])
                        cv2.imshow("anything",img)
                        print len(circles0)
                        return pupilXYs
        # COMES HERE IF NO EYE BOXES ARE DETECTED
        cv2.imshow("anything",img)
        k = cv2.waitKey(10)
        if k == ord('q'):
            cap.release()
            sys.exit(0)
        elif k == ord('z'):
            return pupilXYs

calibImg = cv2.imread('Calibration.jpg')
calibImgBkup = calibImg.copy()
cv2.namedWindow('Calibration', cv2.WINDOW_AUTOSIZE)
skipCalibration = 0
if skipCalibration != 1:
    cv2.imshow('Calibration', calibImg)
    while 1:
        k = cv2.waitKey(0)
        #Space key
        if k == 32:
            break
        elif k == ord('q'):
            cap.release()
            sys.exit(0)


    #calibCircles are the points to draw
    #calibCircles = [[10,10], [10,470], [10, 930], [640,10], [640,470], [640, 930], [1270,10], [1270,470], [1270, 930]]
    #calibPoints are the true x,y values for the mapping
    #calibPoints = [[10,65], [10,527], [10,990], [640,65], [640,527], [640,990], [1270,65], [1270,527], [1270,990]]

    #calibCircles are the points to draw
    #alibCircles = [[10,10], [10,470], [640,10], [640,470], [1270,10], [1270,470]]
    #calibPoints are the true x,y values for the mapping
    #calibPoints = [[10,65], [10,527], [640,65], [640,527], [1270,65], [1270,527]]
    #calibCircles are the points to draw
    calibCircles = [[10,10], [10,470], [315,10],[315,470],[640,10], [640,470], [945,10],[945,470],[1270,10], [1270,470]]
    #calibPoints are the true x,y values for the mapping
    calibPoints = [[10,65], [10,527], [315,65],[315,527], [640,65], [640,527], [945,65],[945,527], [1270,65], [1270,527]]

    #These hold the pupil x to actual x, and pupil y to actual y
    leftEyeXs = []
    leftEyeYs = []
    rightEyeXs = []
    rightEyeYs = []

    for i in range(0, len(calibCircles)):
        cv2.destroyAllWindows()
        calibImg = calibImgBkup.copy()
        cv2.circle(calibImg,(calibCircles[i][0],calibCircles[i][1]),5,(0,0,255),10)
        cv2.imshow('Calibration #' + str(i+1), calibImg)
        counter = 0
        record = 0
        while 1:
            if record:
                capturedXYpairs = getLeftPupil(emptypupils)
                if (len(capturedXYpairs) == 0 and counter >= 5):
                    print "Have enough frames for calibration " + str(i+1)
                    cv2.destroyAllWindows()
                    break
                while(len(capturedXYpairs) == 0):
                    capturedXYpairs = getLeftPupil(emptypupils)

                leftEyeXYs = capturedXYpairs[0]
                rightEyeXYs = capturedXYpairs[0]
                
                leftEyeXs.append([leftEyeXYs[0], calibPoints[i][0]])
                leftEyeYs.append([leftEyeXYs[1], calibPoints[i][1]])

                rightEyeXs.append([rightEyeXYs[0], calibPoints[i][0]])
                rightEyeYs.append([rightEyeXYs[1], calibPoints[i][1]])

                counter += 1
                print "Counter =", counter
            
            k = cv2.waitKey(10)
            if k == ord('a'):
                print "Starting to record"
                #Start recording frames
                record = 1
            elif k == ord('z'):
                if counter >= 5:
                    print "Have enough frames for calibration " + str(i+1)
                    cv2.destroyAllWindows()
                    break
            elif k == ord('q'):
                cap.release()
                sys.exit(0)


    cv2.destroyAllWindows()
    print "training"
    #leftRegressorX.fit([[x[0]] for x in leftEyeXs],[x[1] for x in leftEyeXs])
    #leftRegressorY.fit([[y[0]] for y in leftEyeYs],[y[1] for y in leftEyeYs])
    leftRegressorX.fit([[x[0]] for x in rightEyeXs],[x[1] for x in rightEyeXs])
    leftRegressorY.fit([[y[0]] for y in rightEyeYs],[y[1] for y in rightEyeYs])

    print "Done Training"
    # Once all the calibration points have experimental XYs for each eye, use the correlation to make a mapping function
    polyorder = 3
    leftEyeXpoly = mapping.mapping(leftEyeXs, polyorder)
    leftEyeYpoly = mapping.mapping(leftEyeYs, polyorder)
    rightEyeXpoly = mapping.mapping(rightEyeXs, polyorder)
    rightEyeYpoly = mapping.mapping(rightEyeYs, polyorder)

    #plot

    leftEyeXpoly = np.poly1d(leftEyeXpoly)

    #plt.plot([x[0] for x in leftEyeXs],[x[1] for x in leftEyeXs], '.',[x[0] for x in leftEyeXs],leftEyeXpoly)
    #plt.show()

    leftEyeYpoly = np.poly1d(leftEyeYpoly)
    rightEyeXpoly = np.poly1d(rightEyeXpoly)
    rightEyeYpoly = np.poly1d(rightEyeYpoly)


counter = 0

capturedLeftXYs = []
running_sumX = 0.0
running_sumY = 0.0

def getavgleft(lastgood):
    numSamples = 1
    sums = [[0,0]]
    for x in range(0, numSamples):
        pair = getLeftPupil(lastgood)
        sums[0][0] += pair[0][0]
        sums[0][1] += pair[0][1]
    sums[0][0] /= numSamples
    sums[0][1] /= numSamples
    return sums

oldx = 0
oldy = 0
newx = 0
newy = 0
xvec = []
lastgoodpupil = [[0,0],[0,0]]
while 1:
    #capturedXYpairs = getLeftPupil(lastgoodpupil)

    capturedXYpairs = getavgleft(lastgoodpupil)
    if len(capturedXYpairs) > 0:
        counter += 1
        print counter;
        capturedLeftXYs.append(capturedXYpairs[0])
        xvec.append(capturedXYpairs[0][0]);

    if skipCalibration != 1 and counter == 2:
        
        leftEyeSums = [sum(x) for x in zip(*capturedLeftXYs)]
        leftEyeXAvg = leftEyeSums[0] / counter
        leftEyeYAvg = leftEyeSums[1] / counter
        #leftEyeXHat = leftEyeXpoly(leftEyeXAvg)
        #leftEyeYHat = leftEyeYpoly(leftEyeYAvg)
        
        leftEyeXHat = leftRegressorX.predict(leftEyeXAvg)
        leftEyeYHat = leftRegressorY.predict(leftEyeYAvg)
        print capturedLeftXYs
        lastgoodpupil = capturedLeftXYs
        print "->", capturedLeftXYs[0], capturedLeftXYs[1], leftEyeXHat
        newx = int(leftEyeXHat)
        newy = int(leftEyeYHat)
        pyautogui.moveTo(newx, newy)
        counter = 0        
        capturedLeftXYs = []
        xvec = []
    k = cv2.waitKey(10)
    if k == ord('q'):
        break


cap.release()
cv2.destroyAllWindows()
sys.exit(0)
