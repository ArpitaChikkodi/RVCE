import time
def caltime(func):
    st = time.time()
    print("Start time is ",st)
    func()
    et = time.time()
    print("End time is ",et)
    mins,sec = divmod(et-st,60)
    print("Time taken \n Minutes => ",mins,"\nSeconds => ",sec)
    return func

class Fibs:
    def __init__(self):
        self.a = 0
        self.b = 1
    def __next__(self):
        self.a,self.b = self.b,self.a+self.b
        return self.a
    def __iter__(self):
        return self
       

@caltime
def execute():
    fib = Fibs()
    n = int(input("Enter number : "))
    for f in range(n-1):
        next(fib)
    print(next(fib)) 


