'''class sampleclass: 
    count = 0     # class attribute 
  
    def increase(self): 
        sampleclass.count += 1
  
# Calling increase() on an object 
s1 = sampleclass() 
s1.increase()         
print(s1.count) 
  
# Calling increase() on one more object 
s2 = sampleclass() 
s2.increase() 
print(s2.count)
  
print(sampleclass.count)
print(s1.count)
'''

# Python program to demonstrate instance attributes. 
class emp: 
    def __init__(self): 
        self.name = 'xyz'
        self.salary = 4000
  
    def show(self): 
        print(self.name) 
        print(self.salary) 
  
e1 = emp() 
print("Dictionary form :", vars(e1))
#print(dir(e1)) 
