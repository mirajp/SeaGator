import numpy as np
import cv2
import os.path
import cv2gpu

padding = 50
#Localized face detection, store upper left x,y with w,h
local_face = {'x':0, 'y':0, 'w':0, 'h':0}

def updateLocalFace(x,y,w,h):
    global padding
    localx = x-padding
    localy = y-padding
    if localx < 0:
        localx = 0
    if localy < 0:
        localy = 0

    local_face['x'] = localx
    local_face['y'] = localy
    local_face['w'] = w+padding*2
    local_face['h'] = h+padding*2
    return


# multiple cascades: https://github.com/Itseez/opencv/tree/master/data/haarcascades
#https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_frontalface_default.xml
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
#cv2gpu.init_cpu_detector('haarcascade_eye_tree_eyeglasses.xml')
#https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_eye.xml
#eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')
#eye_cascade = cv2.CascadeClassifier('haarcascade_eye_tree_eyeglasses.xml')
eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')

cap = cv2.VideoCapture(0)
#cap2  = cv2.VideoCapture(1)

while 1:
    ret, imgCap = cap.read()
    #If face was found, crop image immediately
    if local_face['w']:
        img = imgCap[local_face['y']:local_face['y']+local_face['h'], local_face['x']:local_face['x']+local_face['w']]
    else:
        img = imgCap

    #Denoising both the color and then the grayscale image looks nice, but time expensive
    #img = cv2.fastNlMeansDenoisingColored(img,None,10,10,7,21)
    #ret2,img2 = cap2.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    gray = cv2.fastNlMeansDenoising(gray,None,10,7)
    #gray2 = cv2.cvtColor(img2,cv2.COLOR_BGR2GRAY)
    
    #faces = face_cascade.detectMultiScale(img, 1.3, 5)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)
    #faces = cv2gpu.find_faces('gray.png')
    #faces2 = cv2gpu.find_faces('gray2.png')
    #faces2 = face_cascade.detectMultiScale(img2,1.3, 5)
    print "Cam1", faces
    #print "Cam2", faces2
    
    if len(faces) == 0:
        #Miss, lost face
        local_face['w'] = 0
    #for (x,y,w,h),(x2,y2,w2,h2) in zip(faces,faces2):
    for (x,y,w,h) in faces:
        print "\tFound face"
        updateLocalFace(x,y,w,h)
        
        print local_face
        
        #Blue rectangle for face
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),1)
        #Select region of interest by cropping image
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]
        
        zoomed_face = cv2.resize(roi_gray,None,fx=2, fy=2, interpolation = cv2.INTER_CUBIC)
        cv2.imshow('face', zoomed_face)

        eyes = eye_cascade.detectMultiScale(roi_gray)
        for (ex,ey,ew,eh) in eyes:
            print "\tFound eye", [ex, ey, ew, eh]
            #Green rectangle for eyes
            cv2.rectangle(roi_color,(ex,ey),(ex+ew,ey+eh),(0,255,0),2)

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
    #cv2.imshow('img2',gray2)

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
        #cv2.destroyAllWindows()
    elif k == ord('q'):
        break
    break
        

cap.release()
#cap2.release()
cv2.destroyAllWindows()