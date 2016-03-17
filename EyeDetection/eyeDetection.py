import numpy as np
import cv2
import os.path
import cv2gpu
# multiple cascades: https://github.com/Itseez/opencv/tree/master/data/haarcascades

#https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_frontalface_default.xml
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
#cv2gpu.init_cpu_detector('haarcascade_eye_tree_eyeglasses.xml')
#https://github.com/Itseez/opencv/blob/master/data/haarcascades/haarcascade_eye.xml
#eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')
eye_cascade = cv2.CascadeClassifier('haarcascade_eye_tree_eyeglasses.xml')

cap = cv2.VideoCapture(0)
cap2  = cv2.VideoCapture(1)

while 1:
    ret, img = cap.read()
    ret2,img2 = cap2.read()

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    gray2 = cv2.cvtColor(img2,cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)
    #faces = cv2gpu.find_faces('gray.png')
    #faces2 = cv2gpu.find_faces('gray2.png')
    faces2 = face_cascade.detectMultiScale(gray2,1.3, 5)
    print faces

    for (x,y,w,h),(x2,y2,w2,h2) in zip(faces,faces2):
        cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),1)
        
        face_cropped = img[y:y+h, x:x+w]
        face_cropped = cv2.resize(face_cropped,None,fx=2, fy=2, interpolation = cv2.INTER_CUBIC)
        cv2.imshow('face', face_cropped)

        roi_gray = gray[y:y+h, x:x+w]
        roi_color = img[y:y+h, x:x+w]
        
        eyes = eye_cascade.detectMultiScale(roi_gray)
        for (ex,ey,ew,eh) in eyes:
            cv2.rectangle(roi_color,(ex,ey),(ex+ew,ey+eh),(0,255,0),2)

        cv2.rectangle(img2,(x2,y2),(x2+w2,y2+h2),(255,0,0),1)
        
        face_cropped2 = img[y2:y2+h2, x2:x2+w2]
        face_cropped2 = cv2.resize(face_cropped2,None,fx=2, fy=2, interpolation = cv2.INTER_CUBIC)
        cv2.imshow('face2', face_cropped2)

        roi_gray2 = gray[y2:y2+h2, x2:x2+w2]
        roi_color2 = img[y2:y2+h2, x2:x2+w2]
        
        eyes2 = eye_cascade.detectMultiScale(roi_gray2)
        for (ex2,ey2,ew2,eh2) in eyes2:
            cv2.rectangle(roi_color2,(ex2,ey2),(ex2+ew2,ey2+eh2),(0,255,0),2)

    #cv2.imshow('img',img)
    cv2.imshow('img',gray)
    cv2.imshow('img2',gray2)

    k = cv2.waitKey(30) & 0xFF
    if k == 27: #ESC key pressed
        break
    elif k == ord('s'):
        save_path = 'screencap'
        base_save_path = 'screencap'
        picNum = 0
        
        while os.path.exists(save_path + ".jpg"):
            picNum += 1
            save_path = base_save_path + str(picNum)
        print "saving as", (save_path + ".jpg")
        cv2.imwrite(save_path + ".jpg", img)
        #cv2.destroyAllWindows()
    elif k == ord('q'):
        break
    #break
        

cap.release()
cv2.destroyAllWindows()
