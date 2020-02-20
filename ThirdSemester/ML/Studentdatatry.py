import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
import matplotlib.pyplot as plt
from sklearn.model_selection import StratifiedKFold
import numpy as np
from sklearn.metrics import accuracy_score
from sklearn.neighbors import KNeighborsClassifier
url  = "D:/MLProject/Data1ForAnalysis.xlsx"

class Classification:
    def init(self):
        self.data = pd.read_excel(url)
        
    def preprocessing(self):
        print(data)
        data[data['Result'].isnull()]
        #if even a single column of that row has nan value remove whole row(118-9=109)
        data = data.dropna(how='any').shape
        #segregate the predictor variables
        predictors = data.iloc[2:122,9:11]
        print(predictors)
        predictors.shape
        #segregate the target/ class variable
        target = data.iloc[2:122,11]
        print(target)
        target.shape
        ##test_size = 0.3 means 30% of original data to be considered as test data
        predictors_train,predictors_test,target_train,target_test = train_test_split(predictors,target,
                                                                             test_size=0.3,random_state=111)
        #70% is training data i.e 70% of 117 is 81
        print(predictors_train)
        predictors_train.size  #81*2
        len(predictors_train)
        #30% is testing data i.e 30% of 117 is 36
        print(predictors_test)
        predictors_test.size   #36*2
        len(predictors_test)
    
    def knnAlgo(self):
        #instantiate the model with 3 neighbors
        nn = KNeighborsClassifier(n_neighbors = 6)
        #first train the model / classifier with the input data set, training part of it
        model = nn.fit(predictors_train,target_train)
        print(model)
        #to check the prediction accuracy
        nn.score(predictors_test,target_test)


c1 = Classification()
c1.preprocessing()
c1.knnAlgo()








'''
#Naive_bayes
from sklearn.naive_bayes import GaussianNB

data = pd.read_excel("E:/3rd SEM/ML/ML PROJECT/Data1ForAnalysisWN.xlsx")
#print(data)
#seggregate the predictor variables
predictors = data.iloc[2:122,9:11]
#seggregate the target/class variable
target = data.iloc[2:122,11]

predictors_train,predictors_test,target_train,target_test=train_test_split(predictors,target,test_size=0.3,random_state=123)

gnb=GaussianNB()
#instantiate the model with 3 neighbours
model=gnb.fit(predictors_train,target_train)
print(model)
#first train the model/classifier with innput datasettraining set of it
gnb.score(predictors_test,target_test)



#Dtree
from sklearn.tree import DecisionTreeClassifier

data = pd.read_excel("E:/3rd SEM/ML/ML PROJECT/Data1ForAnalysisWN.xlsx")
#print(data)
#seggregate the predictor variables
predictors = data.iloc[2:122,9:11]
#seggregate the target/class variable
target = data.iloc[2:122,11]

predictors_train,predictors_test,target_train,target_test=train_test_split(predictors,target,test_size=0.3,random_state=123)

dtree_entropy=DecisionTreeClassifier(criterion="entropy",random_state=100,max_depth=3,min_samples_leaf=5)

model=dtree_entropy.fit(predictors_train,target_train)

print(model)

prediction=dtree_entropy.predict(predictors_test)

accuracy_score(target_test,prediction,normalize=True)
'''
