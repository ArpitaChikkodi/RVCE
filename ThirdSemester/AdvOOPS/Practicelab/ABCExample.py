import abc
class Calculation(abc.ABC):
    def __init__(self,a,b):
        self.a = a
        self.b = b
    
    @abc.abstractmethod
    def calculate(self):
        pass

class Addition(Calculation):
    def calculate(self):
        sum = []
        for i in range(0,len(self.a)):
            sum.append(self.a[i]+self.b[i])

        print("Sum of ",self.a," and ",self.b," is ",sum)

class Subtraction(Calculation):
    def calculate(self):
        sum = []
        for i in range(0,len(self.a)):
            sum.append(self.a[i]-self.b[i])

        print("Difference of ",self.a," and ",self.b," is ",sum)

class Multiplication(Calculation):
    def calculate(self):
        sum = []
        for i in range(0,len(self.a)):
            sum.append(self.a[i]*self.b[i])

        print("Product of ",self.a," and ",self.b," is ",sum)

class Division(Calculation):
    def calculate(self):
        sum = []
        for i in range(0,len(self.a)):
            sum.append(self.a[i]/self.b[i])

        print("Quotient of ",self.a," and ",self.b," is ",sum)

l = int(input("Enter length of lists : "))
p = []
q = []
print("Enter list1 elements: ")
for i in range(0,l):
    p.append(int(input()))
print("Enter list2 elements: ")
for i in range(0,l):
    q.append(int(input()))

while True:
    print("\n1.Add 2.Sub 3.Mul 4.Div 5.Exit\n")
    ch  = int(input("Enter choice : "))
    if ch==1:
        Addition(p,q).calculate()
    elif ch==2:
        Subtraction(p,q).calculate()
    elif ch==3:
        Multiplication(p,q).calculate()
    elif ch==4:
        Division(p,q).calculate()
    elif ch==5:
        exit()
    else:
        print("Invalid choice!")
    
