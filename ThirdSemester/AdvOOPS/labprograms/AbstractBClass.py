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
        for i in range(len(self.a)):
            sum.append(self.a[i]+self.b[i])
        print("\nSum of the two lists is ",sum)

class Subtraction(Calculation):
    def calculate(self):
        sum = []
        for i in range(len(self.a)):
            sum.append(self.a[i]-self.b[i])
        print("\nDifference of the two lists is ",sum)

class Multiplication(Calculation):
    def calculate(self):
        sum = []
        for i in range(len(self.a)):
            sum.append(self.a[i]*self.b[i])
        print("\nProduct of the two lists is ",sum)

class Division(Calculation):
    def calculate(self):
        sum = []
        for i in range(len(self.a)):
            sum.append(self.a[i]/self.b[i])
        print("\nQuotient of the two lists is ",sum)

l = int(input("\nEnter length of lists : "))
p,q = [],[]
print("Enter list1 elements : ")
for i in range(l):
    p.append(int(input()))
print("Enter list2 elements : ")
for i in range(l):
    q.append(int(input()))

while True:
    print("**********Operations**********")
    print("1.Addition \t2.Subtraction \n3.Multiplication \t4.Division \n5.Exit")
    ch = int(input("Enter choice : "))
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
