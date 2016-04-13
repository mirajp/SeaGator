import numpy as np
import cv2
import os.path
import time
import pyautogui

pyautogui.FAILSAFE = False

#Localized face detection, store upper left x,y with w,h
local_face = {'x':0, 'y':0, 'w':0, 'h':0}
numEyesFound = 0
local_eyes = [{'x':0, 'y':0, 'w':0, 'h':0},{'x':0, 'y':0, 'w':0, 'h':0}]

eyeXYFrames = []
leftEyeFrames = []

cascade_file_gpu = 'haarcascade_frontalface_default_cuda.xml'
#cv2gpu.init_gpu_detector(cascade_file_gpu)

imageCount = 0
eyePairCount = 0

def expandFaceWindow(stretch):
    localx = local_face['x']-stretch
    localy = local_face['y']-stretch
    if localx < 0:
        localx = 0
    if localy < 0:
        localy = 0

    local_face['x'] = localx
    local_face['y'] = localy
    local_face['w'] = local_face['w']+stretch*2
    local_face['h'] = local_face['h']+stretch*2
    return

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

# Change thresholds
#pupil_params.minThreshold = 0;
#pupil_params.maxThreshold = 20;
 
# Filter by Area.
pupil_params.filterByArea = True
pupil_params.minArea = 20
pupil_params.maxArea = 800

# Filter by Circularity
pupil_params.filterByCircularity = False
#pupil_params.minCircularity = 0.45
#pupil_params.maxCircularity = 0.6
 
# Filter by Convexity
pupil_params.filterByConvexity = True
pupil_params.minConvexity = 0.5
pupil_params.maxConvexity = 1
 
# Filter by Inertia
pupil_params.filterByInertia = True
pupil_params.minInertiaRatio = 0.05
pupil_params.maxInertiaRatio = 0.3

#blob Color
#pupil_params.blobColor = 0

pupil_detector = cv2.SimpleBlobDetector_create(pupil_params)

cap = cv2.VideoCapture(0)
#cap2  = cv2.VideoCapture(1)
iter = 0
while 1:
    #print "Frame #", imageCount
    ret, imgCap = cap.read()
    #If face was found in previous frame, crop image immediately
    """
    if local_face['w']:
        img = imgCap[local_face['y']:local_face['y']+local_face['h'], local_face['x']:local_face['x']+local_face['w']]
    else:
        img = imgCap
    """
    img = imgCap.copy()
    #Denoising both the color and then the grayscale image looks nice, but time expensive
    #img = cv2.fastNlMeansDenoisingColored(img,None,10,10,7,21)
    #ret2,img2 = cap2.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    #gray = cv2.fastNlMeansDenoising(gray,None,10,7)
    #gray2 = cv2.cvtColor(img2,cv2.COLOR_BGR2GRAY)

    #faces = face_cascade.detectMultiScale(gray, 1.3, 3)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)
    
    #faces = face_cascade.detectMultiScale(img, 1.3, 5)
    #faces = cv2gpu.find_faces('gray.png')
    #faces2 = cv2gpu.find_faces('gray2.png')
    #faces2 = face_cascade.detectMultiScale(img2,1.3, 5)
    #print "Cam1", faces
    #print "Cam2", faces2
    
    circles = None
    #for (x,y,w,h),(x2,y2,w2,h2) in zip(faces,faces2):
    for (x,y,w,h) in faces:
        #print "face: Center:", (x+(w/2), y+(h/2))
        #print local_face
        
        #Blue rectangle for face
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),1)

        #Draw red circle on approximate location of eye
        #right eye
        #cv2.circle(img, (x + int(0.3*w), y), 10, (0, 0, 255), 2)
        #left eye
        #cv2.circle(img, (x + int(0.7*w), y + int(0.4*h)), 10, (0, 0, 255), 2)

        #Select region of interest by cropping image
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]
        savedFace = roi_color.copy()

        
        #zoomed_face = cv2.resize(roi_gray,None,fx=2, fy=2, interpolation = cv2.INTER_CUBIC)
        #roi_gray = cv2.resize(roi_gray,None,fx=2, fy=2, interpolation = cv2.INTER_CUBIC)
        #roi_color = cv2.resize(roi_color,None,fx=2, fy=2, interpolation = cv2.INTER_CUBIC)

        #cv2.imshow('face', zoomed_face)
        #cv2.imshow('face', roi_color)
        
        #eyes = eye_cascade.detectMultiScale(roi_gray)
        eyes = eye_cascade.detectMultiScale(roi_color)
        if len(eyes) == 2:
            (ex0, ey0, ew0, eh0) = eyes[0]
            (ex1, ey1, ew1, eh1) = eyes[1]
            
            eyeBoxArea0 = ew0*eh0
            eyeBoxArea1 = ew1*eh1
            
            eye_color = (0,255,0)
            large_eye_color = (0,0,255)

            if (abs(eyeBoxArea0-eyeBoxArea1)>1700):
                if (eyeBoxArea0 > eyeBoxArea1):
                    cv2.rectangle(roi_color,(ex0,ey0),(ex0+ew0,ey0+eh0),large_eye_color,1)
                    cv2.rectangle(roi_color,(ex1,ey1),(ex1+ew1,ey1+eh1),eye_color,1)
                else:
                    cv2.rectangle(roi_color,(ex0,ey0),(ex0+ew0,ey0+eh0),eye_color,1)
                    cv2.rectangle(roi_color,(ex1,ey1),(ex1+ew1,ey1+eh1),large_eye_color,1)
            else:
                cv2.rectangle(roi_color,(ex0,ey0),(ex0+ew0,ey0+eh0),eye_color,1)
                cv2.rectangle(roi_color,(ex1,ey1),(ex1+ew1,ey1+eh1),eye_color,1)

            #eye0 = roi_color[ey0:ey0+eh0,ex0:ex0+ew0]
            #eye1 = roi_color[ey1:ey1+eh1,ex1:ex1+ew1]
            ceye0 = roi_color[ey0:ey0+eh0,ex0:ex0+ew0]
            eye0 = roi_gray[ey0:ey0+eh0,ex0:ex0+ew0]
            cv2.bitwise_not(eye0, eye0)
            eye0 = cv2.medianBlur(eye0, 3)
            eye0 = cv2.equalizeHist(eye0)

            ceye1 = roi_color[ey1:ey1+eh1,ex1:ex1+ew1]
            eye1 = roi_gray[ey1:ey1+eh1,ex1:ex1+ew1]
            cv2.bitwise_not(eye1, eye1)
            eye1 = cv2.medianBlur(eye1, 3)
            eye1 = cv2.equalizeHist(eye1)

            gceye0 = cv2.cvtColor(ceye0, cv2.COLOR_BGR2GRAY)
            gceye0 = cv2.fastNlMeansDenoising(gceye0,None,10,7)
            cv2.bitwise_not(gceye0, gceye0)
            gceye0 = cv2.medianBlur(gceye0, 3)
            gceye0 = cv2.equalizeHist(gceye0)
            #ret,gceye0 = cv2.threshold(gceye0, 175, 255, cv2.THRESH_BINARY)

            gceye1 = cv2.cvtColor(ceye1, cv2.COLOR_BGR2GRAY)
            gceye1 = cv2.fastNlMeansDenoising(gceye1,None,10,7)
            cv2.bitwise_not(gceye1, gceye1)
            gceye1 = cv2.medianBlur(gceye1, 3)
            gceye1 = cv2.equalizeHist(gceye1)

            #cv2.imshow('threshold_eye0',gceye0)

            #circles0 = cv2.HoughCircles(eye0,cv2.HOUGH_GRADIENT,1,10,param1=50,param2=30,minRadius=5,maxRadius=20)
            #circles0 = cv2.HoughCircles(eye0,cv2.HOUGH_GRADIENT,1,50,param1=50,param2=20,minRadius=7,maxRadius=25)
            #print "E0: Width:", ew0, "Height:", eh0
            #print "E1: Width:", ew1, "Height:", eh1
            circles0 = cv2.HoughCircles(gceye0,cv2.HOUGH_GRADIENT,1,50,param1=50,param2=20,minRadius=7,maxRadius=25)
            eye0x = 0
            eye0y = 0
            eye1x = 0
            eye1y = 0
            if circles0 is not None:
                for i in circles0[0,:]:
                    #print "eye0: Center:", (x+ex0+i[0], y+ey0+i[1]), "Radius:", i[2]
                    eye0x = x+ex0+i[0]
                    eye0y = y+ey0+i[1]

                    cv2.circle(ceye0,(i[0],i[1]),i[2],(0,255,0),1) # draw the outer circle
                    cv2.circle(eye0,(i[0],i[1]),i[2],(0,255,0),1) # draw the outer circle
                    cv2.circle(ceye0,(i[0],i[1]),2,(0,0,255),1) # draw the center of the circle
                    cv2.circle(eye0,(i[0],i[1]),2,(0,0,255),1) # draw the center of the circle
                cv2.imwrite('eye0_hough.jpg',ceye0)
                #print "showing eye0"
                cv2.imshow('eye0',eye0)

            
            #circles1 = cv2.HoughCircles(eye1,cv2.HOUGH_GRADIENT,1,10,param1=50,param2=30,minRadius=5,maxRadius=20)
            circles1 = cv2.HoughCircles(gceye1,cv2.HOUGH_GRADIENT,1,50,param1=50,param2=20,minRadius=7,maxRadius=25)
            if circles1 is not None:
                for i in circles1[0,:]:
                    #print "eye1: Center:", (x+ex1+i[0], y+ey1+i[1]), "Radius:", i[2]
                    eye1x = x+ex1+i[0]
                    eye1y = y+ey1+i[1]
                    
                    cv2.circle(ceye1,(i[0],i[1]),i[2],(0,255,0),1) # draw the outer circle
                    cv2.circle(eye1,(i[0],i[1]),i[2],(0,255,0),1) # draw the outer circle
                    cv2.circle(ceye1,(i[0],i[1]),2,(0,0,255),1) # draw the center of the circle
                    cv2.circle(eye1,(i[0],i[1]),2,(0,0,255),1) # draw the center of the circle
                
                if circles0 is not None:
                    eyePairCount += 1
                    eyeXYFrames.append([eye0x, eye0y])
                    eyeXYFrames.append([eye1x, eye1y])

                
                cv2.imwrite('eye1_hough.jpg',ceye1)
                #print "showing eye1"
                cv2.imshow('eye1',eye1)
            
            #print ""

            #pupil_params.minArea = eyeBoxArea0/5
            #pupil_params.maxArea = eyeBoxArea0/3
            #pupil_params.minArea = 100
            #pupil_params.maxArea = 1000
            
            #glint_detector = cv2.SimpleBlobDetector_create()
            #eye0 = cv2.resize(eye0,None,fx=2, fy=2, interpolation = cv2.INTER_CUBIC)
            #eye1 = cv2.resize(eye1,None,fx=2, fy=2, interpolation = cv2.INTER_CUBIC)
            #keypoints0 = pupil_detector.detect(eye0)
            #keypoints1 = pupil_detector.detect(eye1)
            #print keypoints0
           # cv2.drawKeypoints(eye0, keypoints0, np.array([]), (0,255,255), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
           # cv2.drawKeypoints(eye1, keypoints1, np.array([]), (0,255,255), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)

            #eye0 = cv2.drawKeypoints(eye0, keypoints0, np.array([]), (0,255,255), 4)
            #eye1 =cv2.drawKeypoints(eye1, keypoints1, np.array([]), (0,255,255), 4)

            #cv2.imshow('eye0',ceye0)
            cv2.imshow('eye1',eye1)

            """
            for (ex,ey,ew,eh) in eyes:
                print "\tFound eye", [ex, ey, ew, eh]
                #Green rectangle for eyes
                cv2.rectangle(roi_color,(ex,ey),(ex+ew,ey+eh),(0,255,0),2)
            """
        
        """
        cv2.rectangle(img2,(x2,y2),(x2+w2,y2+h2),(255,0,0),1)
        roi_gray2 = gray2[y2:y2+h2, x2:x2+w2]
        roi_color2 = img2[y2:y2+h2, x2:x2+w2]

        zoomed_face2 = cv2.resize(roi_gray2,None,fx=2, fy=2, interpolation = cv2.INTER_CUBIC)
        cv2.imshow('face2', zoomed_face2)

        eyes2 = eye_cascade.detectMultiScale(roi_gray2)
        for (ex2,ey2,ew2,eh2) in eyes2:
            cv2.rectangle(roi_color2,(ex2,ey2),(ex2+ew2,ey2+eh2),(0,255,0),2)
        """


    #cv2.imshow('img',img)
    cv2.imshow('img',img)
    #cv2.imwrite("./false/waterbottle" + str(imageCount) + ".jpg", imgCap)
    #cv2.imshow('img2',img2)

    k = cv2.waitKey(30) & 0xFF
    if k == 27: #ESC key pressed
        break
    elif k == ord('s'):
        save_path = 'screencap'
        base_save_path = 'screencap'
        picNum = 0
        
        while os.path.exists(save_path + "color.jpg"):
            picNum += 1
            save_path = base_save_path + str(picNum)
        print "saving as", (save_path + ".jpg")
        cv2.imwrite(save_path + "color.jpg", img)
        cv2.imwrite(save_path + "gray.jpg", gray)
        cv2.imwrite(save_path + "eye0.jpg", eye0)
        cv2.imwrite(save_path + "eye1.jpg", eye1)
        #cv2.destroyAllWindows()
    elif k == ord('q'):
        break
    """
    iter += 1
    if iter > 1:
        break
    """
    #time.sleep(0.5)
    imageCount += 1

    if eyePairCount > 10:
        for itr in range(0, len(eyeXYFrames)-1):
            eyeA = eyeXYFrames[itr]
            eyeB = eyeXYFrames[itr+1]


            #EyeA is the left eye
            if eyeA[0] < eyeB[0]:
                leftEyeFrames.append(eyeA[0])
            else:
                leftEyeFrames.append(eyeB[0])

            itr += 1

        avgX = sum(leftEyeFrames)/len(leftEyeFrames)
        xhat = -35.25*avgX + 8931.11
        if (xhat <= 0):
            xhat = 1
        if (xhat >= 1280):
            xhat = 1279

        print "Predicted screen-x =", xhat
        pyautogui.moveTo(xhat, 600)

        leftEyeFrames = []
        eyeXYFrames = []
        #del leftEyeFrames[:]
        #del eyeXYFrames[:]
        eyePairCount = 0

    #    break

cap.release()
#cap2.release()
cv2.destroyAllWindows()