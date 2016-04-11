#!/usr/bin/env python

"""
setup.py file for SWIG readlabel
"""

from distutils.core import setup, Extension


SLICSuperpixels_module = Extension('_SLICSuperpixels',
                           sources=['SLICSuperpixels_wrap.cxx', 'SLICSuperpixels.cpp', 'SLIC.cpp', 'PictureHandler.cpp'],
                           )

setup (name = 'SLICSuperpixels',
       version = '0.1',
       author      = "SWIG Docs",
       description = """Simple swig readlabel from docs""",
       ext_modules = [SLICSuperpixels_module],
       py_modules = ["SLICSuperpixels"],
       )