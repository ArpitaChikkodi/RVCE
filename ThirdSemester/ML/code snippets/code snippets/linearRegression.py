# -*- coding: utf-8 -*-
"""
Created on Wed Nov  6 21:19:34 2019

@author: rossy
"""

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score
from sklearn import linear_model

data = pd.read_csv("auto-mpg1.csv")

#remove all rows where value of any column is 'NaN'
data_clean = data.dropna(axis=0, how='any')


#seggregate the predictor variables
predictors = data_clean.iloc[:,1:7]


#segregate the target / clss variable
target = data_clean.iloc[:,0]

predictors_train, predictors_test, target_train, target_test = train_test_split(predictors, target, test_size =0.3, random_state =123)

lm= linear_model.LinearRegression()

#first train model / classifier with the input dataset (training data part of it)

model = lm.fit(predictors_train, target_train)

#make prediction using the trained model

prediction = model.predict(predictors_test)

mean_squared_error(target_test, prediction)

r2_score(target_test, prediction)