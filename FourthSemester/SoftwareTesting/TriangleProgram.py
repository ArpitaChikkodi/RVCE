x = 1
while x==1:
    print("Triangle Program!")
    a = int(input("Enter value of a : "))
    b = int(input("Enter value of a : "))
    c = int(input("Enter value of a : "))
    if(a<=0 or b<=0 or c<=0):
        print("Invalid dimensions!")
    elif(a>=b+c or b>=a+c or c>=a+b):
        print("Triangle cannot be formed!")
    elif(a==b & b==c and c!=a):
        print("Impossible!")
    elif(a==b & b!=c & c==a):
        print("Impossible!")
    elif(a!=b & b==c & c==a):
        print("Impossible!")
    elif(a==b & b==c & c==a):
        print("Equilateral triangle!")
    elif(a!=b & b!=c & c!=a):
        print("Scalene triangle!")
    elif(a!=b & b!=c & c==a):
        print("Isosceles triangle!")
    elif(a!=b & b==c & c!=a):
        print("Isosceles triangle!")
    elif(a==b & b!=c & c!=a):
        print("Isosceles triangle!")
    x = int(input("Enter 1 to continue and 0 to exit"))
