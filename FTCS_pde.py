# -*- coding: utf-8 -*-
"""
Created on Wed Nov 09 17:26:01 2016

@author: B2.2 (2016)
"""

# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""




def FTCS(dx,dt,x_max,t_max,D):
    
    import numpy as np
    
    a=D*(dt/(dx**2))
    
    x_points=np.arange(0,x_max+dx,dx)
    t_points=np.arange(0,t_max+dt,dt)
    x=len(x_points)
    t=len(t_points)
    U=np.zeros([t,x])
    
     #assigns initial condition
    
    for i in range(x):
        
        
        #form changed because input is scaled 
        U[0,i] = (4.0*i*((x_max/dx)-i))/(10*(x_max/dx))
        
     #assigns boundary condition
        
    for j in range(t):
        U[j,0],U[j,x-1]=0,0
        
        
    #main part
        
    #for j=0
    
    for i in range(1,x-1):
        U[1,i]=(1-2*a)*U[0,i]+a*(U[0,i+1]+U[0,i-1])
    
    #for j!=0
    
    for i in range (1, x-1):
        for j in range (1,  t-1):
            U[j+1, i]=(1-2*a)*U[j, i]+a*(U[j, i+1] + U[j, i-1])
    
    return U