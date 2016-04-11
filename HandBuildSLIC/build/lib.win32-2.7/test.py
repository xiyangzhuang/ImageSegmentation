# coding: utf-8
import SuperpixelSLIC
print dir(SuperpixelSLIC)

SuperpixelSLIC.doSuperpixelSegmentation(r"beauty.bmp", r"C:\\Users\\Admin\\Desktop\\", 200, 20)
SuperpixelSLIC.readLabel(r"C:\Users\Admin\Desktop\beauty.dat", r"C:\Users\Admin\Desktop\beauty.csv", 667, 996)
# import numpy as np
# a = np.loadtxt("beauty.csv", delimiter=',')