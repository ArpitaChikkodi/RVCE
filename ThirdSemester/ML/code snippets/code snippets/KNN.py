# -*- coding: utf-8 -*-
"""
Created on Sun Oct 20 18:18:33 2019

@author: rossy
"""

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.neighbors import KNeighborsClassifier
data = pd.read_csv("apndcts2.csv")


#seggregate the predictor variables
predictors = data.iloc[:,0:7]


#segregate the target / clss variable
target = data.iloc[:,7]


predictors_train, predictors_test, target_train, target_test = train_test_split(predictors, target, test_size =0.3, random_state =123)

#instantiate the model with 3 neibhbors
nn= KNeighborsClassifier(n_neighbors = 3)

#first tain the model / classifier with the inut data set, training part of it
model = nn.fit(predictors_train, target_train)

#to check the prediction accuracy
nn.score(predictors_test, target_test)