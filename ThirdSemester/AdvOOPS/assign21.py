import os.path as op

''' Python program showing 
file management using  
context manager '''
  
class FileManager(): 
    def __init__(self, filename, mode): 
        self.filename = filename 
        self.mode = mode 
        self.file = None
          
    def __enter__(self): 
        self.file = open(self.filename, self.mode) 
        return self.file
      
    def __exit__(self, exc_type, exc_value, exc_traceback):
        self.file.close() 
  
# input filename  
fname = input("Enter filename : ")
while True:
    print("*"*7,"FILE OPERATIONS","*"*7)
    print("1.Create 2.Read file 3.Write to file 4.Append 5.Seek 6.Tell 7.Exit")
    ch = int(input("Enter choice : "))
    if ch==1:
        if(op.exists(fname)):
            print("File already exists!")
        else:
            with FileManager(fname, 'w') as f:
                print("File ",fname," is created successfully!")
                
    elif ch==2:
        if(op.exists(fname)):
            with FileManager(fname, 'r') as f:
                print(f.read())
               
        else:
            print("File not found!")
    elif ch==3:
        with FileManager(fname, 'w') as f:
            s = input("Enter data to write to file")
            f.write(s)
            print("\nWrite operation successful!")
    elif ch==4:
        with FileManager(fname, 'a') as f:
            s = input("Enter data to append to file")
            f.write(s)
            print("\nAppend operation successful!")
    elif ch==5:
        with FileManager(fname, 'r') as f:
            i = int(input("Enter position to seek : "))
            f.seek(i)
            print(f.read())
           
    elif ch==6:
        with FileManager(fname, 'r') as f:
            print("Current position of cursor is ",f.tell())
          
    elif ch==7:
        break
    else:
        print("Invalid choice!")


        
'''File management using context manager and with statement :

On executing the with block, the following operations happen in sequence:

A FileManager object is created with test.txt as the
filename and when w(write)/r(read)/a(append) is given as the mode then __init__ method is executed.
The __enter__ method opens the test.txt file in write
mode(setup operation) and returns the FileManager object to variable f.
Most of the file operations are performed.
The __exit__ method takes care of closing the file on exiting the
with block(teardown operation).
When print(f.closed) is run, the output is True as the FileManager
has already taken care of closing the file which otherwise needed
to be explicitly done.'''
