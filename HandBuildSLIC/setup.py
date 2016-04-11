#!/usr/bin/env python

"""
setup.py file for SWIG SuperpixelSLIC
"""

from distutils.core import setup, Extension


SuperpixelSLIC_module = Extension('_SuperpixelSLIC',
                           sources=['SuperpixelSLIC_wrap.cxx', 'SuperpixelSLIC.cpp', "SLIC.cpp", "PictureHandler.cpp"],
                           )

setup (name = 'SuperpixelSLIC',
       version = '0.1',
       author      = "zhuangxiyang",
       description = """SLIC Superpixel Image Segmentation""",
       ext_modules = [SuperpixelSLIC_module],
       py_modules = ["SuperpixelSLIC"],
       )