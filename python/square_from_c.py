# coding: utf-8

import ctypes

# Load c shared library
myAppC = ctypes.CDLL("./obj/myapp.so")

# Call c function from shared library
print("Square(4)="+ str(myAppC.square(4)))