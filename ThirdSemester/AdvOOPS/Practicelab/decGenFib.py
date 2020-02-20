import time
def caltime(func):
    st = time.time()
    func()
    et = time.time()
    d = et - st
    print("\nStart and end time is : ",st,"\t",et)
    print("Time taken is ",d)
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
    fibs = Fibs()
    n = int(input("Enter n value : "))
    for f in range(n-1):
        next(fibs)
    print(next(fibs))

