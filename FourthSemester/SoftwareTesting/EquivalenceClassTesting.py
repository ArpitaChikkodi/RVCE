from tkinter import *
root = Tk()
root.title("Input Box")
root.geometry("300x200")
var1 = IntVar()
var2 = StringVar()
var2.set("")
def clicked():
    try:
        i = var1.get()
        if(type(i) == int):
            if(i<1 or i>100):
                var2.set("Invalid number!")
            else:
                var2.set("Valid number!")
    except Exception:
        var2.set("Enter number only!")


label = Label(root,text="Enter a number : ").grid(row=1,column=1)
inp = Entry(root,textvariable= var1).grid(row=1,column=2)
btn = Button(root,text="Done",command= clicked).grid(row=2,column=2)
out = Label(root,textvariable=var2).grid(row=4,column=2)
root.mainloop()


'''
try:
    i = int(input("Enter a number : "))
    if(type(i) == int):
        if(i<1 or i>100):
            print("Invalid number!")
        else:
            print("Valid number!")
except ValueError:
    print("Enter number only!")

'''
