import os.path as op
def decor():
    print("*"*50)
        
class FileManager: 
    def __init__(self, filename, mode): 
        self.filename = filename 
        self.mode = mode 
        self.file = None
          
    def __enter__(self): 
        self.file = open(self.filename, self.mode) 
        return self.file
      
    def __exit__(self, exc_type, exc_value, exc_traceback):
        self.file.close() 
  
  
fname = input("Enter filename : ")

def con_manager():
    if(op.exists(fname)):
        with FileManager(fname, 'r') as f:
            line = f.readline()
            while line:
                decor()
                print("{}".format(line.strip()))
                line = f.readline()
            decor()
           #f.close()
    else:
        print("File does not exist!")

con_manager()
