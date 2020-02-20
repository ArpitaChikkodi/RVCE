# -*- coding: utf-8 -*-
"""
Created on Wed Nov  6 20:53:52 2019

@author: rossy
"""


import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeClassifier

data = pd.read_csv("apndcts2.csv")


#seggregate the predictor variables
predictors = data.iloc[:,0:7]


#segregate the target / clss variable
target = data.iloc[:,7]


predictors_train, predictors_test, target_train, target_test = train_test_split(predictors, target, test_size =0.3, random_state =123)

dtree_entropy = DecisionTreeClassifier(criterion = "entropy", random_state=100, max_depth=3, min_samples_leaf=5)


#Train the model / classifier with the inuput dataseet (training data part of it)
model = dtree_entropy.fit(predictors_train, target_train)
print(model)

#make predictions using the trained model
prediction = dtree_entropy.predict(predictors_test)

#predicton accuracy
accuracy_score(target_test , prediction, normalize=True)