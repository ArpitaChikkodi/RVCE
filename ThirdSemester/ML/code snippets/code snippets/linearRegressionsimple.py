# -*- coding: utf-8 -*-
"""
Created on Thu Nov  7 20:47:02 2019

@author: rossy
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
plt.rcParams['figure.figsize'] = (12.0, 9.0)

# Preprocessing Input data and display of scatterplot
data = pd.read_csv("int_extmarks.csv")
X = data.iloc[:, 0]
Y = data.iloc[:, 1]
plt.scatter(X, Y)
plt.show()

#calculation of OLS - SSE
x_mean = np.mean(X)
print(x_mean)
print(y_mean)
y_mean = np.mean(Y)
cov_xy =  0
var_x = 0

for i in range(len(X)):
    cov_xy += (X[i] - x_mean)*(Y[i] - y_mean)
    var_x += (X[i] - x_mean)**2

print("sum of products SP")
print(cov_xy)
print ("sum of squares") 
print(var_x)

m = cov_xy / var_x

c = y_mean - m * x_mean
print (m,c)
    
#making predictions and plotting of graph
y_pred = m*X + c
plt.scatter(X, Y) # actual
# plt.scatter(X, Y_pred, color='red')
plt.plot([min(X), max(X)], [min(y_pred), max(y_pred)], color='red') # predicted
plt.show()
 
