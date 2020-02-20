def Comp_Emp(flag = False):
    if flag==True:
       keys = ['ename','empid','address','age']
    else:
        keys = ['cname','compid','address']

    class Credential:
        exp_keys = set(keys)

        def __init__(self,**kwargs):
            if self.exp_keys != set(kwargs.keys()):
                raise KeyError("Keys do not match!")
            else:
                for k,v in kwargs.items():
                    setattr(self,k,v)

    return Credential


emp = Comp_Emp(True)
e1 = emp(ename = 'abc',empid = '123',address = 'hubli',age=22)
print("Emp is of type ",type(emp))
print("e1 is of type ",type(e1))
print("\nEmployee Details\n")
print("Name : ",e1.ename,"\nID : ",e1.empid,"\nAddress : ",e1.address,"\nAge : ",e1.age)

cmp = Comp_Emp(False)
c1 = cmp(cname = 'cerner',compid = 'c01',address = 'hubli')
print("Cmp is of type ",type(cmp))
print("c1 is of type ",type(c1))
print("\nCompany Details\n")
print("Name : ",c1.cname,"\nID : ",c1.compid,"\nAddress : ",c1.address)

