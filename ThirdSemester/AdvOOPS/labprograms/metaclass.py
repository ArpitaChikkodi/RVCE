class Example(type):
    def fun():
        return "lets have fun"

    def __new__(cls,name,bases,attr):
        print("New method of class ",name)
        print("Current executing object : ",cls)
        print("Bases : ",bases)
        attr['fun']=Example.fun()
        print("Attributes are : ",attr)
        return super(Example,cls).__new__(cls,name,bases,attr)

    def __init__(cls,name,bases,attr):
        print("Init method of class ",name)
        print("Current executing object : ",cls)
        print("Bases : ",bases)
        print("Attributes ",attr)
        return super(Example,cls).__init__(name,bases,attr)

class MyClass(object,metaclass = Example):
    at = 20
    def foo(self,param):
        print("Parameter entered is ",param)

m = MyClass()
m.foo("hello")
