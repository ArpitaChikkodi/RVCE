def Comp_Emp(et=False):
    if et==True:
        keys = ['empid','ename','empaddress']
    else:
        keys = ['compid','cname','caddress']

    class Credential:
        exp_keys = set(keys)

        def __init__(self,**kwargs):
            if self.exp_keys != set(kwargs.keys()):
                raise KeyError('Keys do not match!')
            else:
                for k,v in kwargs.items():
                    setattr(self,k,v)

                print(kwargs.items())

    return Credential

emp = Comp_Emp(True)
e1 = emp(empid='e01',ename='abc',empaddress = 'hubli')
#help(e1)
print(type(emp))
print(type(e1))
