# -*- coding: utf-8 -*-
"""
Created on Fri Nov 11 14:10:07 2016

@author: B2.2 (2016)
"""
import matplotlib.pyplot as plt

from DuFortFrankel import DuFortFrankel
from Richardson import Richardson
from FTCS import FTCS

print "\nThis program makes contour plots for solutions to the Heat Equation in 1D."
print "\nThree different methods are employed for the solution:"
print "\n1.FTCS"
print "2.Richardson"
print "3.DuFort Frankel"
print "\nTo plot the function of your choice:"
print "Input plot(functionname(dx,dt,x_max,t_max,D)) into the console"
print "\nfunctionname can be FTCS,Richardson and DuFort_Frankel."


def plot(k):
    plt.figure()
    cp = plt.contourf(k)
    plt.colorbar(cp)
    plt.title('Contour Plot')
    plt.xlabel('x')
    plt.ylabel('t')
    plt.show()
    
    