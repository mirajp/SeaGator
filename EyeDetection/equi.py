import cv2
import numpy as np

img = cv2.imread('eye0.jpg',0)
equ = cv2.equalizeHist(img)
res = np.hstack((img,equ)) #stacking images side-by-si
cv2.imwrite('eye0res.png',res)
