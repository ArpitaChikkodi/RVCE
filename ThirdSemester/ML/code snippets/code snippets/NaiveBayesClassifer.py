# -*- coding: utf-8 -*-
"""
Created on Wed Nov  6 22:02:21 2019

@author: rossy
"""

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.naive_bayes import GaussianNB

data = pd.read_csv("apndcts1.csv")


#seggregate the predictor variables
predictors = data.iloc[:,0:7]


#segregate the target / clss variable
target = data.iloc[:,7]


predictors_train, predictors_test, target_train, target_test = train_test_split(predictors, target, test_size =0.3, random_state =123)

#instantiate the model 
gnb = GaussianNB()

#first tain the model / classifier with the inut data set, training part of it
model = gnb.fit(predictors_train, target_train)

prediction = model.predict(predictors_test)
#to check the prediction accuracy
accuracy_score(target_test, prediction, normalize = True)