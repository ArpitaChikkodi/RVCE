class Example(type):
    def __new__(cls,name,bases,dct):
        print("New method of class ",name)
        print("Bases are \n",bases)
        print("Attributes are \n",dct)
        return super(Example,cls).__new__(cls,name,bases,dct)

    def __init__(cls,name,bases,dct):
        print("Init method of class ",name)
        print("Bases are \n",bases)
        print("Attributes are \n",dct)
        return super(Example,cls).__init__(name,bases,dct)

class Myclass(metaclass = Example):
    barattr = 2
    def foo(self,param):
        print("Parameter value is ",param)

m = Myclass()
m.foo("hello")

    
