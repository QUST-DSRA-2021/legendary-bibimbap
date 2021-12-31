#!/usr/bin/env Python
# -*- coding: utf-8 -*-

import argparse

import numpy as np

class RGB_Color(object):
    flipdict = {
        "r": [ 0 , 2 , 1 ],
        "g": [ 2 , 1 , 0 ],
        "b": [ 1 , 0 , 2 ],
        }

    def __init__(self, colorarr):
        assert hasattr(colorarr, "__iter__")
        if isinstance(colorarr, str):
            assert colorarr[0] == "#"
            if len(colorarr) > 6:
                self.r = eval("0x" + colorarr[ 1 : 3 ])
                self.g = eval("0x" + colorarr[ 3 : 5 ])
                self.b = eval("0x" + colorarr[ 5 : 7 ])
            else:
                self.r = eval("0x" + colorarr[1]) * 17
                self.g = eval("0x" + colorarr[2]) * 17
                self.b = eval("0x" + colorarr[3]) * 17
        else:
            self.r = max(0, min(255, round(colorarr[0])))
            self.g = max(0, min(255, round(colorarr[1])))
            self.b = max(0, min(255, round(colorarr[2])))
    
    @property
    def nparray(self):
        return np.array([ self.r, self.g, self.b ])

    def __str__(self):
        return "RGB Color %s" % self.nparray

    @property
    def lightenessx2(self):
        return min(self.r, self.g, self.b) + max(self.r, self.g, self.b)

    def __repr__(self):
        return """<%s
    lighteness: %s
    at address: %s
    >""" % (self.__str__(), self.lightenessx2 / 2, hex(id(self)))

    def lighten(self, ratio):
        return RGB_Color(self.nparray * ratio)

    def lightenascolor(self, target):
        if not isinstance(target, RGB_Color):
            target = RGB_Color(target)
        return self.lighten(target.lightenessx2 / self.lightenessx2)

    def flip(self, axis):
        assert len(axis) == 1
        return RGB_Color(self.nparray[RGB_Color.flipdict[axis.lower()]])

    def spin(self, rev=False):
        return RGB_Color(self.nparray[[2,0,1] if rev else [1,2,0]])